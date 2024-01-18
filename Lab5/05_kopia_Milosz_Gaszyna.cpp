#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        cerr << "Użycie: " << argv[0] << " <rozmiar bufora> <plik.src> <plik.trg>\n";
        return EXIT_FAILURE;
    }

    // Pobieranie rozmiaru bufora z argumentów wiersza poleceń
    int buffer_size = atoi(argv[1]);
    if (buffer_size <= 0 || buffer_size > numeric_limits<int>::max()) {
        cerr << "Nieprawidłowy rozmiar bufora\n";
        return EXIT_FAILURE;
    }

    // Otwarcie pliku źródłowego do odczytu
    ifstream src_file(argv[2], ios::binary);
    if (!src_file.is_open()) {
        perror("Błąd otwierania pliku źródłowego");
        return EXIT_FAILURE;
    }

    // Otwarcie pliku docelowego do zapisu
    ofstream trg_file(argv[3], ios::binary);
    if (!trg_file.is_open()) {
        perror("Błąd otwierania pliku docelowego");
        return EXIT_FAILURE;
    }

    // Pomiar czasu przed rozpoczęciem kopiowania
    auto start_time = high_resolution_clock::now();

    // Bufor do przechowywania danych
    char *buffer = new char[buffer_size];

    // Kopiowanie danych
    while (src_file.read(buffer, buffer_size)) {
        trg_file.write(buffer, src_file.gcount());
    }

    // Pomiar czasu po zakończeniu kopiowania
    auto end_time = high_resolution_clock::now();

    // Obliczanie czasu trwania operacji
    duration<double> elapsed_time = duration_cast<duration<double>>(end_time - start_time);

    // Wypisanie czasu kopiowania
    cout << "Czas kopiowania: " << elapsed_time.count() << " sekundy" << endl;

    // Zwolnienie bufora i zamknięcie plików
    delete[] buffer;
    src_file.close();
    trg_file.close();

    return EXIT_SUCCESS;
}
