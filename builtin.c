#include "shell.h"
int main() {
    char input[MAX_INPUT];
    char *prompt = "#cisfun$ ";

    while (1) {
        printf("%s", prompt);
        if (fgets(input, MAX_INPUT, stdin) == NULL) {
            printf("\n");  // Handle Ctrl+D (end of file)
            break;
        }

        // Remove the newline character
        input[strcspn(input, "\n")] = '\0';

        // Fork a child process
        pid_t pid = fork();

        if (pid == -1) {
            perror("Fork failed");
            exit(1);
        } else if (pid == 0) {
            // Child process
            if (execlp(input, input, (char *)NULL) == -1) {
                printf("%s: No such file or directory\n", input);
                exit(2);
            }
        } else {
            // Parent process
            int status;
            waitpid(pid, &status, 0);

            if (WIFEXITED(status) && WEXITSTATUS(status) == 2) {
                // Command not found
                continue;
            }
        }
    }

    return 0;
}
