/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_door_open_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 19:36:25 by vahemere          #+#    #+#             */
/*   Updated: 2022/02/04 21:55:54 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	load_door_open(t_machine *data)
{
	data->element->door_open = mlx_xpm_file_to_image(data->init->mlx,
			TEXTURE_DOOR_OPEN, &data->element->width, &data->element->height);
	if (!data->element->door_open)
	{
		mlx_destroy_image(data->init->mlx, data->img->img);
		mlx_destroy_image(data->init->mlx, data->element->player_front);
		mlx_destroy_image(data->init->mlx, data->element->player_back);
		mlx_destroy_image(data->init->mlx, data->element->player_left);
		mlx_destroy_image(data->init->mlx, data->element->player_right);
		mlx_destroy_image(data->init->mlx, data->element->coin1);
		mlx_destroy_image(data->init->mlx, data->element->coin2);
		mlx_destroy_image(data->init->mlx, data->element->coin3);
		mlx_destroy_image(data->init->mlx, data->element->coin4);
		mlx_destroy_image(data->init->mlx, data->element->wall);
		mlx_destroy_image(data->init->mlx, data->element->floor);
		mlx_destroy_image(data->init->mlx, data->element->door);
		return (0);
	}
	return (1);
}
