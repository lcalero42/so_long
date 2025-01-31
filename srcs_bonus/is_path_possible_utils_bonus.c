/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_path_possible_utils_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 00:52:56 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/31 17:08:32 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	is_traversable(int x, int y, t_mlx_data *data, int **is_visited);

/*This function uses Depth-First-Search algorithm to mark all
the boxes that can be visited by the player*/
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

/*This functions checks if a position is traversable or not*/
int	is_traversable(int x, int y, t_mlx_data *data, int **is_visited)
{
	return ((x >= 0) && (x < data->map.width) && (y < data->map.height)
		&& (data->map.grid[y][x] != '1') && (data->map.grid[y][x] != 'E')
		&& (!is_visited[y][x]) && (data->map.grid[y][x] != 'K'));
}

/*This function finds the player starting position and initializes
x and y to these positions (this function is only used in the pathfinding
algorithms, this is not the function that set the player positions !)*/
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

/*This function initializes the visited 2D array and sets all
its values to zero (which means not visited yet)*/
void	init_visited(t_mlx_data *data, int **is_visited)
{
	int	i;

	i = 0;
	while (data->map.grid[i])
	{
		is_visited[i] = malloc(sizeof(int) * data->map.width);
		if (!is_visited[i])
		{
			while (--i >= 0)
				free(is_visited[i]);
			return ;
		}
		ft_bzero(is_visited[i], data->map.width * sizeof(int));
		i++;
	}
}

/*This function counts all the possible collectibles that the player
can collect in the given map*/
int	count_possible_collec(t_mlx_data *data, int **is_visited)
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
