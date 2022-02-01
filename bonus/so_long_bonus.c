/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 17:03:38 by vahemere          #+#    #+#             */
/*   Updated: 2022/02/01 21:28:16 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	init_mlx(t_machine *data)
{
	data->init->mlx = mlx_init();
	if (!data->init->mlx)
		return (free_all("Error\n/!\\ initialisation mlx /!\\", data));
	if (!load_assets(data))
		return (free_all("Error\n/!\\when trying to load xpm to img /!\\",
				data));
	data->init->window = mlx_new_window(data->init->mlx,
			data->map->width * TEXTURE_WIDTH,
			data->map->height * TEXTURE_HEIGHT, "So_long");
	if (!data->init->window)
		return (free_all("Error\n/!\\ initialisation window /!\\", data));
	data->img->img = mlx_new_image(data->init->mlx,
			data->map->width * TEXTURE_WIDTH,
			data->map->height * TEXTURE_HEIGHT);
	if (!data->img->img)
		return (free_all("Error\n/!\\ initialisation window /!\\", data));
	data->img->addr = mlx_get_data_addr(data->img->img, &data->img->bpp,
			&data->img->line_len, &data->img->endian);
	return (1);
}

int	main(int ac, char **av)
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
		return (0);
	data->element->move_count = 0;
	data->element->frame_trap = 0;
	data->element->state_wall = 0;
	data->element->frame = 0;
	pos_player(data);
	first_dabbing(data);
	mlx_key_hook(data->init->window, manage_hook, data);
	mlx_loop_hook(data->init->mlx, animate_dabbing, data);
	mlx_hook(data->init->window, 17, (1L << 5), destroy_notify, data);
	mlx_loop(data->init->mlx);
	free_all(NULL, data);
	return (0);
}
