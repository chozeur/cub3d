/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:33:29 by flcarval          #+#    #+#             */
/*   Updated: 2022/08/09 16:37:46 by flcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

# include "cub3d.h"

//////////////
// CHECKER x INIT
//////////////
void	check_init_file(int ac, char **av);
char	**save_file(char **av);
char	**save_map(char **file);
int		first_map_line(char **file);
int		checker_map(void);
int		first_line_map(char *str);
int		start_saving_map(int fd, char **av);
void	del_last_backslash_n(char *str);
char	*add_end_spaces(char *str);
char	*save_map_loop(char **save, char **file, int k, int i);

//////////////
// UTILS
//////////////
int		ft_strcmp(const char *s1, const char *s2);
void	free_split(char **spl, int free_spl);

//////////////
// GARBAGE COLLECTOR
//////////////
void	garcol_add(void *var);
void	garcol_free_all(void);

#endif
