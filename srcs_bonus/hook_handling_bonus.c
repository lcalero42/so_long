/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handling_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 19:22:05 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/31 17:08:20 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

//used to determin which key has been pressed
int	key_hook(int keycode, t_mlx_data *data)
{
	if (keycode == ESC_KEY)
		close_window(data);
	determin_movement(data, keycode);
	return (0);
}
