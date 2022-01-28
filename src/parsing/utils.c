/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:43:20 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/28 16:11:04 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_strline(char *str, t_machine *data)
{
	int	i;

	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	data->map->width = i;
	return (i);
}

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
	close(fd);
	return (nb_line - 1);
}

char	*copy_line(char *map, char *line)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	map = malloc(sizeof(char) * (i + 1));
	if (!map)
		return (NULL);
	i = -1;
	while (line[++i])
		map[i] = line[i];
	map[i] = '\0';
	return (map);
}

char	**import_map_to_tab(char *path_to_file)
{
	char	*line;
	char	**map;
	int		fd;
	int		nb_line;
	int		i;

	line = "";
	nb_line = count_line(path_to_file);
	map = malloc(sizeof(char *) * (nb_line + 1));
	if (!map)
		return (NULL);
	fd = open(path_to_file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = -1;
	while (nb_line)
	{
		line = get_next_line(fd);
		map[++i] = copy_line(*map, line);
		free(line);
		line = NULL;
		nb_line--;
	}
	map[i + 1] = NULL;
	return (map);
}
