#include <glob.h>
#include <stdio.h>
#include <stdlib.h>

void shell_ls(const char *pattern) {
    glob_t globbuf;
    int i;

    // Initialize glob to clear previous results
    globbuf.gl_offs = 0;

    // Perform the pattern matching (wildcard expansion)
    if (glob(pattern, 0, NULL, &globbuf) != 0) {
        printf("No matching files found for pattern: %s\n", pattern);
        return;
    }

    // Print the matching files
    for (i = 0; i < globbuf.gl_pathc; i++) {
        printf("%s\n", globbuf.gl_pathv[i]);
    }

    // Free the memory used by glob
    globfree(&globbuf);
}

int main() {
    // Example usage of shell_ls with a wildcard pattern
    shell_ls("*");  // List all files
    shell_ls("*.c");  // List all files ending with '.c'
    shell_ls("test*");  // List all files starting with 'test'

    return 0;
}
