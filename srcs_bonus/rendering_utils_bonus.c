/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 05:18:19 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/03 13:14:03 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*This function updates the number of moves the player
made and prints them in the shell*/
void	update_print_moves(t_mlx_data *data)
{
	char	*s;

	s = NULL;
	s = ft_itoa(data->player.nb_moves);
	if (!s)
	{
		free(s);
		print_error_free(data, "Allocation Error\n");
	}
	mlx_string_put(data->mlx, data->win,
		data->window_x - 100, 27, WHITE, "Moves :");
	mlx_string_put(data->mlx, data->win,
		data->window_x - 25, 28, WHITE, s);
	free(s);
}

/*This function prints a winning message with the number
of moves the player made to win and closes the window*/
void	player_win(t_mlx_data *data)
{
	ft_putstr_fd("\e[0;32mWell done ! You won with \033[0m", 1);
	ft_putstr_fd("\e[0;35m", 1);
	ft_putnbr_fd(data->player.nb_moves, 1);
	ft_putstr_fd("\e[0;32m", 1);
	ft_putstr_fd(" moves !\n", 1);
	ft_putstr_fd("\033[0m", 1);
	close_window(data);
}

/*This functions skips all the newlines in the file
that is being read to be able to render the map even with
newlines separating lines*/
void	skip_newlines(char **line, int fd)
{
	char	*tmp;

	if (!line || !*line)
		return ;
	while (*line && !ft_strncmp(*line, "\n", ft_strlen(*line)))
	{
		tmp = *line;
		free(tmp);
		*line = get_next_line(fd);
	}
}

/*This function checks the extension of the string
we enter and returns 1 if it is a .ber and 0 if it is not*/
int	check_map_extension(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
			if (ft_strncmp(s + i, ".ber", 4))
				return (0);
		i++;
	}
	return (1);
}

void	check_end_of_file(char **line, int fd, char *res, t_mlx_data *data)
{
	char	*tmp;
	int		i;

	if (!line || !*line)
		return ;
	i = 0;
	while (*line)
	{
		tmp = *line;
		while (tmp[i])
		{
			if (tmp[i] != '\n')
			{
				free(res);
				free(tmp);
				close(fd);
				print_error_free(data, "Error\nWrong Input\n");
			}
			i++;
		}
		*line = get_next_line(fd);
		free(tmp);
	}
}
