// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include "../include/so_long.h"
// #include "../MLX42/include/MLX42/MLX42.h"
// #include "../MLX42/include/MLX42/MLX42_int.h"
// #include "../include/MLX42.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// #include "../include/MLX42_int.h"

#define WIDTH 2560
#define HEIGHT 2560
#define BPP sizeof(int32_t)

static mlx_image_t	*image;

// -----------------------------------------------------------------------------

int32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	ft_randomize(void *param)
{
	(void)param;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(rand() % 0xFF, // R
										rand() % 0xFF, // G
										rand() % 0xFF, // B
										rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void	ft_hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
		image->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
		image->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		image->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		image->instances[0].x += 5;
}

// -----------------------------------------------------------------------------

int32_t	main(void)
{
	mlx_t	*mlx;
	xpm_t	*demo;

	// mlx_texture_t* mouth;
	write(1, "Hello, World!\n", 14);

	// Start mlx
	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}

	// // Load a texture
	// if(!(mouth = mlx_load_png("../textures/mouth2.png")))
	// {
	// 	puts(mlx_strerror(mlx_errno));
	// 	return(EXIT_FAILURE);
	// }

	// Load a texture
	if (!(demo = mlx_load_xpm42("../xpms/demo.xpm42")))
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}

	// Create a new image
	if (!(image = mlx_new_image(mlx, 128, 128)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_texture_to_image(mlx, &demo->texture)))
	{
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}

	// Set every pixel to white
	memset(image->pixels, 255, image->width * image->height * BPP);
	mlx_put_pixel(image, 0, 0, 0xFF0000FF);
	// Display an instance of the image
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return (EXIT_FAILURE);
	}
	// Set the instance position
	// image->instances[0].x = 50;
	// image->instances[0].y = 50;
	// mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}

// size_t size;

// mlx_image_t	i1;
// size = i1.count;

// mlx_image_t	*i2;
// size = i2->count;

// mlx_image_t	**i3;
// size = i3[0]->count;

// endian => the order in which bytes are transmitted
