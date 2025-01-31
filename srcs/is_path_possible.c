/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_path_possible.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 02:07:24 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/31 15:29:03 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static int	is_exit_possible(t_mlx_data *data);
static int	is_traversable_exit(int x, int y, t_mlx_data *data, int **is_visited);
static int	dfs_exit(int x, int y, t_mlx_data *data, int **is_visited);
static void	ft_free_visited(int **arr, t_mlx_data *data);

/*This function processes all the pathfinding logic and returns
if the player can collect all the collectibles and exit*/
int	is_path_possible(t_mlx_data *data)
{
	int	start_x;
	int	start_y;
	int	**is_visited;
	int	is_path_possible;

	if (!is_exit_possible(data))
		return (print_error_free(data, "Error\nNo exit possible\n"), 0);
	ft_putstr_fd("calculating if path is possible...\n", 1);
	is_visited = malloc(sizeof(int *) * data->map.height);
	init_visited(data, is_visited);
	start_x = -1;
	start_y = -1;
	find_player_pos(data, &start_x, &start_y);
	dfs(start_x, start_y, data, is_visited);
	is_path_possible = (count_possible_collec(data, is_visited)
			== data->collectibles);
	ft_free_visited(is_visited, data);
	return (is_path_possible);
}


/*This function tests if the player can exit the given
map, even if he can collect all the collectibles*/
static int	is_exit_possible(t_mlx_data *data)
{
	int	start_x;
	int	start_y;
	int	**is_visited;
	int	is_exit_possible;

	ft_putstr_fd("calculating if exit is possible...\n", 1);
	is_visited = malloc(sizeof(int *) * data->map.height);
	init_visited(data, is_visited);
	start_x = -1;
	start_y = -1;
	find_player_pos(data, &start_x, &start_y);
	is_exit_possible = dfs_exit(start_x, start_y, data, is_visited);
	ft_free_visited(is_visited, data);
	return (is_exit_possible);
}


/*This function uses Depth-First-Search algorithm to mark all
the boxes that can be visited by the player without counting the exit
as an obstacle and then returns if the player can exit*/
static int	dfs_exit(int x, int y, t_mlx_data *data, int **is_visited)
{
	int	i;
	int	j;

	i = 0;
	is_visited[y][x] = 1;
	if (is_traversable_exit(x, y - 1, data, is_visited))
		dfs_exit(x, y - 1, data, is_visited);
	if (is_traversable_exit(x, y + 1, data, is_visited))
		dfs_exit(x, y + 1, data, is_visited);
	if (is_traversable_exit(x - 1, y, data, is_visited))
		dfs_exit(x - 1, y, data, is_visited);
	if (is_traversable_exit(x + 1, y, data, is_visited))
		dfs_exit(x + 1, y, data, is_visited);
	while (data->map.grid[i])
	{
		j = 0;
		while (data->map.grid[i][j])
		{
			if (is_visited[i][j] && data->map.grid[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*This functions checks if a position is traversable or not without
counting the exit as an obstacle (useful to check if the player can exit
after he has collected all the collectibles)*/
static int	is_traversable_exit(int x, int y, t_mlx_data *data, int **is_visited)
{
	return ((x >= 0) && (x < data->map.width) && (y < data->map.height)
		&& (data->map.grid[y][x] != '1') && (!is_visited[y][x]));
}

/*This function frees all the data in the 2D array "arr"
passed in parameter*/
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
