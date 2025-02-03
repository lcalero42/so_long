/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 12:55:35 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/03 12:30:50 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static char	*ft_strjoin_free(char *s1, char *s2);

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
	res = ft_strdup("");
	if (fd < 0 || !res)
		return (free(res), print_error_free(data, "Error\nWrong file\n"), 1);
	line = get_next_line(fd);
	skip_newlines(&line, fd);
	while (line && *line != '\n')
	{
		data->map.height++;
		tmp = line;
		res = ft_strjoin_free(res, tmp);
		free(tmp);
		line = get_next_line(fd);
	}
	data->map.grid = ft_split(res, '\n');
	if (!data->map.grid[0] || !data)
		return (free(line), free(res), close(fd), 0);
	data->map.width = ft_strlen(data->map.grid[0]);
	close(fd);
	return (free(line), free(res), 1);
}

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
	if (!res)
		return (free(s1), NULL);
	ft_memcpy(res, s1, len_s1);
	ft_memcpy(res + len_s1, s2, j);
	res[len_s1 + j] = '\0';
	free(s1);
	return (res);
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
