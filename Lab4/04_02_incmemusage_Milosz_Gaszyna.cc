#include <iostream>
#include <cstdlib>
#include <ctime>

const int SIZE = 1000; // rozmiar tablicy wskaźników

int main() {
    srand(time(0)); // inicjalizacja generatora liczb losowych

    // deklaracja tablicy wskaźników
    double*** tablica = new double**[SIZE];

    for(int i = 0; i < SIZE; i++) {
        // utworzenie tablicy 2-wymiarowej
        tablica[i] = new double*[SIZE];
        for(int j = 0; j < SIZE; j++) {
            tablica[i][j] = new double[SIZE];
            // wypełnienie tablicy liczbami losowymi
            for(int k = 0; k < SIZE; k++) {
                tablica[i][j][k] = (double)rand() / RAND_MAX;
            }
        }

        std::cout << "Utworzono tablicę 2-wymiarową nr " << i+1 << ". Naciśnij enter, aby kontynuowac\n";
        std::cin.get();
    }
    return 0;
}
