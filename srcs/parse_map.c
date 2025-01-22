/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:55:35 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/22 20:35:06 by lcalero          ###   ########.fr       */
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

int	parse_map(t_map *map)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*res;

	fd = open("map.ber", O_RDONLY);
	line = get_next_line(fd);
	res = ft_strdup("");
	while (line && *line != '\n')
	{
		tmp = line;
		res = ft_strjoin_free(res, tmp);
		free(tmp);
		line = get_next_line(fd);
	}
	map->grid = ft_split(res, '\n');
	free(line);
	free(res);
	return (0);
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
	while (map->grid[i])
	{
		j = 0;
		while (map->grid[i][j])
		{
			put_right_image(map->grid[i][j], data, x, y);
			j++;
			x += 64;
		}
		x = 0;
		y += 64;
		i++;
	}
	map->height = i;
	map->width = ft_strlen(map->grid[0]);
	return (0);
}
