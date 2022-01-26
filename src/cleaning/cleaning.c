/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 02:14:03 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/26 19:12:56 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

char	**free_map(char **tab, int nb_elem)
{
	int	i;

	i = -1;
	if (nb_elem)
	{
		while (++i <= nb_elem)
		{
			free(tab[i]);
			tab[i] = NULL;
		}
	}
	free(tab);
	tab = NULL;
	return (tab);
}

void	free_struct(t_machine *data)
{
	free(data->tmp);
	free(data->map);
	free(data->init);
	free(data->img);
	free(data->element);
	free(data);
}

void	free_img(t_machine *data)
{
	if (data->img->img)
		mlx_destroy_image(data->init->mlx, data->img->img);
	if (data->element->collectable)
		mlx_destroy_image(data->init->mlx, data->element->collectable);
	if (data->element->floor)
		mlx_destroy_image(data->init->mlx, data->element->floor);
	if (data->element->wall)
		mlx_destroy_image(data->init->mlx, data->element->wall);
	if (data->element->door)
		mlx_destroy_image(data->init->mlx, data->element->door);
	if (data->element->player_front)
		mlx_destroy_image(data->init->mlx, data->element->player_front);
	if (data->element->player_back)
		mlx_destroy_image(data->init->mlx, data->element->player_back);
	if (data->element->player_left)
		mlx_destroy_image(data->init->mlx, data->element->player_left);
	if (data->element->player_right)
		mlx_destroy_image(data->init->mlx, data->element->player_right);
}

void	free_all(char *str, t_machine *data)
{
	printf("%s\n", str);
	free_img(data);
	if (data->init->window)
	{
		mlx_clear_window(data->init->mlx, data->init->window);
		mlx_destroy_window(data->init->mlx, data->init->window);
	}
	if (data->init->mlx)
		mlx_destroy_display(data->init->mlx);
	free_map(data->map->map, data->map->height);
	free_struct(data);
}
