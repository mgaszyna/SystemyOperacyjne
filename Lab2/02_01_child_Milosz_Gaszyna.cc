#include <stdio.h>
#include <unistd.h>

int main() {
    printf("PID: %d\n", getpid());
    getchar();

    pid_t child_pid = fork();

    if (child_pid == -1) {
        perror("Fork failed");
        return 1;
    }

    if (child_pid == 0) {
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
        getchar();
    } else {
        getchar();
    }

    return 0;
}
