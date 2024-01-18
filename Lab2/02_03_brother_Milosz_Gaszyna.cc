#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

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

        pid_t grandchild_pid = fork();

        if (grandchild_pid == -1) {
            perror("Fork failed");
            return 1;
        }

        if (grandchild_pid == 0) {
            printf("Grandchild PID: %d\n", getpid());
            printf("Parent PID: %d\n", getppid());
            getchar();
        } else {
            wait(NULL);
        }
    } else {
        pid_t child2_pid = fork();

        if (child2_pid == -1) {
            perror("Fork failed");
            return 1;
        }

        if (child2_pid == 0) {
            printf("Child2 (brother) PID: %d\n", getpid());
            printf("Parent PID: %d\n", getppid());
            getchar();
        } else {
            wait(NULL);
        }
        getchar();
    }

    return 0;
}
