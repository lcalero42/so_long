/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rendering_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:58:26 by lcalero           #+#    #+#             */
/*   Updated: 2025/02/01 04:49:47 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*This function returns the image that needs to be rendered for
the player considering his direction and plays the right aniamtion
according to the player direction*/
t_image	render_player_texture(int keycode, t_mlx_data *data)
{
	if (keycode == W_KEY)
		return (play_anim(data, TOWARD_DIR));
	else if (keycode == A_KEY)
		return (play_anim(data, LEFT_DIR));
	else if (keycode == S_KEY)
		return (play_anim(data, BACKWARD_DIR));
	else
		return (play_anim(data, RIGHT_DIR));
}

/*This function saves in the data the right image that needs to be
rendered with its keycode associated*/
void	save_player_image(int keycode, t_mlx_data *data)
{
	data->player.current_image = render_player_texture(keycode, data);
	data->keycode = keycode;
}
