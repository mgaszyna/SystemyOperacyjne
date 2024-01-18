#include <iostream>
#include <csignal>
#include <cstdlib>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: ./02_04_sendsignal_Milosz_Gaszyna <PID> <signal>\n";
        return 1;
    }

    pid_t pid = std::stoi(argv[1]);
    int sig = std::stoi(argv[2]);

    if (kill(pid, sig) == -1) {
        perror("Error sending signal");
        return 1;
    }

    std::cout << "Signal " << sig << " sent to process " << pid << ".\n";

    return 0;
}
