/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/10/20 11:30:18 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/06/25 23:39:21 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

/*The  calloc()  function  allocates memory for an array of nmemb 
elements of size bytes each and returns a pointer to the allocated 
memory.  The memory is set to zero.  If nmemb or size is 0, then 
calloc() returns either NULL, or a unique pointer value that can 
later be successfully passed  to  free().   If the multiplication 
of nmemb and size would result in integer overflow, then calloc() 
returns an error. */

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr_str;
	size_t			i;

	i = 0;
	ptr_str = (unsigned char *)s;
	while (i < n)
	{
		ptr_str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size != 0 && nmemb > (SIZE_MAX / size))
		return (NULL);
	else
	{
		ptr = (void *)malloc(nmemb * size);
		if (ptr == NULL || errno == ENOMEM)
			return (NULL);
	}
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
/*
int	main(void)
{
	char	*p;

	p = "123456789123456789";
	printf("before: %s\n", p);
	p = ft_calloc(10, sizeof(char));
	printf(" after: %s\n", p);
	for (int n = 0; n < 12; n++)
		printf("%d\n", p[n]);
	free (p);
	return (0);
}
*/