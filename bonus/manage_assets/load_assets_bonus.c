/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_assets_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 17:33:38 by vahemere          #+#    #+#             */
/*   Updated: 2022/02/04 22:06:48 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	load_wall(t_machine *data)
{
	data->element->wall = mlx_xpm_file_to_image(data->init->mlx,
			TEXTURE_WALL, &data->element->width, &data->element->height);
	if (!data->element->wall)
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
		return (0);
	}
	return (1);
}

int	load_floor(t_machine *data)
{
	data->element->floor = mlx_xpm_file_to_image(data->init->mlx,
			TEXTURE_FLOOR, &data->element->width, &data->element->height);
	if (!data->element->floor)
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
		return (0);
	}
	return (1);
}

int	load_door(t_machine *data)
{
	data->element->door = mlx_xpm_file_to_image(data->init->mlx,
			TEXTURE_DOOR, &data->element->width, &data->element->height);
	if (!data->element->door)
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
		return (0);
	}
	return (1);
}

int	load_trap(t_machine *data)
{
	data->element->trap = mlx_xpm_file_to_image(data->init->mlx,
			TEXTURE_TRAP, &data->element->width, &data->element->height);
	if (!data->element->trap)
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
		mlx_destroy_image(data->init->mlx, data->element->door_open);
		return (0);
	}
	return (1);
}

int	load_assets(t_machine *data)
{
	if (!load_player(data) || !load_coin(data)
		|| !load_wall(data) || !load_floor(data) || !load_door(data)
		|| !load_door_open(data) || !load_trap(data))
	{
		data->init->texture_succes = 0;
		return (0);
	}
	return (1);
}
