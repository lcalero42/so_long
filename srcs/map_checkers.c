/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 20:34:45 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/24 04:40:15 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*This function checks that the height or the 
width of the map is not too big*/
int	check_map_size(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.grid[i])
	{
		if (i > 30)
			print_error_free(data, "Error : height too high\n");
		j = 0;
		while (data->map.grid[i][j])
			j++;
		if (j > 60)
			print_error_free(data, "Error : width too high\n");
		i++;
	}
	return (1);
}

/*This function checks that the shape of the map
is rectangular and no other*/
static int	check_map_shape(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.grid[i])
	{
		j = i + 1;
		while (data->map.grid[j])
		{
			if (ft_strlen(data->map.grid[i]) != ft_strlen(data->map.grid[j]))
				print_error_free(data, "Error : map is not rectangular\n");
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
	if (i == 0 && c != '1')
		return (0);
	if (j == 0 && c != '1')
		return (0);
	if (i == data->map.height - 1 && c != '1')
		return (0);
	if (j == data->map.width - 1 && c != '1')
		return (0);
	if ((c != '1') && (c != '0') && (c != 'E') && (c != 'P') && (c != 'C'))
		return (0);
	return (1);
}

/*This function processes all the map checking logic*/
int	check_map(t_mlx_data *data)
{
	int	i;
	int	j;

	i = 0;
	check_map_size(data);
	check_map_shape(data);
	while (data->map.grid[i])
	{
		j = 0;
		while (data->map.grid[i][j])
		{
			if (!check_wrong_input(data->map.grid[i][j], i, j, data))
				print_error_free(data, "Error : Wrong input entered\n");
			j++;
		}
		i++;
	}
	if (!is_path_possible(data))
		print_error_free(data, "Error : no path possible\n");
	return (1);
}
