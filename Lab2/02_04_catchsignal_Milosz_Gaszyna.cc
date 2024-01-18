#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void signal_handler(int signal) {
    printf("Otrzymano sygnał: %s\n", strsignal(signal));
}

int main() {
    for (int i = 1; i < NSIG; ++i) { //NSIG - liczba sygnalow zdefiniowanych w systemie
        signal(i, signal_handler);
    }

    while (true) {
        pause(); // zawieszamy proces do momentu otrzymania sygnalu
    }

    return 0;
}

// nie jestesmy w stanie przechwycic sygnalu SIGKILL(9) oraz SIGSTOP(19)
