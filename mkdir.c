#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void shell_mkdir(const char *path) {
    if (mkdir(path, 0777) == -1) {  // 0777 allows full permissions (read/write/execute)
        esp_printf(putc, "mkdir: failed to create directory %s\n", path);
    } else {
        esp_printf(putc, "Directory created: %s\n", path);
    }
}
