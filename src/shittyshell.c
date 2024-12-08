#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char **argv) {
    char *line = NULL;
    char **argz;
    pid_t pid, wpid;
    size_t bufsize = 0;
    ssize_t line_size;

    while (1) {
        // 1. Print the prompt
        printf("$ ");  // Change this to any prompt you like

        // 2. Read a line from stdin
        line_size = getline(&line, &bufsize, stdin);
        if (line_size == -1) {
            // Error or EOF
            perror("getline");
            break;
        }

        // 3. Remove the newline character
        if (line[line_size - 1] == '\n') {
            line[line_size - 1] = '\0';
        }

        // 4. Fork a new process
        pid = fork();

        if (pid == -1) {
            // Fork failed
            perror("fork");
            free(line);
            continue;
        }

        if (pid == 0) {
            // 5. Child process: Prepare the argument vector for execv

            // Allocate memory for the argument vector (just one argument here)
            argz = malloc(2 * sizeof(char *));
            if (argz == NULL) {
                perror("malloc");
                free(line);
                exit(EXIT_FAILURE);
            }

            argz[0] = line;  // Command to execute
            argz[1] = NULL;   // Execv expects the last argument to be NULL

            // 6. Execute the command using execv
            if (execv(line, argz) == -1) {
                perror("execv");
                free(argz);
                exit(EXIT_FAILURE);
            }
        } else {
            // 7. Parent process: Wait for the child to finish
            do {
                wpid = waitpid(pid, NULL, WUNTRACED);
            } while (!WIFEXITED(wpid) && !WIFSIGNALED(wpid));

            // 8. Free the allocated memory
            free(argz);
        }
    }

    // Clean up
    free(line);
    return 0;
}
