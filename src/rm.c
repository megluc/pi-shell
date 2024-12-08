#include <unistd.h>

void shell_rm(const char *filename) {
    if (unlink(filename) == -1) {
        esp_printf(putc, "rm: Failed to delete file %s\n", filename);
    } else {
        esp_printf(putc, "File deleted: %s\n", filename);
    }
}
