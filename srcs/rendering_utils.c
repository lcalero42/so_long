/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 05:18:19 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/29 18:03:26 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*This function updates the number of moves the player
made and prints them in the shell*/
void	update_print_moves(t_mlx_data *data)
{
	char	*s;

	s = NULL;
	data->player.nb_moves++;
	s = ft_itoa(data->player.nb_moves);
	ft_putstr_fd(s, 1);
	ft_putchar_fd('\n', 1);
	free(s);
}

/*This function prints a winning message with the number
of moves the player made to win and closes the window*/
void	player_win(t_mlx_data *data)
{
	ft_putstr_fd("Well done ! You won with ", 1);
	ft_putnbr_fd(data->player.nb_moves, 1);
	ft_putstr_fd(" moves !\n", 1);
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
int		check_map_extension(char *s)
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
