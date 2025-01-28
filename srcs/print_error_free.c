/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:33:51 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/28 14:02:41 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*This function frees all the data that needs to be freed, 
prints the error that has been passed in parameter and exits the
program*/
void	print_error_free(t_mlx_data *data, char *s)
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
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	if (data->map.grid)
		ft_free(data->map.grid);
	ft_putstr_fd(s, 1);
	exit(0);
}
