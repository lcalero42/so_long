/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:55:35 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/26 00:33:29 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <stdio.h>

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

int	parse_map(t_mlx_data *data)
{
	int		fd;
	int		i;
	char	*line;
	char	*tmp;
	char	*res;

	i = 0;
	fd = open("map.ber", O_RDONLY);
		if (fd < 0)
			print_error_free(data, "Error : Wrong entry file\n");
	line = get_next_line(fd);
	res = ft_strdup("");
	while (line && *line != '\n')
	{
		tmp = line;
		res = ft_strjoin_free(res, tmp);
		free(tmp);
		line = get_next_line(fd);
		i++;
	}
	data->map.grid = ft_split(res, '\n');
	data->map.height = i;
	data->map.width = ft_strlen(data->map.grid[0]);
	close(fd);
	return(free(line), free(res), 0);
}

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
