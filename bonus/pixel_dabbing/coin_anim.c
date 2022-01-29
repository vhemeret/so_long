/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_anim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 20:12:46 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/29 20:56:20 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	manage_coin(t_machine *data, int x, int y)
{
	static int time = 1;

	if (time == 5)
		time = 0;
	if (time % 5 == 1)
	{
		time++;
		dabbing_element(data, data->element->coin1, x, y);
		printf("coin1\n");
		return ;
	}
	if (time % 5 == 2)
	{
		dabbing_element(data, data->element->coin2, x, y);
		printf("coin2\n");
		time++;
		return ;
	}
	if (time % 5 == 3)
	{
		dabbing_element(data, data->element->coin3, x, y);
		printf("coin3\n");

		time++;
		return ;
	}
	if (time % 5 == 4)
	{
		dabbing_element(data, data->element->coin4, x, y);
		printf("coin4\n");

		time++;
		return ;
	}
	if (time % 5 == 5)
	{
		dabbing_element(data, data->element->coin5, x, y);
		printf("coin5\n");
		time++;
		return ;
	}
}