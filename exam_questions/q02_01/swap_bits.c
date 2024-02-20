#include <unistd.h>
#include <stdio.h>

unsigned char	swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4));
}

// Suppose octet is represented in binary as abcdefgh, where a to h are individual bits.

// After octet >> 4, the bits are shifted to the right: 0000abcd.
// After octet << 4, the bits are shifted to the left: efgh0000.
// The bitwise OR operation combines these results: efghabcd.
// So, the original bits abcdefgh have been swapped to efghabcd, resulting in a new unsigned char.

// int main(void)
// {
// 	char letter_t;
// 	char letter_G;
// 	letter_t = 't';
// 	letter_G = 'G';

// 	printf("letter_t after swap: %c", swap_bits(letter_t));
// 	printf("\n");
// 	printf("letter_G after swap: %c", swap_bits(letter_G));
// 	printf("\n");
// 	return (0);
// }


// Assignment name  : swap_bits
// Expected files   : swap_bits.c
// Allowed functions:
// --------------------------------------------------------------------------------

// Write a function that takes a byte, swaps its halves (like the example) and
// returns the result.

// Your function must be declared as follows:

// unsigned char	swap_bits(unsigned char octet);

// Example:

//   1 byte
// _____________
//  0100 | 0001
//      \ /
//      / 
//  0001 | 0100
