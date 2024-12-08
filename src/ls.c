#include <dirent.h>
#include <stdio.h>

void shell_ls(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);
    
    if (dp == NULL) {
        esp_printf(putc, "ls: Cannot open directory: %s\n", path);
        return;
    }

    while ((entry = readdir(dp))) {
        esp_printf(putc, "%s\n", entry->d_name);
    }

    closedir(dp);
}

