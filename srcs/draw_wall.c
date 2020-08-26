/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_wall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 18:38:35 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/26 12:15:40 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int		get_clr(t_vars *vars, int y, int flag)
{
	if (vars->flag == 1)
		return (*(unsigned int *)(vars->l_tx.tex_we.addr +
			((y + 1) * vars->l_tx.tex_we.length - (vars->y + 1) *
				(vars->l_tx.tex_we.bs_pxl / 8))));
	else if (flag == 2)
		return (*(unsigned int *)(vars->l_tx.tex_ea.addr +
			(y * vars->l_tx.tex_ea.length + vars->y *
				(vars->l_tx.tex_ea.bs_pxl / 8))));
	else if (flag == 3)
		return (*(unsigned int *)(vars->l_tx.tex_no.addr +
				(y * vars->l_tx.tex_no.length +
				vars->x * (vars->l_tx.tex_no.bs_pxl / 8))));
	else if (flag == 4)
	{
		return (*(unsigned int *)(vars->l_tx.tex_so.addr + ((y + 1) *
		vars->l_tx.tex_so.length -
		(vars->x + 1) * (vars->l_tx.tex_so.bs_pxl / 8))));
	}
	return (0);
}

static void		paint_wall(t_vars *vars, int start, int end, int screen_x)
{
	int		tex_y;
	int		color;
	int		first_point;
	double	h_koef;

	tex_y = 0;
	color = 0;
	first_point = start;
	h_koef = 64.0 / (end - start);
	if (start < 0)
		start = 0;
	while (start < end && start < vars->window.height
	&& screen_x < vars->window.width)
	{
		tex_y = (int)((start - first_point) * h_koef);
		color = get_clr(vars, tex_y, vars->flag);
		color = get_clr(vars, tex_y, vars->flag);
		color = get_clr(vars, tex_y, vars->flag);
		color = get_clr(vars, tex_y, vars->flag);
		my_mlx_pixel_put(vars, screen_x, start++, color);
	}
}

void			ft_draw_wall(t_vars *vars, double len, int screen_x,
double angle_ray)
{
	int start;
	int end;

	len = len * cos(vars->player.angle - angle_ray);
	start = vars->window.height / 2 - (vars->window.height / len * 64) / 2;
	end = vars->window.height / 2 + (vars->window.height / len * 64) / 2;
	paint_wall(vars, start, end, screen_x);
}
