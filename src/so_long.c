/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:48:59 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/25 22:06:26 by vahemere         ###   ########.fr       */
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
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp,
		&data->img->line_len, &data->img->endian);
	return (1);
}

int main(int ac, char **av)
{
	t_machine	*data;

	data = malloc(sizeof(*data));
	data->map = malloc(sizeof(t_data_map));
	data->init = malloc(sizeof(t_init));
	data->img = malloc(sizeof(t_data_img));
	data->element = malloc(sizeof(t_data_element));
	if (!data)
		return (0);
	check_error(ac, av, data);
	if (!data->map->map)
		return (0);
	if (!init_mlx(data))
		return (0);
	data->element->move_count = 0;
	pixel_dabbing(data);
	return (0);
}
