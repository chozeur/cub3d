/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:50:18 by tbrebion          #+#    #+#             */
/*   Updated: 2022/08/26 20:07:29 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	init(void);

t_data	g_data;

int	ft_close(void)
{
	mlx_clear_window(g_data.mlx.ptr, g_data.win.ptr);
	mlx_destroy_window(g_data.mlx.ptr, g_data.win.ptr);
	mlx_destroy_image(g_data.mlx.ptr, g_data.img.ptr);
	mlx_destroy_display(g_data.mlx.ptr);
	garcol_free_all();
	exit(0);
	return (1);
}

int	main(int ac, char **av, char **envp)
{
	(void)envp;
	init();
	check_init_file(ac, av);
	init_mlx();

	///////////////////////////////////
	draw();	
	mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x * SIZE, g_data.pos.y * SIZE, 0x00FFFFFF);
	////////////////////////////////////////////////////////////////////

	mlx_hook(g_data.win.ptr, 2, (1L << 0), &ft_key, &g_data);
	mlx_hook(g_data.win.ptr, 17, 0, &ft_close, &g_data);
	mlx_loop(g_data.mlx.ptr);
	garcol_free_all();
	return (0);
}

static void	init(void)
{
	g_data.win.x = 2558/*1420*/;
	g_data.win.y = 1080/*800*/;
	g_data.map.x = 0;
	g_data.map.y = 0;
	g_data.pos.x = 0;
	g_data.pos.y = 0;
}

// double	ft_deg_to_rad(double d)
// {
// 	return (d * M_PI / 180.0);
// }
