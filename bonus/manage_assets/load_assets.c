/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:33:38 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/29 20:52:31 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	load_floor(t_machine *data)
{
	data->element->floor = mlx_xpm_file_to_image(data->init->mlx,
			TEXTURE_FLOOR, &data->element->width, &data->element->height);
	if (!data->element->floor)
		return (0);
	return (1);
}

int	load_wall(t_machine *data)
{
	data->element->wall = mlx_xpm_file_to_image(data->init->mlx,
			TEXTURE_WALL, &data->element->width, &data->element->height);
	if (!data->element->wall)
		return (0);
	return (1);
}

int	load_door(t_machine *data)
{
	data->element->door = mlx_xpm_file_to_image(data->init->mlx,
			TEXTURE_DOOR, &data->element->width, &data->element->height);
	if (!data->element->door)
		return (0);
	return (1);
}

int	load_coin(t_machine *data)
{
	data->element->coin1 = mlx_xpm_file_to_image(data->init->mlx,
			TEXTURE_COIN1, &data->element->width, &data->element->height);
	if (!data->element->coin1)
		return (0);
			data->element->coin1 = mlx_xpm_file_to_image(data->init->mlx,
			TEXTURE_COIN2, &data->element->width, &data->element->height);
	if (!data->element->coin2)
		return (0);
			data->element->coin1 = mlx_xpm_file_to_image(data->init->mlx,
			TEXTURE_COIN3, &data->element->width, &data->element->height);
	if (!data->element->coin3)
		return (0);
			data->element->coin1 = mlx_xpm_file_to_image(data->init->mlx,
			TEXTURE_COIN4, &data->element->width, &data->element->height);
	if (!data->element->coin4)
		return (0);
			data->element->coin1 = mlx_xpm_file_to_image(data->init->mlx,
			TEXTURE_COIN5, &data->element->width, &data->element->height);
	if (!data->element->coin5)
		return (0);
	return (1);
}

int	load_assets(t_machine *data)
{
	if (!load_player(data) || !load_floor(data)
		|| !load_wall(data) || !load_coin(data) || !load_door(data))
		return (0);
	return (1);
}
