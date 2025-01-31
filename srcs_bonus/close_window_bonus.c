/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_window_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:20:25 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/31 17:08:11 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*closes the window and frees all the data
that needs to be freed*/
int	close_window(t_mlx_data *data)
{
	int	i;

	i = 0;
	while (i < NUM_IMAGES)
	{
		if (data->images[i].img)
			mlx_destroy_image(data->mlx, data->images[i].img);
		i++;
	}
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	mlx_loop_end(data->mlx);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	ft_free(data->map.grid);
	exit(0);
	return (0);
}
