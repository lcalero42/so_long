/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rendering.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:58:26 by lcalero           #+#    #+#             */
/*   Updated: 2025/01/30 18:16:58 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*This function returns the image that needs to be rendered for
the player considering his direction*/
t_image	get_player_texture(int keycode, t_mlx_data *data)
{
	if (keycode == W_KEY)
		return (data->images[4]);
	else if (keycode == A_KEY)
		return (data->images[6]);
	else if (keycode == S_KEY)
		return (data->images[3]);
	else
		return (data->images[5]);
}

/*This function saves in the data the right image that needs to be
rendered with its keycode associated*/
void	save_player_image(int keycode, t_mlx_data *data)
{
	data->player.current_image = get_player_texture(keycode, data);
	data->keycode = keycode;
}
