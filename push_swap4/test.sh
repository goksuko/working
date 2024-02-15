#!/bin/bash

make && make bonus
ARG=$(shuf -i 5-200 -n 4)
./push_swap $ARG
#./push_swap "-5 12 -85 -45 6 -97 4 -58 65 87 99 13"
echo "line number: "
./push_swap $ARG | wc -l
echo "result: "
./push_swap $ARG | ./checker_linux $ARG
echo "my check: "
./push_swap $ARG | ./checker $ARG