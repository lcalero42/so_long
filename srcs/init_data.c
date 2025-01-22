/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 13:23:53 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/22 14:11:58 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_data(t_mlx_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1920, 1080, "so_long");
	data->images[0].img = mlx_xpm_file_to_image(data->mlx, "ressources/background.xpm", &data->images[0].width, &data->images[0].height);
	data->images[1].img = mlx_xpm_file_to_image(data->mlx, "ressources/box-1.xpm", &data->images[1].width, &data->images[1].height);
	data->images[2].img = mlx_xpm_file_to_image(data->mlx, "ressources/bottle.xpm", &data->images[2].width, &data->images[2].height);
}
