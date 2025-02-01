/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_animation_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis <luis@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 02:38:07 by luis              #+#    #+#             */
/*   Updated: 2025/02/01 04:21:05 by luis             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/*This function plays an animation accordingly to the animation
index in parameter, we use static int to index so that each time the
function is called it renders a different image*/
t_image    play_anim(t_mlx_data *data, int anim_index)
{
    static int i = 0;
    
    if (data->player.animations[anim_index][i].img)
        mlx_put_image_to_window(data->mlx, data->win,
			    data->player.animations[anim_index][i].img,
                data->player.pos_x, data->player.pos_y);
    else
        print_error_free(data, "Error\nFailed to load image\n");
    i++;
    if (i == NUM_ANIM)
        i = 0;
    return (data->player.animations[anim_index][i]);
}

/*This function initializes all the images that are needed to render animations, 
this function is called in the init_data file*/
void    init_animations(t_mlx_data *data)
{
    data->player.animations[0][0].img = mlx_xpm_file_to_image(data->mlx,
			"ressources/anim_0.xpm", &data->player.animations[0][0].width,
			&data->player.animations[0][0].height);
	data->player.animations[0][1].img = mlx_xpm_file_to_image(data->mlx,
			"ressources/anim_1.xpm", &data->player.animations[0][1].width,
			&data->player.animations[0][1].height);
    data->player.animations[1][0].img = mlx_xpm_file_to_image(data->mlx,
			"ressources/anim_1_0.xpm", &data->player.animations[1][0].width,
			&data->player.animations[1][0].height);
	data->player.animations[1][1].img = mlx_xpm_file_to_image(data->mlx,
			"ressources/anim_1_1.xpm", &data->player.animations[1][1].width,
			&data->player.animations[1][1].height);
    data->player.animations[2][0].img = mlx_xpm_file_to_image(data->mlx,
			"ressources/anim_2_0.xpm", &data->player.animations[2][0].width,
			&data->player.animations[2][0].height);
	data->player.animations[2][1].img = mlx_xpm_file_to_image(data->mlx,
			"ressources/anim_2_1.xpm", &data->player.animations[2][1].width,
			&data->player.animations[0][1].height);
    data->player.animations[3][0].img = mlx_xpm_file_to_image(data->mlx,
			"ressources/anim_3_0.xpm", &data->player.animations[3][0].width,
			&data->player.animations[3][0].height);
	data->player.animations[3][1].img = mlx_xpm_file_to_image(data->mlx,
			"ressources/anim_3_1.xpm", &data->player.animations[3][1].width,
			&data->player.animations[3][1].height);
}

//This function frees all the images in the animation array
void    free_animations(t_mlx_data *data)
{
    int i;
    int j;

    i = 0;
    while(i < 4)
    {
        j = 0;
        while (j < NUM_ANIM)
        {
            if (data->player.animations[i][j].img)
                mlx_destroy_image(data->mlx, data->player.animations[i][j].img);
            j++;
        }
        i++;
    }    
}
