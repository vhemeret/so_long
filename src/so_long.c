/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:48:59 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/24 23:50:26 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_mlx(t_machine *data)
{
	data->init->mlx = mlx_init();
	if (!data->init->mlx)
	{
		free_map(data->map->map, data->map->height);
		printf("/!\\ Error initialisation mlx /!\\\n");
		return (0);
	}
	if (!load_assets(data))
		return (0); //pensez a free dans load_assets.c
	data->init->window = mlx_new_window(data->init->mlx,
		data->map->width * TEXTURE_WIDTH, data->map->height * TEXTURE_HEIGHT,
		"So_long");
	if (!data->init->window)
	{
		free_map(data->map->map, data->map->height);
		//free mlx
		printf("/!\\ Error initialisation window /!\\\n");
		return (0);
	}
	data->img->img = mlx_new_image(data->init->mlx,
	data->map->width * TEXTURE_WIDTH, data->map->height * TEXTURE_HEIGHT);
	if (!data->img->img)
	{
		free_map(data->map->map, data->map->height);
		//free mlx & window
		printf("/!\\ Error initialisation window /!\\\n");
		return (0);
	}
	return (1);
}

int main(int ac, char **av)
{
	t_machine	*data;

	data->map->map = check_error(ac, av);
	if (!data->map->map)
		return (0);
	if (!init_mlx(data))
		return (0);
	data->element->move_count = 0;
	pixel_dabbing(data); // a creer
	return (0);
}
