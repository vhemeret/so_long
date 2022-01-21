/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vahemere <vahemere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 18:34:39 by vahemere          #+#    #+#             */
/*   Updated: 2022/01/21 19:40:36 by vahemere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	SO_LONG_H
# define SO_LONG_H

# include "minilibx_linux/mlx.h"
# include "src/get_next_line/get_next_line.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <stdio.h>

/**********************PARSING*************************/
char	**check_error(int ac, char **av);

/*	PARSING UTILS	*/
int		count_line(char *path_to_file);
char	**import_map_to_tab(char *path_to_file);
int		ft_strline(char *str);

/*	PARSING FILE	*/
int		check_fd(char *path_to_file);
int		check_is_symbolic_link(char *path_to_file);
int		check_is_directory(char *path_to_file);
int		check_existing_file(char *path_to_file);
int		check_name_file(char *path_to_file);

/*	PARSING MAP		*/
int		check_map_struct(char **map);
int		unexpected_char(char **map);
int		map_is_rectangle(char **map);
int		check_map_border(char **map);

/**********************CLEANING*************************/
char	**free_map(char **tab, int nb_elem);

#endif