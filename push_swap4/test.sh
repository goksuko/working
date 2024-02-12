#!/bin/bash

make && make bonus
ARG=$(shuf -i 1-1000 -n 100)
./push_swap $ARG
echo "line number: "
./push_swap $ARG | wc -l
echo "result: "
./push_swap $ARG | ./checker_linux $ARG
echo "my check: "
./push_swap $ARG | ./checker $ARG