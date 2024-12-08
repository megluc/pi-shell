#include <stdio.h>

void shell_mv(const char *source, const char *destination) {
    if (rename(source, destination) == -1) {
        esp_printf(putc, "mv: Could not move %s to %s\n", source, destination);
    } else {
        esp_printf(putc, "Moved %s to %s\n", source, destination);
    }
}
