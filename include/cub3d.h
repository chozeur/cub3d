/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:43:18 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/02 18:38:26 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "../minilibx-linux/mlx.h"
#include "../Lib42/include/lib42.h"

typedef struct	s_game
{
	int		max_len;
	char	**map;
}	t_game;

typedef struct	s_data
{
	t_game	game;
	t_list	**garbage;
}	t_data;

extern t_data	g_data;

//////////////
// CHECKER x INIT
//////////////
void	check_and_init(int ac, char **av);
char	**save_map(char **av);
int		checker_map(void);

//////////////
// UTILS
//////////////
int		ft_strcmp(const char *s1, const char *s2);
void	free_split(char **spl, int free_spl);

//////////////
// GARBAGE COLLECTOR
//////////////
void	*garcol_add(void *var, size_t size);
void	garcol_free_all(void);


#endif