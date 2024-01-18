#!/bin/bash

if [ $# -eq 0 ]; then
    echo "Użycie: $0 <katalog>"
    exit 1
fi

katalog=$1

find "$katalog" -type f -exec stat -c "%A" {} + | \
    sort | uniq -c | awk '{if ($1 > 1) {count[$2]++; print $1, $2, $3, $4, $5, $6, $7, $8, $9, $10, $11, $12}}' | \
    sort

