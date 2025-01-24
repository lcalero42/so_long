/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_path_possible.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 02:07:24 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/24 02:25:28 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	ft_free_visited(int **arr, t_mlx_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.height)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	is_path_possible(t_mlx_data *data)
{
	int	start_x;
	int	start_y;
	int	**is_visited;
	int	is_path_possible;

	is_visited = malloc(sizeof(int *) * data->map.height);
	init_visited(data, is_visited);
	start_x = -1;
	start_y = -1;
	find_player_pos(data, &start_x, &start_y);
	dfs(start_x, start_y, data, is_visited);
	is_path_possible = (count_collec(data, is_visited) == data->collectibles);
	ft_free_visited(is_visited, data);
	return (is_path_possible);
}
