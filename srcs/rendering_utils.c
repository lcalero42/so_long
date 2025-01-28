/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 05:18:19 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/28 12:19:27 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_print_moves(t_mlx_data *data)
{
	char	*s;

	data->player.nb_moves++;
	s = ft_itoa(data->player.nb_moves);
	ft_putstr_fd(s, 1);
	ft_putchar_fd('\n', 1);
	free(s);
}
