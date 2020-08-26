/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 20:35:59 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/26 00:17:26 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_image(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx.mlx, vars->window.width,
	vars->window.height);
	vars->img.addr = mlx_get_data_addr(vars->img.img,
	&vars->img.bits_per_pixel,
	&vars->img.line_length, &vars->img.endian);
	vars->l_tx.tex_no.addr = mlx_get_data_addr(vars->l_tx.tex_no.tex,
	&vars->l_tx.tex_no.bs_pxl,
	&vars->l_tx.tex_no.length, &vars->l_tx.tex_no.endian);
	vars->l_tx.tex_so.addr = mlx_get_data_addr(vars->l_tx.tex_so.tex,
	&vars->l_tx.tex_so.bs_pxl,
	&vars->l_tx.tex_so.length, &vars->l_tx.tex_so.endian);
	vars->l_tx.tex_we.addr = mlx_get_data_addr(vars->l_tx.tex_we.tex,
	&vars->l_tx.tex_we.bs_pxl,
	&vars->l_tx.tex_we.length, &vars->l_tx.tex_we.endian);
	vars->l_tx.tex_ea.addr = mlx_get_data_addr(vars->l_tx.tex_ea.tex,
	&vars->l_tx.tex_ea.bs_pxl,
	&vars->l_tx.tex_ea.length, &vars->l_tx.tex_ea.endian);
	vars->sp.addr = mlx_get_data_addr(vars->sp.tex,
	&vars->sp.bits_per_pixel,
	&vars->sp.line_length, &vars->sp.endian);
}

void	my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char	*dst;

	dst = vars->img.addr + (y * vars->img.line_length +
	x * (vars->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
