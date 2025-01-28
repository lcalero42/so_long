/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:52:57 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/28 13:23:33 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*This function go through all the data of the map
and counts how many collectibles the map contains*/
int	count_collectibles(t_mlx_data *data)
{
	int	i;
	int	j;
	int	cpt;

	i = 0;
	cpt = 0;
	while (data->map.grid[i])
	{
		j = 0;
		while (data->map.grid[i][j])
		{
			if (data->map.grid[i][j] == 'C')
				cpt++;
			j++;
		}
		i++;
	}
	return (cpt);
}

/*This function returns if the player is allowed to take
the exit by checking his number of collectibles*/
int	can_exit(t_mlx_data *data)
{
	return (data->player.collectibles == data->collectibles);
}
