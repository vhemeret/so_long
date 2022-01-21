/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 19:42:11 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/21 19:06:23 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	check_name_file(char *path_to_file)
{
	int	i;

	i = 0;
	while (path_to_file[i])
		i++;
	if (path_to_file[i - 1] != 'r' || path_to_file[i - 2] != 'e'
		|| path_to_file[i - 3] != 'b' || path_to_file[i - 4] != '.')
		return (0);
	else
		return (1); 
}

int	check_existing_file(char *path_to_file)
{
	int fd;

	fd = open(path_to_file, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	check_is_directory(char *path_to_file)
{
	int	fd;

	fd = open(path_to_file, __O_DIRECTORY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

int	check_is_symbolic_link(char *path_to_file)
{
	int	fd;

	fd = open(path_to_file, __O_NOFOLLOW);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	check_fd(char *path_to_file)
{
	if (!check_name_file(path_to_file))
	{
		printf("/!\\ Le nom du fichier n'est pas bon.\n");
		return (0);
	}
	if (!check_existing_file(path_to_file))
	{
		printf("/!\\ Le fichier n'existe pas.\n");
		return (0);
	}
	if (!check_is_directory(path_to_file))
	{
		printf("/!\\ Ceci est un dossier.\n");
		return (0);
	}
	if (!check_is_symbolic_link(path_to_file))
	{
		printf("/!\\ Ceci est un lien symbolique.\n");
		return (0);
	}
	return (1);
}