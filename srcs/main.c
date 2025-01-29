/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcalero <lcalero@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:55:27 by luis              #+#    #+#             */
/*   Updated: 2025/01/29 23:04:32 by lcalero          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_mlx_data	data;

	if (ac < 2)
		return (ft_putstr_fd("Error\nYou must enter a file\n", 2), 1);
	if (ac > 2)
		return (ft_putstr_fd("Error\nToo much arguments\n", 2), 1);
	if (!check_map_extension(av[1]))
		return (ft_putstr_fd("Error\nWrong file extension\n", 2), 1);
	init_data(&data, av[1]);
	render_map(&data.map, &data);
	mlx_hook(data.win, 2, 1L<<0, key_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_loop(data.mlx);
	return (0);
}
