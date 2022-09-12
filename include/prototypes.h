/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 16:33:29 by flcarval          #+#    #+#             */
/*   Updated: 2022/09/12 20:06:03 by tbrebion         ###   ########.fr       */
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
int		get_game_params(void);
void	NO_handler(char *str);
void	SO_handler(char *str);
void	WE_handler(char *str);
void	EA_handler(char *str);
void	F_handler(char *str);

//////////////
// UTILS
//////////////
int		ft_strcmp(const char *s1, const char *s2);
void	free_split(char **spl, int free_spl);
int		is_empty_str(char *str);
int		nb_line(void);
int		nb_col(void);
int		ft_close(void);
int		player_pos(char c);
double	ft_deg_to_rad(double d);
void	width_height_map(void);
int		for_win(char *line, int *i);
int		ft_spaceskip(char *line, int *i);


//////////////
// GARBAGE COLLECTOR
//////////////
void	garcol_add(void *var);
char	**garcol_split(char *str, char lim);
void	garcol_free_all(void);

////////////////
// KEY x RENDER
////////////////
void	init_mlx(void);
int		ft_key(int keysym);
void	ft_ws(double d);
void	ft_ad(double d);
void	ft_rotate(double d);
void	draw(void);
// void	ray_right(void);
// void	ray_left(void);
void	ray_ver(void);
void	ray_hor(void);
void	ray_rotate(void);
int 	which_side(void);
void	ft_dir(void);
void	screen_loop(void);
void	draw_line(int start_x, int side, int screen);

// void	init_pos(void);

#endif
