/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_key.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:27:45 by tbrebion          #+#    #+#             */
/*   Updated: 2022/09/05 16:06:29 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static void	ft_ws(double d);
static void	ft_ad(double d);
static void	ft_rotate(double d);
// static void	ray_player(void);
// static void	ray_30_right(void);
// static void	ray_30_left(void);
static void	others_ray(double d);
static int which_side(void);
static void draw_wall(void);

void	init_mlx(void)
{
	g_data.mlx.ptr = mlx_init();
	garcol_add(g_data.mlx.ptr);
	g_data.win.ptr = mlx_new_window(g_data.mlx.ptr, g_data.win.x, g_data.win.y, "./cub3d");
	g_data.img.ptr = mlx_new_image(g_data.mlx.ptr, g_data.win.x, g_data.win.y);
}

int	ft_key(int keysym)
{
	if (keysym == XK_Escape)
		ft_close();
	else if (keysym == XK_w) 
		ft_ws(1);
	else if (keysym == XK_s) 
		ft_ws(-1);
	else if (keysym == XK_d) 
		ft_ad(1);
	else if (keysym == XK_a) 
		ft_ad(-1);
	else if (keysym == XK_Left)
		ft_rotate(-1);
	else if (keysym == XK_Right)
		ft_rotate(1);
	// ray_player();
	// ray_30_left();
	// ray_30_right();
	others_ray(1);
	others_ray(-1);
	mlx_clear_window(g_data.mlx.ptr, g_data.win.ptr);
	mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x * SIZE, g_data.pos.y * SIZE, 0x00FFFFFF);

	// mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.ray.x * SIZE, g_data.ray.y * SIZE, 0x00FFFFFF);

	printf("//////////////////////////////////////////\n");
	printf("RAYX %f    RAYY %f", g_data.ray.x, g_data.ray.y);
	printf("//////////////////////////////////////////\n");
	////////////////////////////////////////////////////////////
	printf("//////////////////////////////////////////\n");
	printf("\nPOSx : %f\n\nPOSy : %f\n\n", g_data.pos.x, g_data.pos.y);
	printf("//////////////////////////////////////////\n");
	printf("\nDIRx : %f\n\nDIRy : %f\n\n", g_data.dir.x, g_data.dir.y);
	printf("//////////////////////////////////////////\n");
	// mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.pos.x * SIZE, g_data.pos.y * SIZE, 0x00FFFFFF);
	////////////////////////////////////////////////////////////
	
	return (1);
}

static void	ft_ws(double d)
{
	g_data.pos.x += d * (g_data.dir.x * SPEED / 100);
	if (g_data.map.tab[(int)floor(g_data.pos.y)][(int)floor(g_data.pos.x)] == '1')
		g_data.pos.x -= d * (g_data.dir.x * SPEED / 100);
	g_data.pos.y += d * (g_data.dir.y * SPEED / 100);
	if (g_data.map.tab[(int)floor(g_data.pos.y)][(int)floor(g_data.pos.x)] == '1')
		g_data.pos.y -= d * (g_data.dir.y * SPEED / 100);
}

static void	ft_ad(double d)
{
	g_data.pos.x -= d * (g_data.dir.y * SPEED / 100);
	if (g_data.map.tab[(int)floor(g_data.pos.y)][(int)floor(g_data.pos.x)] == '1')
		g_data.pos.x += d * (g_data.dir.y * SPEED / 100);
	g_data.pos.y += d * (g_data.dir.x * SPEED / 100);
	if (g_data.map.tab[(int)floor(g_data.pos.y)][(int)floor(g_data.pos.x)] == '1')
		g_data.pos.y -= d * (g_data.dir.x * SPEED / 100);
}

static void	ft_rotate(double d)
{
	double	dist;

	g_data.dir.x = g_data.dir.x * cos(d * TURN) - g_data.dir.y * sin(d * TURN);
	g_data.dir.y = g_data.dir.y * cos(d * TURN) + g_data.dir.x * sin(d * TURN);
	dist = hypot(g_data.dir.x, g_data.dir.y);
	g_data.dir.x /= dist;
	g_data.dir.y /= dist;
	// printf("////////////////////\nDIST IN ROTATE: %f\n////////////////////////\n", dist);
}

// static void	ray_player(void)
// {
// 	int		i;
// 	double	x;
// 	double	y;
// 	double	dist;

// 	i = 0;
// 	x = /*0.0;*/g_data.pos.x;
// 	y = /*0.0;*/g_data.pos.y;
// 	dist = 0.0;
// 	while (i < g_data.win.x * 2)
// 	{
// 		x += /*sqrt(1 + (g_data.dir.y * g_data.dir.y) / (g_data.dir.x * g_data.dir.x));*/(g_data.dir.x * SPEED / 1000);
// 		y += /*sqrt(1 + (g_data.dir.x * g_data.dir.x) / (g_data.dir.y * g_data.dir.y));*/(g_data.dir.y * SPEED / 1000);
// 		if (g_data.map.tab[(int)floor(y)][(int)floor(x)] == '1' || g_data.map.tab[(int)floor(y)][(int)floor(x)] == ' ')
// 		{
// 			// g_data.hit.x = x;
// 			// g_data.hit.y = y;
// 			break ;
// 		}
// 		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, x * SIZE, y * SIZE, 0x00FFFFFF);
// 		i++;
// 	}
// 	dist = sqrt(pow(x - g_data.pos.x, 2) + pow(y - g_data.pos.y, 2));
// 	printf("////////////////////\ndist ray player: %f\n////////////////////////\n", dist);
// }
// static void	ray_30_right(void)
// {
// 	int		i;
// 	// double	x;
// 	// double	y;
// 	double	tmpdirx;
// 	double	tmpdiry;
// 	int		d;
// 	double dist;

// 	dist = 0.0;
// 	i = 0;
// 	d = 1;
// 	g_data.view.right_x = g_data.pos.x;
// 	g_data.view.right_y = g_data.pos.y;
// 	tmpdirx = g_data.dir.x * cos(d * 0.5) - g_data.dir.y * sin(d * 0.5);
// 	tmpdiry = g_data.dir.y * cos(d * 0.5) + g_data.dir.x * sin(d * 0.5);
// 	while (i < g_data.win.x * 2)
// 	{
// 		g_data.view.right_x += (tmpdirx * SPEED / 1000);
// 		g_data.view.right_y += (tmpdiry * SPEED / 1000);
// 		if (g_data.map.tab[(int)floor(g_data.view.right_y)][(int)floor(g_data.view.right_x)] == '1' || g_data.map.tab[(int)floor(g_data.view.right_y)][(int)floor(g_data.view.right_x)] == ' ')
// 		{
// 			break ;
// 		}
// 		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.view.right_x * SIZE, g_data.view.right_y * SIZE, 0x00FFFFFF);
// 		i++;
// 	}
// 	dist = sqrt(pow(g_data.view.right_x - g_data.pos.x, 2) + pow(g_data.view.right_y - g_data.pos.y, 2));
// 	printf("////////////////////\ndist right: %f\n////////////////////////\n", dist);
// }

// static void	ray_30_left(void)
// {
// 	int		i;
// 	// double	x;
// 	// double	y;
// 	double	tmpdirx;
// 	double	tmpdiry;
// 	int		d;
// 	double dist;

// 	dist = 0.0;
// 	i = 0;
// 	d = -1;
// 	g_data.view.left_x = g_data.pos.x;
// 	g_data.view.left_y = g_data.pos.y;
// 	tmpdirx = g_data.dir.x * cos(d * 0.5) - g_data.dir.y * sin(d * 0.5);
// 	tmpdiry = g_data.dir.y * cos(d * 0.5) + g_data.dir.x * sin(d * 0.5);
// 	while (i < g_data.win.x * 2)
// 	{
// 		g_data.view.left_x += (tmpdirx * SPEED / 1000);
// 		g_data.view.left_y += (tmpdiry * SPEED / 1000);
// 		if (g_data.map.tab[(int)floor(g_data.view.left_y)][(int)floor(g_data.view.left_x)] == '1' || g_data.map.tab[(int)floor(g_data.view.left_y)][(int)floor(g_data.view.left_x)] == ' ')
// 		{
// 			break ;
// 		}
// 		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.view.left_x * SIZE, g_data.view.left_y * SIZE, 0x00FFFFFF);
// 		i++;
// 	}
// 	dist = sqrt(pow(g_data.view.left_x - g_data.pos.x, 2) + pow(g_data.view.left_y - g_data.pos.y, 2));
// 	printf("////////////////////\ndist left: %f\n////////////////////////\n", dist);
// }

static void	others_ray(double d)
{
	double 	x;
	double 	y;
	double 	tmpx;
	double 	tmpy;
	int		j;
	double 	angle;
	int		side;

	angle = 0.0;
	// x = g_data.pos.x;
	// y = g_data.pos.y;
	tmpx = 0.0;
	tmpy = 0.0;
	j = 0;
	while (angle < 0.5)
	{
		x = g_data.pos.x;
		y = g_data.pos.y;
		tmpx = g_data.dir.x * cos(d * angle) - g_data.dir.y * sin(d * angle);
		tmpy = g_data.dir.y * cos(d * angle) + g_data.dir.x * sin(d * angle);
		while (j < g_data.win.x * 2)
		{
			x += (tmpx * SPEED / 1000);
			y += (tmpy * SPEED / 1000);
			if (g_data.map.tab[(int)floor(y)][(int)floor(x)] == '1' || g_data.map.tab[(int)floor(y)][(int)floor(x)] == ' ')
			{
				g_data.hit.x = x;
				g_data.hit.y = y;
				break;
			}
			// mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, x * SIZE, y * SIZE, 0x00FFFFFF);
		}
		side = which_side();
		g_data.dist.dist = sqrt(pow(x - g_data.pos.x, 2) + pow(y - g_data.pos.y, 2));
		// DDA ALGO
		draw_wall();
		angle += 0.005;
	}
}

static int which_side(void)
{
	if ((g_data.hit.y - floor(g_data.hit.y)) == 0)
	{
		if (g_data.pos.y < g_data.hit.y)
			return (SOUTH);
		else 
			return (NORTH);
	}
	if ((g_data.hit.x - floor(g_data.hit.x)) == 0)
	{
		if (g_data.pos.x < g_data.hit.x)
			return (EAST);
		else 
			return (WEST);
	}
	return (-1);
}

static void draw_wall(void)
{
	int	line_height;
	int	draw_start;
	int	draw_end;
	double x;
	double y;

	line_height = SIZE / g_data.dist.dist;
	draw_start = -line_height / 2 + SIZE / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = line_height / 2 + SIZE / 2;
	if (draw_end >= SIZE)
		draw_end = SIZE - 1;
	x = g_data.hit.x;
	y = g_data.hit.y;
	// double d = -1;
	while (draw_start <= draw_end * SIZE)
	{
		// while (x < x * SIZE)
		// {
		// 	while (y < y * SIZE)
		// 	{
				mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, x * SIZE, y * SIZE, 0x00FFFFFF);
				// y++;
			// }
			// y = g_data.hit.y;
			// x++;
		// }
		x = g_data.hit.x;
		y--;
		x--;
		
		// x += d * (g_data.dir.x * SPEED / 100);
		// y += d * (g_data.dir.y * SPEED / 100);
		draw_start++;
	}
}
// static void	ray(void)
// {
// 	double	angle;
// 	double	dist;

// 	if (g_data.ray.i < g_data.win.x)
// 	{
// 		angle = ((g_data.ray.i - (g_data.win.x / 2)) * 33 / (g_data.win.x / 2));
// 		angle = ft_deg_to_rad(angle);
// 		g_data.ray.x = g_data.dir.x * cos(angle) - g_data.dir.y * sin(angle);
// 		g_data.ray.y = g_data.dir.y * cos(angle) + g_data.dir.x * sin(angle);
// 		dist = hypot(g_data.ray.x, g_data.ray.y);
// 		g_data.ray.x /= dist;
// 		g_data.ray.y /= dist;
// 		g_data.ray.i++;
// 		mlx_pixel_put(g_data.mlx.ptr, g_data.win.ptr, g_data.ray.x * SIZE, g_data.ray.y * SIZE, 0x00FFFFFF);
// 	}
// }
