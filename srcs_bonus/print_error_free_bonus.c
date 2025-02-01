/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error_free_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:33:51 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/01 03:30:40 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
	free_animations(data);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	free(data->mlx);
	if (data->map.grid)
		ft_free(data->map.grid);
	ft_putstr_fd(s, 2);
	exit(0);
}
