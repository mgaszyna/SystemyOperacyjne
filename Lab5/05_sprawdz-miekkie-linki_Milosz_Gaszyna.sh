#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Użycie: $0 <katalog>"
    exit 1
fi

directory=$1

# Sprawdzanie zapętlonego linkowania
find "$directory" -type l | while read link; do
    visited=("$link")
    target=$(readlink "$link")

    while [ -n "$target" ] && ! [[ " ${visited[@]} " =~ " $target " ]]; do
        visited+=("$target")
        target=$(readlink "$target")
    done

    if [ -n "$target" ]; then
        # Znaleziono zapętlenie
        echo "Zapętlenie w linkowaniu:"
        echo "${visited[@]} $target"
        echo "Długość zapętlenia: ${#visited[@]}"
        echo
    fi
done
