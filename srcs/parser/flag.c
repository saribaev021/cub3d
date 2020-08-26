/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 22:22:57 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/26 14:41:15 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int		check_path(t_vars *vars)
{
	if ((vars->l_tx.tex_no.tex = mlx_xpm_file_to_image(vars->mlx.mlx,
		vars->l_tx.tex_no.rl_pth,
			&vars->l_tx.tex_no.img_wdh, &vars->l_tx.tex_no.img_ht)) == NULL)
		vars->parse.erorrs.flag_invalid_file = 1;
	if ((vars->l_tx.tex_so.tex = mlx_xpm_file_to_image(vars->mlx.mlx,
		vars->l_tx.tex_so.rl_pth,
			&vars->l_tx.tex_so.img_wdh, &vars->l_tx.tex_so.img_ht)) == NULL)
		vars->parse.erorrs.flag_invalid_file = 1;
	if ((vars->l_tx.tex_we.tex = mlx_xpm_file_to_image(vars->mlx.mlx,
		vars->l_tx.tex_we.rl_pth,
			&vars->l_tx.tex_we.img_wdh, &vars->l_tx.tex_we.img_ht)) == NULL)
		vars->parse.erorrs.flag_invalid_file = 1;
	if ((vars->l_tx.tex_ea.tex = mlx_xpm_file_to_image(vars->mlx.mlx,
		vars->l_tx.tex_ea.rl_pth,
			&vars->l_tx.tex_ea.img_wdh, &vars->l_tx.tex_ea.img_ht)) == NULL)
		vars->parse.erorrs.flag_invalid_file = 1;
	if ((vars->sp.tex = mlx_xpm_file_to_image(vars->mlx.mlx,
		vars->sp.rl_pth,
			&vars->sp.img_width, &vars->sp.img_height)) == NULL)
		vars->parse.erorrs.flag_invalid_file = 1;
	if (vars->parse.erorrs.flag_invalid_file == 1)
		return (1);
	return (0);
}

void			check_flag(t_vars *vars)
{
	if (vars->parse.count_color_c != 1 || vars->rgb.color_c < 0)
		vars->parse.erorrs.flag_c = 1;
	if (vars->parse.count_color_f != 1 || vars->rgb.color_f < 0)
		vars->parse.erorrs.flag_f = 1;
	if (vars->parse.count_r != 1 ||
	vars->window.width <= 0 || vars->window.height <= 0)
		vars->parse.erorrs.flag_r = 1;
	if (vars->parse.s != 1)
		vars->parse.erorrs.flag_s = 1;
	if (vars->parse.tex_no != 1)
		vars->parse.erorrs.flag_no = 1;
	if (vars->parse.tex_so != 1)
		vars->parse.erorrs.flag_so = 1;
	if (vars->parse.tex_we != 1)
		vars->parse.erorrs.flag_we = 1;
	if (vars->parse.tex_ea != 1)
		vars->parse.erorrs.flag_r = 1;
	if (vars->parse.erorrs.flag_c || vars->parse.erorrs.flag_f ||
	vars->parse.erorrs.flag_r || vars->parse.erorrs.flag_no ||
		vars->parse.erorrs.flag_so || vars->parse.erorrs.flag_we
		|| vars->parse.erorrs.flag_ea || vars->parse.erorrs.flag_s)
		ft_errors(vars);
	if (check_path(vars))
		ft_errors(vars);
}
