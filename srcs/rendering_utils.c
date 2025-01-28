/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 05:18:19 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/28 13:22:14 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*This function updates the number of moves the player
made and prints them in the shell*/
void	update_print_moves(t_mlx_data *data)
{
	char	*s;

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
