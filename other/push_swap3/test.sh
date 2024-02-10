#!/bin/bash

make
ARG=$(shuf -i 1-100 -n 10)
./push_swap $ARG
echo "line number: "
./push_swap $ARG | wc -l
echo "result: "
./push_swap $ARG | ./checker_linux $ARG
