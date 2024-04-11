#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <MLX42/MLX42.h>
// #include <MLX42/MLX42_Int.h>

int32_t main(void)
{
	mlx_t* mlx;

	if (!(mlx = mlx_init(512, 512, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
}