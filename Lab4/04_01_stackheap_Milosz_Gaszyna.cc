#include <iostream>
#include <cstdlib> // dla funkcji rand()
#include <ctime> // dla funkcji time()

const int SIZE = 1000000; // 10^6

void statyczna() {
    double tablica[SIZE];
    for(int i = 0; i < SIZE; i++) {
        tablica[i] = (double)rand() / RAND_MAX;
    }
    std::cout << "Stworzono i wypelniono tablice statyczna. Nacisnij enter, aby kontynuowac\n";
    std::cin.get();
}

void dynamiczna() {
    double* tablica = new double[SIZE];
    for(int i = 0; i < SIZE; i++) {
        tablica[i] = (double)rand() / RAND_MAX;
    }
    std::cout << "Stworzono i wypelniono tablice dynamiczna. Nacisnij enter, aby kontynuowac\n";
    std::cin.get();
    delete[] tablica;
}

int main() {
    srand(time(0)); // inicjalizacja generatora liczb losowych
    statyczna();
    std::cout << "Nacisnij enter, aby wywołac funkcje dynamiczna...\n";
    std::cin.get();
    dynamiczna();
    return 0;
}
