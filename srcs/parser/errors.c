/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 21:43:37 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/27 18:34:04 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		ft_errors_print_2(t_vars *vars)
{
	if (vars->parse.erorrs.flag_f)
		ft_putendl_fd("Error\ncolor_f", 1);
	if (vars->parse.erorrs.flag_c)
		ft_putendl_fd("Error\ncolor_c", 1);
	if (vars->parse.erorrs.flag_smbl)
		ft_putendl_fd("Error\ninvalid characters", 1);
	if (vars->parse.erorrs.flag_malloc_error == 1)
		ft_putendl_fd("Error\n malloc erorr", 1);
	if (vars->parse.erorrs.flag_invalid_file == 1)
		ft_putendl_fd("Error\ninvalid file", 1);
	if (vars->parse.erorrs.flag_invalid_arg == 1)
		ft_putendl_fd("Error\ninvalid arg", 1);
	if (vars->parse.erorrs.flag_empty_line == 0)
		ft_putendl_fd("Error\nno empty line", 1);
	if (vars->parse.erorrs.flag_invalid_map == 1)
		ft_putendl_fd("Error\ninvalid map", 1);
	if (vars->parse.erorrs.flag_gnl == 1)
		ft_putendl_fd("Error\ngnl return -1", 1);
}

static void		ft_errors_print(t_vars *vars)
{
	if (vars->parse.erorrs.flag_r)
		ft_putendl_fd("Error\nsize screen", 1);
	if (vars->parse.erorrs.flag_no)
		ft_putendl_fd("Error\ntexture 'NO'", 1);
	if (vars->parse.erorrs.flag_so)
		ft_putendl_fd("Error\ntexture 'SO'", 1);
	if (vars->parse.erorrs.flag_we)
		ft_putendl_fd("Error\ntexture 'WE'", 1);
	if (vars->parse.erorrs.flag_ea)
		ft_putendl_fd("Error\ntexture 'EA'", 1);
	if (vars->parse.erorrs.flag_s)
		ft_putendl_fd("Error\nsprite", 1);
	ft_errors_print_2(vars);
}

void			ft_free(t_vars *vars)
{
	if (vars->l_tx.tex_no.rl_pth != NULL)
		free(vars->l_tx.tex_no.rl_pth);
	if (vars->l_tx.tex_so.rl_pth != NULL)
		free(vars->l_tx.tex_so.rl_pth);
	if (vars->l_tx.tex_we.rl_pth != NULL)
		free(vars->l_tx.tex_we.rl_pth);
	if (vars->l_tx.tex_ea.rl_pth != NULL)
		free(vars->l_tx.tex_ea.rl_pth);
	if (vars->parse.map != NULL)
		free(vars->parse.map);
}

void			ft_errors(t_vars *vars)
{
	ft_errors_print(vars);
	ft_free(vars);
	exit(1);
}
