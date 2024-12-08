#include <fcntl.h>
#include <unistd.h>

void shell_touch(const char *filename) {
    int fd = open(filename, O_CREAT | O_RDWR, 0666); // Create or open file with read/write permissions
    if (fd == -1) {
        esp_printf(putc, "touch: Could not create or open file %s\n", filename);
    } else {
        close(fd);  // Close the file after opening
    }
}
