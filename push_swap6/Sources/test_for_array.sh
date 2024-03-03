#!/bin/bash


ARG2=$(shuf -i 1-100 -n 1)
ARG=$(shuf -i 5-2000 -n $ARG2)
ARG6=$(shuf -i 5-2000 -n 20)
ARG4="9 10 15 19 5 18 6 -9 -10 -15 -19     -5 -18 -6"
ARG5="0 9 1 8 2"

#cc -Wall -Werror -Wextra radix_array3.c
cc -Wall -Werror -Wextra -g -fsanitize=address radix_array3.c
echo "$ARG2 numbers: "
echo $ARG
./a.out
