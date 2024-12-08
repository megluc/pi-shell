#include <fcntl.h>
#include <unistd.h>

void shell_cp(const char *source, const char *destination) {
    int src_fd = open(source, O_RDONLY);
    if (src_fd == -1) {
        esp_printf(putc, "cp: Failed to open source file %s\n", source);
        return;
    }

    int dest_fd = open(destination, O_WRONLY | O_CREAT | O_TRUNC, 0666);  // Create or overwrite the destination
    if (dest_fd == -1) {
        esp_printf(putc, "cp: Failed to open destination file %s\n", destination);
        close(src_fd);
        return;
    }

    char buffer[1024];
    ssize_t bytes_read;
    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
        write(dest_fd, buffer, bytes_read);
    }

    close(src_fd);
    close(dest_fd);
}
