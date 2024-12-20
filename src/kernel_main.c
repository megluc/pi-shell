
// kernel_main.c

#include "fat.h"
#include "serial.h"
#include "rprintf.h"
#include "delays.h"

char glbl[1024]; // global char array, used for clearing bss


// returns the execution level the kernel is currently running at
unsigned int getEL(){
  unsigned int el;

  asm("mrs %0,CurrentEL"
      : "=r"(el)
      :
      :);
  el = (el >> 2) & 0x3; // Shift right by 2 bits and mask to get the EL value

  return el;
}

// main function
void kernel_main() {

  extern int __bss_start, __bss_end;
  char *bss_start, *bss_end;

  bss_start = &__bss_start; // pointer to beginning of bss segment
  bss_end = &__bss_end; // pointer to end of bss segment

  // iterate through bss segment and write `0` to each address
  for(int *i = bss_start; i <= bss_end; i++){
    *i = 0;
  }

  // serial driver
  putc(' ');
  esp_printf(putc, "Current Execution Level is %d\r\n", getEL()); // Uses putc to print a string

  // page frame allocator
  init_pfa_list();
  struct ppage *allocd_list = allocate_physical_pages(10);

  // FATFS intialization
  fatInit();

  // open file
  char file_name[] = "TEST";
  char *fn = &file_name;
  char file_extension[] = "TXT";
  char *fe = &file_extension;
  struct root_directory_entry *file;
  
  esp_printf(putc, "Opening file %s.%s ...\r\n", fn, fe);


  file = fatOpen(fn, fe);
  
  if (file) {
    esp_printf(putc, "File %s.%s opened successfully\r\n", file->file_name, file->file_extension);
  } else {
    esp_printf(putc, "Failed to open file %s.%s\n", fn, fe);
  }

  // read file
  char read_buffer[512];
  char *read_buf_ptr = &read_buffer[0];
  fatRead(read_buf_ptr, 512, file);
  esp_printf(putc, "%s\n", read_buf_ptr);

  shell();

  while(1){
    esp_printf(putc, "running...\n");
    wait_seconds(1);
  }
}
