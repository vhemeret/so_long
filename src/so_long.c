/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:48:59 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/26 21:05:18 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_mlx(t_machine *data)
{
	data->init->mlx = mlx_init();
	if (!data->init->mlx)
	{
		free_all("/!\\ Error initialisation mlx /!\\", data);
		return (0);
	}
	if (!load_assets(data))
	{
		free_all("/!\\ Error when trying to load xpm to img /!\\", data);
		return (0);
	}
	data->init->window = mlx_new_window(data->init->mlx,
		data->map->width * TEXTURE_WIDTH, data->map->height * TEXTURE_HEIGHT,
		"So_long");
	if (!data->init->window)
	{
		free_all("/!\\ Error initialisation window /!\\", data);
		return (0);
	}
	data->img->img = mlx_new_image(data->init->mlx,
	data->map->width * TEXTURE_WIDTH, data->map->height * TEXTURE_HEIGHT);
	if (!data->img->img)
	{
		free_all("/!\\ Error initialisation window /!\\", data);
		return (0);
	}
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp,
		&data->img->line_len, &data->img->endian);
	return (1);
}

int main(int ac, char **av)
{
	t_machine	*data;

	data = manage_malloc_struct();
	if (!data)
		return (0);
	if (!check_error(ac, av, data))
	{
		free_struct(data);
		return (0);
	}
	if (!init_mlx(data))
	{
		printf("ici\n");
		//free_struct(data);
		mlx_destroy_display(data->init->mlx);
		return (0);
	}
	data->element->move_count = 0;
	pixel_dabbing(data);
	free_all("free\n", data);
	return (0);
}
