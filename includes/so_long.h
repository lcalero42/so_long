/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:07:11 by luis              #+#    #+#             */
/*   Updated: 2025/01/20 16:39:34 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct	s_image {
	void	*img;
	int		width;
	int		height;
}	t_image;

typedef struct s_mlx_data
{
    void	*mlx;
    void	*win;
    t_image	img;
}	t_mlx_data;

#endif