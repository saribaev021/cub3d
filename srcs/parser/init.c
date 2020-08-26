/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 22:17:14 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/26 15:32:57 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		init2(t_vars *vars)
{
	vars->parse.erorrs.flag_malloc_error = 0;
	vars->parse.erorrs.flag_gnl = 0;
	vars->window.width = 0;
	vars->window.height = 0;
	vars->collected_sprites = 0;
	vars->parse.erorrs.flag_invalid_arg = 0;
	vars->parse.erorrs.flag_num = 0;
	vars->l_tx.tex_no.rl_pth = NULL;
	vars->l_tx.tex_so.rl_pth = NULL;
	vars->l_tx.tex_we.rl_pth = NULL;
	vars->l_tx.tex_ea.rl_pth = NULL;
	vars->sp.rl_pth = NULL;
	vars->parse.map = NULL;
	vars->parse.erorrs.flag_empty_line = 0;
	vars->mlx.mlx = mlx_init();
	mlx_get_screen_size(vars->mlx.mlx,
	&vars->window.max_w, &vars->window.max_h);
}

void			init(t_vars *vars)
{
	vars->parse.count_color_c = 0;
	vars->parse.count_color_f = 0;
	vars->parse.tex_no = 0;
	vars->parse.tex_so = 0;
	vars->parse.tex_we = 0;
	vars->parse.tex_ea = 0;
	vars->parse.s = 0;
	vars->parse.count_r = 0;
	vars->parse.erorrs.flag_r = 0;
	vars->parse.erorrs.flag_s = 0;
	vars->parse.erorrs.flag_so = 0;
	vars->parse.erorrs.flag_no = 0;
	vars->parse.erorrs.flag_we = 0;
	vars->parse.erorrs.flag_ea = 0;
	vars->parse.erorrs.flag_c = 0;
	vars->parse.erorrs.flag_f = 0;
	vars->parse.erorrs.flag_smbl = 0;
	init2(vars);
}
