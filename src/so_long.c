/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:48:59 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/22 05:39:37 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_mlx(t_data_map map)
{
	t_init	mlx;

	mlx.mlx = mlx_init();
	mlx.window = mlx_new_window(mlx.mlx, map.width * TEXTURE_WIDTH, map.height * TEXTURE_HEIGHT, "So_long");
	mlx.img = mlx_new_image(mlx.mlx, map.width * TEXTURE_WIDTH, map.height * TEXTURE_HEIGHT);
	if (!mlx.img)
		return (0);
	//mlx_put_image_to_window(mlx, window, img, 1, 1);
	//mlx_loop(mlx);
}

int main(int ac, char **av)
{
	t_data_map	map;

	map.map = check_error(ac, av);
	if (!map.map)
		return (0);
	init_mlx(map);
	return (0);
}
