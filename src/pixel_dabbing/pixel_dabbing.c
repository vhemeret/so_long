/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_dabbing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:33:44 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/26 01:43:13 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

unsigned int	get_pixel(void *img, int x, int y)
{
	char			*src;
	t_data_img		*tmp;
	unsigned int	color;

	tmp = malloc(sizeof(t_data_img));
	if (!tmp)
		return (0);
	tmp->addr = mlx_get_data_addr(img, &tmp->bpp, &tmp->line_len, &tmp->endian);
	src = tmp->addr + (y * tmp->line_len + x * (tmp->bpp / 8));
	color = *(unsigned int *)src;
	return (color);
}

void	my_mlx_pixel_put(t_machine *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img->addr + (y * data->img->line_len + x * (data->img->bpp / 8));
	*(unsigned int*)dst = color;
}

void	dabbing_element(t_machine *data, void *img, int x, int y)
{
	int			x_count;
	int			y_count;

	y_count = -1;
	while (++y_count < TEXTURE_WIDTH)
	{
		x_count = -1;
		while (++x_count < TEXTURE_HEIGHT)
		{
			data->element->color = get_pixel(img, x_count, y_count);
			if (!(data->element->color == (0xFF << 24)))
				my_mlx_pixel_put(data, (x * TEXTURE_WIDTH) + x_count,
					(y * TEXTURE_HEIGHT) + y_count, data->element->color);
		}
	}
}

void	pixel_dabbing(t_machine *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map->height)
	{
		x = -1;
		while (++x < data->map->width)
		{
			dabbing_element(data, data->element->floor, x, y);
			if (data->map->map[y][x] == '1')
				dabbing_element(data, data->element->wall, x, y);
			if (data->map->map[y][x] == 'C')
				dabbing_element(data, data->element->collectable, x, y);
			if (data->map->map[y][x] == 'E')
				dabbing_element(data, data->element->door, x, y);
			if (data->map->map[y][x] == 'P')
				dabbing_element(data, data->element->player_front, x, y);
		}
	}
	mlx_put_image_to_window(data->init->mlx, data->init->window,
	data->img->img, 0, 0);
	mlx_loop(data->init->mlx);
}