# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    sources.mk                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flcarval <flcarval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 11:56:41 by flcarval          #+#    #+#              #
#    Updated: 2022/10/04 11:56:42 by flcarval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

## SOURCES.MK ##

## SRC ##

SOURCES		+=                                		\
		src/cub3d.c                              	\


## SRC/GARBAGE_COLLECTOR ##

SOURCES		+=                                		\
		src/garbage_collector/garcol.c           	\


## SRC/UTILS ##

SOURCES		+=                                		\
		src/utils/math.c                         	\
		src/utils/ft_error.c                     	\
		src/utils/count_char.c                   	\
		src/utils/is_empty_str.c                 	\
		src/utils/free_split.c                   	\
		src/utils/split_len.c                    	\
		src/utils/utils.c                        	\


## SRC/PARSING ##

SOURCES		+=                                		\
		src/parsing/dir_handler.c                	\
		src/parsing/checker_map.c                	\
		src/parsing/param_handlers.c             	\
		src/parsing/save_map_loop.c              	\
		src/parsing/check_init_file.c            	\
		src/parsing/nb_col_line.c                	\
		src/parsing/save_file.c                  	\
		src/parsing/get_game_params.c            	\
		src/parsing/get_game_params_utils.c      	\
		src/parsing/maps_utils.c                 	\
		src/parsing/save_map.c                   	\


## SRC/RENDER ##

SOURCES		+=                                		\
		src/render/set_texture.c                 	\
		src/render/screen.c                      	\
		src/render/screen_tex.c                  	\
		src/render/draw.c                        	\
		src/render/screen_utils.c                	\
		src/render/screen_loop.c                 	\
		src/render/texture_to_int.c              	\
		src/render/init_and_key.c                	\


