/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:48:59 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/23 20:07:48 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_mlx(t_machine *data)
{
	data->init->mlx = mlx_init();
	if (!data->init->mlx)
		// need to free mlx and map;
	data->init->window = mlx_new_window(data->init->mlx,
		data->map->width * TEXTURE_WIDTH,
		data->map->height * TEXTURE_HEIGHT, "So_long");
	data->init->img = mlx_new_image(data->init->mlx,
		data->map->width * TEXTURE_WIDTH,
		data->map->height * TEXTURE_HEIGHT);
	data->img->addr = mlx_get_data_addr(data->init->img,
	&data->img->bpp,
	&data->img->line_len, data->img->endian);
	if (!data->init->img)
		return (0);
	//load_texture(map);
}

int main(int ac, char **av)
{
	t_machine	*data;

	data->map->map = check_error(ac, av);
	if (!data->map->map)
		return (0);
	init_mlx(data);
	return (0);
}
