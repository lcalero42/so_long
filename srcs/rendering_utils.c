/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 05:18:19 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/01 04:43:40 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*This function updates the number of moves the player
made and prints them in the shell*/
void	update_print_moves(t_mlx_data *data)
{
	ft_putstr_fd("\e[1;36mMoves : \e[0m", 1);
	ft_putnbr_fd(data->player.nb_moves, 1);
	ft_putstr_fd("\n", 1);
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
