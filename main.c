/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:55:27 by luis              #+#    #+#             */
/*   Updated: 2025/01/18 17:35:06 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	pixel_put(t_image *image ,int x, int y, int color)
{
	char *dst;

	dst = image->addr + (y * image->line_length + x * (image->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	put_square(int x, int y, int length, t_image *image)
{
	int	i;

	if (length < 0)
		return ;
	i = 0;
	while (length > 0)
	{
		while (i < length)
		{
			pixel_put(image, x + i, y, 0x00FF0000);
			i++;
		}
		i = 0;
		while (i < length)
		{
			pixel_put(image, x + length, y + i, 0x00FF0000);
			i++;
		}
		i = 0;
		while (i < length)
		{
			pixel_put(image, (x + length) - i, y + length, 0x00FF0000);
			i++;
		}
		i = 0;
		while (i < length)
		{
			pixel_put(image, x, (y + length) - i, 0x00FF0000);
			i++;
		}
		length--;
	}
}

int	main(int ac, char **av)
{
	void 	*mlx;
	void	*mlx_win;
	t_image	img;

	(void)ac;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	put_square(ft_atoi(av[1]), ft_atoi(av[2]), 300, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
