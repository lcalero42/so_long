/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:34:45 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/03 10:57:58 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static int	check_map_size(t_mlx_data *data);
static int	check_map_shape(t_mlx_data *data);
static int	check_wrong_input(char c, int i, int j, t_mlx_data *data);
static void	check_duplicates(t_mlx_data *data);

/*This function processes all the map checking logic*/
int	check_map(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.grid[i])
	{
		j = 0;
		while (data->map.grid[i][j])
		{
			if (!check_wrong_input(data->map.grid[i][j], i, j, data))
				print_error_free(data, "Error\nWrong input entered\n");
			j++;
		}
		i++;
	}
	check_map_size(data);
	check_map_shape(data);
	check_duplicates(data);
	if (!is_path_possible(data))
		print_error_free(data, "Error\nNo path possible\n");
	return (1);
}

/*This function checks that the height or the 
width of the map is not too big*/
static int	check_map_size(t_mlx_data *data)
{
	if (IMG_SIZE * data->map.height > 1080 || IMG_SIZE * data->map.width > 1920)
	{
		print_error_free(data, "Error\nSize of the map is too big\n");
		return (0);
	}
	return (1);
}

/*This function checks that the shape of the map
is rectangular and no other*/
static int	check_map_shape(t_mlx_data *data)
{
	int	i;
	int	j;

	ft_putstr_fd("Checking map shape...\n", 1);
	i = 0;
	while (data->map.grid[i])
	{
		j = i + 1;
		while (data->map.grid[j])
		{
			if (ft_strlen(data->map.grid[i]) != ft_strlen(data->map.grid[j]))
				print_error_free(data, "Error\nMap is not rectangular\n");
			j++;
		}
		i++;
	}
	return (1);
}

/*This function returns if an element in the map is valid
or not*/
static int	check_wrong_input(char c, int i, int j, t_mlx_data *data)
{
	if ((i == 0) && (c != '1'))
		return (0);
	if ((j == 0) && (c != '1'))
		return (0);
	if ((i == data->map.height - 1) && (c != '1'))
		return (0);
	if ((j == data->map.width - 1) && (c != '1'))
		return (0);
	if ((c != '1') && (c != '0') && (c != 'E') && (c != 'P')
		&& (c != 'C') && (c != 'K'))
		return (0);
	return (1);
}

/*This function checks if there are duplicates exits or player
starting positions in the given map*/
static void	check_duplicates(t_mlx_data *data)
{
	int	i;
	int	j;
	int	cpt_exit;
	int	cpt_start;

	ft_putstr_fd("Checking number of exits and starts...\n", 1);
	i = 0;
	cpt_exit = 0;
	cpt_start = 0;
	while (data->map.grid[i])
	{
		j = 0;
		while (data->map.grid[i][j])
		{
			if (data->map.grid[i][j] == 'E')
				cpt_exit++;
			if (data->map.grid[i][j] == 'P')
				cpt_start++;
			j++;
		}
		i++;
	}
	if ((cpt_exit != 1) || (cpt_start != 1))
		print_error_free(data,
			"Error\nNumber of exit and start must be one\n");
}
