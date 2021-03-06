/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 02:14:03 by vahemere          #+#    #+#             */
/*   Updated: 2022/02/04 22:19:26 by vahemere         ###   ########.fr       */
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
	mlx_destroy_image(data->init->mlx, data->img->img);
	mlx_destroy_image(data->init->mlx, data->element->player_front);
	mlx_destroy_image(data->init->mlx, data->element->player_back);
	mlx_destroy_image(data->init->mlx, data->element->player_left);
	mlx_destroy_image(data->init->mlx, data->element->player_right);
	mlx_destroy_image(data->init->mlx, data->element->wall);
	mlx_destroy_image(data->init->mlx, data->element->floor);
	mlx_destroy_image(data->init->mlx, data->element->door);
	mlx_destroy_image(data->init->mlx, data->element->collectable);
}

int	destroy_notify(t_machine *data)
{
	mlx_loop_end(data->init->mlx);
	return (0);
}

int	free_all(char *str, t_machine *data)
{
	if (str)
		printf("%s\n", str);
	if (data->init->texture_succes == 1)
		free_img(data);
	if (data->init->window)
	{
		mlx_clear_window(data->init->mlx, data->init->window);
		mlx_destroy_window(data->init->mlx, data->init->window);
	}
	if (data->init->mlx)
	{
		mlx_destroy_display(data->init->mlx);
		free(data->init->mlx);
	}
	free_map(data->map->map, data->map->height);
	free_struct(data);
	return (0);
}
