/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:52:57 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/31 17:08:16 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

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
