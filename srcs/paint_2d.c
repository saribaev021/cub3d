/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_2D.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 20:58:16 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/25 23:43:37 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map(t_vars *vars, int x, int y)
{
	while (vars->map.map[y >> 4u] != '\0')
	{
		x = 0;
		while (vars->map.map[y >> 4u][x >> 4u] != '\0')
		{
			if (vars->map.map[y >> 4u][x >> 4u] == '1')
				my_mlx_pixel_put(vars, x, y, 0x00ff00);
			if (vars->map.map[y >> 4u][x >> 4u] == '0' ||
			vars->map.map[y >> 4u][x >> 4u] == 'N' ||
			vars->map.map[y >> 4u][x >> 4u] == 'W' ||
			vars->map.map[y >> 4u][x >> 4u] == 'E' ||
			vars->map.map[y >> 4u][x >> 4u] == 'S')
				my_mlx_pixel_put(vars, x, y, 0xff0000);
			if (vars->map.map[y >> 4u][x >> 4u] == '2')
				my_mlx_pixel_put(vars, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	create_dout(t_vars *vars, int x, int y, int color)
{
	double	tmp_x;
	double	tmp_y;
	int		k;

	k = -1;
	tmp_y = y - 6;
	tmp_x = x - 5;
	while (++tmp_y < (y + 5) && x < vars->window.width && y <
	vars->window.height && x >= 5 && y >= 5)
	{
		tmp_x = x - 5;
		while (tmp_x < (x + 5))
			my_mlx_pixel_put(vars, tmp_x++, tmp_y, color);
	}
	while (++k <= 10)
		my_mlx_pixel_put(vars, x + k * cos(vars->player.angle), y +
		k * sin(vars->player.angle), 0xffffff);
}
