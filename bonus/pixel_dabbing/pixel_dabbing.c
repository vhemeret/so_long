/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_dabbing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:33:44 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/30 20:25:03 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

unsigned int	get_pixel(t_machine *data, void *img, int x, int y)
{
	char			*src;
	unsigned int	color;

	data->tmp->addr = mlx_get_data_addr(img, &data->tmp->bpp,
			&data->tmp->line_len, &data->tmp->endian);
	src = data->tmp->addr
		+ (y * data->tmp->line_len + x * (data->tmp->bpp / 8));
	color = *(unsigned int *)src;
	return (color);
}

void	my_mlx_pixel_put(t_machine *data, int x, int y, int color)
{
	char	*dst;

	dst = data->img->addr
		+ (y * data->img->line_len + x * (data->img->bpp / 8));
	*(unsigned int *)dst = color;
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
			data->element->color = get_pixel(data, img, x_count, y_count);
			if (!(data->element->color == (0xFF << 24)))
				my_mlx_pixel_put(data, (x * TEXTURE_WIDTH) + x_count,
					(y * TEXTURE_HEIGHT) + y_count, data->element->color);
		}
	}
}

void	check_position(int position, t_machine *data)
{
	if (position == POS_FRONT)
		dabbing_element(data, data->element->player_front,
			data->element->pos_x, data->element->pos_y);
	else if (position == POS_BACK)
		dabbing_element(data, data->element->player_back,
			data->element->pos_x, data->element->pos_y);
	else if (position == POS_LEFT)
		dabbing_element(data, data->element->player_left,
			data->element->pos_x, data->element->pos_y);
	else if (position == POS_RIGHT)
		dabbing_element(data, data->element->player_right,
			data->element->pos_x, data->element->pos_y);
}

int	pixel_dabbing(t_machine *data, int position)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->map->height)
	{
		x = -1;
		while (++x < data->map->width)
		{
			if (data->map->map[y][x] == '0')
				dabbing_element(data, data->element->floor, x, y);
			if (data->map->map[y][x] == 'P')
				dabbing_element(data, data->element->floor, x, y);
			if (data->map->map[y][x] == 'O')
				dabbing_element(data, data->element->door_open, x, y);
			if (data->map->map[y][x] == 'A')
				dabbing_element(data, data->element->trap_active, x, y);
		}
	}
	check_position(position, data);
	mlx_put_image_to_window(data->init->mlx, data->init->window,
		data->img->img, 0, 0);
	return (0);
}
