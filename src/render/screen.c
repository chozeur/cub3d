/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbrebion <tbrebion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:51:47 by tbrebion          #+#    #+#             */
/*   Updated: 2022/09/27 11:56:21 by tbrebion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ray_ver(void)
{
	double	x;
	double	y;

	x = floor(g_data.pos.x) + g_data.ray.v;
	y = g_data.pos.y + (x - g_data.pos.x) * (g_data.ray.y / g_data.ray.x);
	while ((int)floor(y) > 0 && (int)floor(y) < 1000)
	{
		if ((int)floor(y) > g_data.map.h || \
		(int)(x - 1 + g_data.ray.v) > g_data.map.w)
			break ;
		if (g_data.map.tab[(int)floor(y)][(int)(x - 1 + g_data.ray.v)] == '1'\
		|| g_data.map.tab[(int)floor(y)][(int)(x - 1 + g_data.ray.v)] == ' ')
		{
			g_data.hit.x = x;
			g_data.hit.y = y;
			g_data.hit.d = hypot(x - g_data.pos.x, y - g_data.pos.y);
			g_data.hit.side = which_side();
			return ;
		}
		x += (2 * g_data.ray.v - 1);
		y += (2 * g_data.ray.v - 1) * g_data.ray.y / g_data.ray.x;
	}
	g_data.hit.x = g_data.pos.x;
	g_data.hit.y = g_data.pos.y;
	g_data.hit.d = 10000000;
}

void	ray_hor(void)
{
	double	x;
	double	y;

	y = floor(g_data.pos.y) + g_data.ray.w;
	x = g_data.pos.x + (y - g_data.pos.y) * (g_data.ray.x / g_data.ray.y);
	while ((int)floor(x) > 0 && (int)floor(x) < 1000)
	{
		if ((int)(y - 1 + g_data.ray.w) > g_data.map.h || \
		(int)floor(x) > g_data.map.w)
			break ;
		if (g_data.map.tab[(int)(y - 1 + g_data.ray.w)][(int)floor(x)] == '1' \
		|| g_data.map.tab[(int)(y - 1 + g_data.ray.w)][(int)floor(x)] == ' ')
		{
			if (g_data.hit.d > hypot(x - g_data.pos.x, y - g_data.pos.y))
			{
				g_data.hit.x = x;
				g_data.hit.y = y;
				g_data.hit.d = hypot(x - g_data.pos.x, y - g_data.pos.y);
				g_data.hit.side = which_side();
			}
			return ;
		}
		y += (2 * g_data.ray.w - 1);
		x += (2 * g_data.ray.w - 1) * g_data.ray.x / g_data.ray.y;
	}
}

void	ft_dir(void)
{
	if (g_data.ray.x >= 0)
		g_data.ray.v = 1;
	else
		g_data.ray.v = 0;
	if (g_data.ray.y >= 0)
		g_data.ray.w = 1;
	else
		g_data.ray.w = 0;
}

int	which_side(void)
{
	static int	tmp_side = 0;

	if (fabs((int)round(g_data.hit.y) - g_data.hit.y) \
	< fabs((int)round(g_data.hit.x) - g_data.hit.x))
	{
		if (g_data.pos.y > g_data.hit.y)
			tmp_side = NORTH;
		if (g_data.pos.y < g_data.hit.y)
			tmp_side = SOUTH;
	}
	else if (fabs((int)round(g_data.hit.y) - g_data.hit.y) \
	> fabs((int)round(g_data.hit.x) - g_data.hit.x))
	{
		if (g_data.pos.x > g_data.hit.x)
			tmp_side = WEST;
		if (g_data.pos.x < g_data.hit.x)
			tmp_side = EAST;
	}
	return (tmp_side);
}

void	ray_rotate(void)
{
	double	angle;
	double	dist;

	angle = ((double)g_data.ray.i - (W / 2)) * 33 / (W / 2);
	angle = ft_deg_to_rad(angle);
	g_data.ray.x = g_data.dir.x * cos(angle) - g_data.dir.y * sin(angle);
	g_data.ray.y = g_data.dir.y * cos(angle) + g_data.dir.x * sin(angle);
	dist = hypot(g_data.ray.x, g_data.ray.y);
	g_data.ray.x /= dist;
	g_data.ray.y /= dist;
}
