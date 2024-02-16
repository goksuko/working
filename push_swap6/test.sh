#!/bin/bash

make && make bonus
ARG2=$(shuf -i 1-100 -n 1)
ARG3=$(shuf -i 5-20 -n 7)
ARG="9 10 15 19 5 18 6 -9 -10 -15 -19 -5 -18 -6"

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
echo "line number: "
./push_swap $ARG | wc -l
#./push_swap $angle | wc -l
echo "result: "
./push_swap $ARG | ./checker_linux $ARG
#./push_swap $angle | ./checker_linux $angle
echo "my check: "
./push_swap $ARG | ./checker $ARG
#./push_swap $angle | ./checker $angle
echo "numbers: "
#echo $angle
echo $ARG