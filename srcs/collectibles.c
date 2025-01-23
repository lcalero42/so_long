/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:52:57 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/24 00:25:38 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

#include <stdio.h>
int	can_exit(t_mlx_data *data)
{
	printf("%d\n%d\n", data->player.collectibles, data->num_collectibles);
	return (data->player.collectibles == data->num_collectibles);
}
