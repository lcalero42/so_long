/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:52:40 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/01 04:11:49 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*This function is a typical loop function and
is called every frame, it renders the map and updates
the moves printeed on the screen (i added a usleep
to make less calculations and less mallocs)*/
int	loop(t_mlx_data *data)
{
	render_map(&data->map, data);
	update_print_moves(data);
	mlx_do_sync(data->mlx);
	usleep(70000);
	return (0);
}
