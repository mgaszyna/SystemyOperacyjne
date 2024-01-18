#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Użycie: $0 <katalog>"
    exit 1
fi

directory=$1

# Znalezienie plików o zadanej liczbie dowiązań
find "$directory" -type f -links +1 | while read file; do
    # Sprawdzenie liczby dowiązań dla każdego pliku
    link_count=$(stat -c "%h" "$file")

    if [ "$link_count" -gt 1 ]; then
        echo "Plik $file ma $link_count dowiązań."
    fi
done
