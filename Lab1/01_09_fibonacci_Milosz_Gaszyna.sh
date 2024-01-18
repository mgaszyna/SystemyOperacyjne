#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Sposob uzycia: $0 <n>"
fi

n=$1
a=0
b=1

if [ $n -ge 1 ]; then
    echo -n "$a "
fi

if [ $n -ge 2 ]; then
    echo -n "$b "
fi

i=2

while [ "$i" -lt "$n" ]; do
    c=$((a+b))
    echo -n "$c "
    a=$b
    b=$c
    i=$((i+1))
done

echo
