/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:43:20 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/20 05:29:57 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	count_line(char *path_to_file)
{
	int		fd;
	int		nb_line;
	char	*line;

	line = "";
	nb_line = 0;
	fd = open(path_to_file, O_RDONLY);
	if (fd == -1)
		return (0);
	while (line)
	{
		line = get_next_line(fd);
		free(line);
		nb_line++;
	}
	return (nb_line);
}

char	**import_map_to_tab(char *path_to_file)
{
	//char	*line;
	//char	**map;
	//int		fd;
	int		nb_line;

	nb_line = count_line(path_to_file);
	printf("%i\n", nb_line);
	//line = "";
	//fd = open(path_to_file, O_RDONLY);
	//if (fd == -1)
	//	return (NULL);
	//while (line)
	//{
	//	line = get_next_line(fd);
	//}
}
