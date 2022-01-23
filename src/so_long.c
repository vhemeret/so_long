/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:48:59 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/23 00:44:14 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_mlx(t_data_map map)
{
	t_machine	*machine;

	machine->init->mlx = mlx_init();
	machine->init->window = mlx_new_window(machine->init->mlx,
		machine->map->width * TEXTURE_WIDTH,
		machine->map->height * TEXTURE_HEIGHT, "So_long");
	machine->init->img = mlx_new_image(machine->init->mlx,
		machine->map->width * TEXTURE_WIDTH,
		machine->map->height * TEXTURE_HEIGHT);
	if (!machine->init->img)
		return (0);
	load_texture(map);
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
