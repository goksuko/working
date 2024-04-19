#include "../include/so_long.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
		return (ft_printf("Please provide 1 map.\n"), 1);
	else
	{
		if (sl_check_map_probs(argv[1]))
			return (ft_printf("Map is not valid.\n"), 1);
		else
			return (ft_printf("Fine.\n"), 0);
	}
	return (0);
}