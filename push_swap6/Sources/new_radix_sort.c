/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   new_radix_sort.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/03/02 22:30:35 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/03/02 23:58:11 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/push_swap.h"

void	send_descending(t_stack **src, t_stack **dest)
{

}

void	do_negatives(t_stack **a, t_stack **b)
{
	int	min;
	int	place;

	min = find_min(a);
	min *= -1;
	place = 1;
	while (min)
	{
		send_descending(a, b);
		place *= 10;
		min /= 10;
		if (min)
		{
			send_ascending(b, a);
			place *= 10;
			min /= 10;
		}
	}








// void reverseSort(int *arr2, int neg, int place)
// {
//     int i, freq[range] = {0};
//     int *output = (int *)malloc(neg * sizeof(int));

//     // Store count of occurrences in freq[]
//     for (i = 0; i < neg; i++) freq[-(arr2[i] / place) % range]++;

//     // Change freq[i] so that it contains the actual position of the digit in
//     // output[]
//     for (i = range - 1; i > 0; i--) freq[i - 1] += freq[i];

//     // Build the output array
//     for (i = neg - 1; i >= 0; i--)
//     {
//         output[freq[-(arr2[i] / place) % range] - 1] = arr2[i];
//         freq[-(arr2[i] / place) % range]--;
// 		// printf("freq[(arr[i] / place) %% range]: freq[%d]\n", ((arr[i] / place) % range));
//     }

//     // Copy the output array to arr[], so it contains numbers according to the
//     // current digit
//     for (i = 0; i < neg; i++) arr2[i] = output[i];
//     free(output);
// }


}

void	make_numbers_negative(t_stack **a)
{
	t_stack	*current;

	current = *a;
	while (current)
	{
		current->value *= -1;		
		current = current->next;
	}
}

int	find_neg_nums(t_stack **a)
{
	t_stack	*current;
	int		neg;

	current = *a;
	neg = 0;
	while (current)
	{
		if (current->value < 0)
			neg++;
		current = current->next;
	}
	return (neg);
}

int	find_pos_nums(t_stack **a)
{
	t_stack	*current;
	int		pos;

	current = *a;
	pos = 0;
	while (current)
	{
		if (current->value >= 0)
			pos++;
		current = current->next;
	}
	return (pos);
}

void	do_radix_sort(t_stack **a, int length)
{
	// int	min;
	// int	max;

	// min = find_min(a);
	// max = find_max(a);
	int			neg;
	int			pos;
	int			times;
	t_stack		*current_a;
	t_stack		*current_b;
	t_stack		*b;

	make_numbers_negative(a);

	neg = find_neg_nums(a);
	pos = find_pos_nums(a);
	times = length;
	while (times--)
	{
		current_a = *a;
		current_b = b;
		if (current_a->value < 0)
			do_negatives(a, &b);
		else
			ps_rotate(a, "a");
	}
	//take the bigger value up
	sort_eff_b(&b);

	

}


// void radixsort2(int *arr, int n,
// 				int min,  // min is the minimum element in the array
//                 int max)  // max is the maximum element in the array
// {
//     int *arr2;
//     int *arr3;
//     int neg = numNeg(arr, n);
// 	int pos = numPos(arr, n);
//     arr2 = takeNeg(arr, n, neg);
//     arr3 = takePos(arr, n, pos);
// 	sortNeg(arr2, neg, min);
// 	sortPos(arr3, pos, max);
//     arr = combine(arr, arr2, arr3, neg, pos);
// }