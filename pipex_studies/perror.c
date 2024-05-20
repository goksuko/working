/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   perror.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: akaya-oz <akaya-oz@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/05/20 21:59:22 by akaya-oz      #+#    #+#                 */
/*   Updated: 2024/05/20 22:05:00 by akaya-oz      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int	result;

	result = open("nonexistingfile", O_RDONLY, 0777);
	if (result < 0)
	{
		perror("openingfunction");
		// it will write the error message to the standard error output with the beginning of the start message we wrote
		// use perror only for fucntions that are not done by you
		return (1);
	}
	else
		return (0);
}

// goksu@vmi1580390:~/Codam/working/pipex_studies$ cc perror.c && ./a.out 
// openingfunction: No such file or directory
