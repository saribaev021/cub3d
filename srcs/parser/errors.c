/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 21:43:37 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/26 10:20:17 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		ft_errors_print_2(t_vars *vars)
{
	if (vars->parse.erorrs.flag_f)
		ft_putendl_fd("error color_f", 1);
	if (vars->parse.erorrs.flag_c)
		ft_putendl_fd("error color_c", 1);
	if (vars->parse.erorrs.flag_smbl)
		ft_putendl_fd("error\n invalid characters", 1);
	if (vars->parse.erorrs.flag_malloc_error == 1)
		ft_putendl_fd("error\n malloc erorr", 1);
	if (vars->parse.erorrs.flag_invalid_file == 1)
		ft_putendl_fd("error\ninvalid file", 1);
	if (vars->parse.erorrs.flag_invalid_arg == 1)
		ft_putendl_fd("error\ninvalid arg", 1);
	if (vars->parse.erorrs.flag_empty_line == 0)
		ft_putendl_fd("error\nno empty line", 1);
	if (vars->parse.erorrs.flag_invalid_map == 1)
		ft_putendl_fd("error\ninvalid map", 1);
	if (vars->parse.erorrs.flag_gnl == 1)
		ft_putendl_fd("error\n gnl return -1", 1);
}

static void		ft_errors_print(t_vars *vars)
{
	if (vars->parse.erorrs.flag_r)
		ft_putendl_fd("error size screen", 1);
	if (vars->parse.erorrs.flag_no)
		ft_putendl_fd("error texture 'NO'", 1);
	if (vars->parse.erorrs.flag_so)
		ft_putendl_fd("error texture 'SO'", 1);
	if (vars->parse.erorrs.flag_we)
		ft_putendl_fd("error texture 'WE'", 1);
	if (vars->parse.erorrs.flag_ea)
		ft_putendl_fd("error texture 'EA'", 1);
	if (vars->parse.erorrs.flag_s)
		ft_putendl_fd("error\nsprite", 1);
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
