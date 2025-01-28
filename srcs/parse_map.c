/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:55:35 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/28 14:27:43 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*This function joins s1 and s2 string and frees s1 in the
same time*/
static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*res;
	size_t	len_s1;
	size_t	j;

	j = 0;
	len_s1 = ft_strlen(s1);
	while (s2[j] != '\n' && s2[j])
		j++;
	if (s2[j] == '\n')
		j++;
	res = malloc((len_s1 + j + 1) * sizeof(char));
	if (res == NULL)
		return (free(s1), NULL);
	ft_memcpy(res, s1, len_s1);
	ft_memcpy(res + len_s1, s2, j);
	res[len_s1 + j] = '\0';
	free(s1);
	return (res);
}

/*This function checks the right image to put at a certain position
in the given map and puts it on the screen*/
static void	put_right_image(char c, t_mlx_data *data, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images[1].img, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(data->mlx, data->win,
			data->images[2].img, x, y);
	else if (c == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->images[3].img, x, y);
		data->player.pos_x = x;
		data->player.pos_y = y;
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->images[7].img, x, y);
	}
	else if (c == '0')
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->images[0].img, x, y);
	}
}

/*This function frees all the data in the 2D string res
(used to free what split allocated)*/
void	ft_free(char **res)
{
	int	i;

	i = 0;
	while (res[i])
	{
		if (res[i])
			free(res[i]);
		i++;
	}
	free(res);
}

/*This function parses the string in the file that
has been passed in parameter and puts all the elements
in the grid in the map struct*/
int	parse_map(t_mlx_data *data, char *file_name)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*res;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		print_error_free(data, "Error\nWrong entry file\n");
	line = get_next_line(fd);
	res = ft_strdup("");
	while (line && *line != '\n')
	{
		data->map.height++;
		tmp = line;
		if (data->map.width == 0)
			data->map.width = ft_strlen(tmp) - 1;
		res = ft_strjoin_free(res, tmp);
		free(tmp);
		line = get_next_line(fd);
	}
	data->map.grid = ft_split(res, '\n');
	close(fd);
	return (free(line), free(res), 0);
}

/*This function get through all the elements of the map
and puts each time the corresponding image to the screen at
the right position*/
int	render_map(t_map *map, t_mlx_data *data)
{
	int	i;
	int	j;
	int	x;
	int	y;

	x = 0;
	y = 0;
	i = 0;
	while (map->grid[i] && i < 30)
	{
		j = 0;
		while (map->grid[i][j] && j < 60)
		{
			put_right_image(map->grid[i][j], data, x, y);
			check_player_starting(data, map->grid[i][j], i, j);
			j++;
			x += 64;
		}
		x = 0;
		y += 64;
		i++;
	}
	return (0);
}
