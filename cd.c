#include <unistd.h>

void shell_cd(const char *path) {
    if (chdir(path) == -1) {
        esp_printf(putc, "cd: No such file or directory: %s\n", path);
    }
}
