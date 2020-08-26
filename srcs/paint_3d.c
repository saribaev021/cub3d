/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 21:27:23 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/26 12:21:17 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		ft_ceiling(t_vars *vars)
{
	int l;
	int x;

	x = 0;
	l = 0;
	while (++l < vars->window.height / 2)
	{
		x = -1;
		while (++x < vars->window.width)
			my_mlx_pixel_put(vars, x, l, vars->rgb.color_c);
	}
	l = vars->window.height / 2 - 1;
	x = 0;
	while (++l < vars->window.height && l > 0)
	{
		x = -1;
		while (++x < vars->window.width)
			my_mlx_pixel_put(vars, x, l, vars->rgb.color_f);
	}
}

static void		ft_tracer(t_vars *vars)
{
	int		x;
	double	step;
	double	start_angel;
	double	end_angel;
	double	count_ray[vars->window.width];

	step = M_PI / (3.0 * vars->window.width);
	start_angel = vars->player.angle - M_PI / 6;
	end_angel = vars->player.angle + M_PI / 6;
	vars->flag = 0;
	x = 0;
	ft_ceiling(vars);
	while (start_angel < end_angel)
	{
		vars->player.ray = ft_raycasting(vars, start_angel);
		ft_draw_wall(vars, vars->player.ray, x, start_angel);
		count_ray[x++] = vars->player.ray;
		start_angel += step;
	}
	ft_sprite(vars, count_ray);
}

void			paint_3d(t_vars *vars)
{
	ft_tracer(vars);
	if (vars->window.width > 100 && vars->window.height > 100)
	{
		draw_map(vars, 0, 0);
		create_dout(vars, vars->player.x >> 2u, vars->player.y >> 2u, 0xffffff);
	}
}

void			start(t_vars *vars, int fd, int argc, char **argv)
{
	get_file(vars, fd);
	player_dir(vars);
	vars->window.width = vars->window.width >
	vars->window.max_w ? vars->window.max_w : vars->window.width;
	vars->window.height = vars->window.height >
	vars->window.max_h ? vars->window.max_h : vars->window.height;
	vars->mlx.win = mlx_new_window(vars->mlx.mlx,
	vars->window.width, vars->window.height, "CUB3D");
	get_sprite(vars);
	create_image(vars);
	paint_3d(vars);
	if (argc == 3)
	{
		if (ft_strncmp("--save", argv[2], 6) == 0)
			screenshot(vars);
		else
		{
			vars->parse.erorrs.flag_invalid_arg = 1;
			ft_errors(vars);
		}
		exit(0);
	}
}
