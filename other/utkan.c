#include <unistd.h>


int	main(void)
{
	write(1, "pink", 4);
	write(1, "\n", 1);
}
