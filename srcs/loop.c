/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:52:40 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/30 13:46:16 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	loop(t_mlx_data *data)
{
	render_map(&data->map, data);
	update_print_moves(data);
	mlx_do_sync(data->mlx);
	usleep(30000);
	return (0);
}
