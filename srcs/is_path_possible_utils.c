/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_path_possible_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:52:56 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/24 02:18:35 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_traversable(int x, int y, t_mlx_data *data, int **is_visited)
{
	return ((x >= 0) && (x < data->map.width) && (y < data->map.height)
		&& (data->map.grid[y][x] != '1') && (data->map.grid[y][x] != 'E')
		&& (!is_visited[y][x]));
}

void	dfs(int x, int y, t_mlx_data *data, int **is_visited)
{
	is_visited[y][x] = 1;
	if (is_traversable(x, y - 1, data, is_visited))
		dfs(x, y - 1, data, is_visited);
	if (is_traversable(x, y + 1, data, is_visited))
		dfs(x, y + 1, data, is_visited);
	if (is_traversable(x - 1, y, data, is_visited))
		dfs(x - 1, y, data, is_visited);
	if (is_traversable(x + 1, y, data, is_visited))
		dfs(x + 1, y, data, is_visited);
}

void	find_player_pos(t_mlx_data *data, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.grid[i])
	{
		j = 0;
		while (data->map.grid[i][j])
		{
			if (data->map.grid[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_visited(t_mlx_data *data, int **is_visited)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.grid[i])
	{
		j = 0;
		is_visited[i] = malloc(sizeof(int) * data->map.width);
		while (j < data->map.width)
		{
			is_visited[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	count_collec(t_mlx_data *data, int **is_visited)
{
	int	i;
	int	j;
	int	collected;

	i = 0;
	collected = 0;
	while (data->map.grid[i])
	{
		j = 0;
		while (data->map.grid[i][j])
		{
			if (data->map.grid[i][j] == 'C' && is_visited[i][j])
				collected++;
			j++;
		}
		i++;
	}
	return (collected);
}
