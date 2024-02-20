#include <unistd.h>

int	main(void)
{
	int	i;
	int j;
	char c;

	i = 1;
	while (i <= 100)
	{
		if (i % 15 == 0)
			write(1, "fizzbuzz\n", 9);		
		else if (i % 3 == 0)
			write (1, "fizz\n", 5);
		else if (i % 5 == 0)
			write (1, "buzz\n", 5);
		else 
		{
			if (i / 10 > 0)
			{
				j = (i / 10) + 48;
				c = (char)j;
				write (1, &c, 1);
			}
			j = (i % 10) + 48;
			c = (char)j;
			write (1, &c, 1);		
			write (1, "\n", 1);
		}
		i++;
	}
	return (0);
}