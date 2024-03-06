#!/bin/bash

make && make bonus
ARG2=$(shuf -i 1-1000 -n 1)
ARG=$(shuf -i 5-2000 -n $ARG2)
#ARG=$(shuf -i 5-2000 -n 20)
ARG10="1457 1150 1729 178 1298 949 -1800 -1396 -1071 -989 -879 -773 -713 76 1627 781 1487 527 1676 405 1145 281 1902 1266 0 -1935 -1933  -1792 -1670 104 1801 988 -1606 -1575 -1524 -660 -339 -190 -177 -93 -75"
#ARG+=$ARG10
ARG4="9 10 15 19 5 18 6 -9 -10 -15 -19     -5 -18 -6"
ARG5="0 9 1 8 2"

#angle=$(seq -3000 30000 | shuf -n 100) 
#MIN=-10001
#MAX=100000
#NUM_NUMBERS=10
# Generate a sequence of numbers within the range
#sequence=$(seq $MIN $MAX)
# Shuffle the sequence
#shuffled_sequence=$(shuf -e $sequence)

#selected_numbers=()
#while [ ${#selected_numbers[@]} -lt $NUM_NUMBERS ]; do
#    # Shuffle the sequence
#    shuffled_sequence=$(shuf <<< "$sequence")
#    # Select the first NUM_NUMBERS elements from the shuffled sequence
#    selected_numbers=($(echo "$shuffled_sequence" | head -n $NUM_NUMBERS))
#done

# Output the selected non-repeating random numbers
#echo "${selected_numbers[@]}"
#angle=$(echo "$shuffled_sequence" | head -n $NUM_NUMBERS)
#angle=$(echo "$selected_numbers" | head -n $NUM_NUMBERS)
#./push_swap $angle
./push_swap $ARG
#./push_swap "-5 12 -85 -45 6 -97 4 -58 65 87 99 13"

echo " "
echo "instruction number: "
./push_swap $ARG | wc -l
echo " "
echo "*****org check: "
./push_swap $ARG | ./checker_linux $ARG
#echo "****org check2: "
#./push_swap $ARG | ./checker_linux $ARG | ./checker_linux ra
echo "******my check: "
./push_swap $ARG | ./checker $ARG
echo " "
echo "$ARG2 numbers: "
#echo $ARG