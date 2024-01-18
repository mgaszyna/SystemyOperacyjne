#!/bin/bash

params=($*)
n=$#
for ((x=n-1;x>=0;x--))
do
echo ${params[x]}
done
