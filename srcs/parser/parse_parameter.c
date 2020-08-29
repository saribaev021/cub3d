/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_parameter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 13:40:24 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/27 18:13:51 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		get_rgb(t_vars *vars, int flag)
{
	if (flag == 1)
	{
		vars->rgb.color_f = (0 << 24 | vars->rgb.c_r << 16 |
			vars->rgb.c_g << 8 | vars->rgb.c_b << 0);
		vars->parse.count_color_f++;
	}
	else if (flag == 2)
	{
		vars->rgb.color_c = (0 << 24 | vars->rgb.c_r << 16 |
			vars->rgb.c_g << 8 | vars->rgb.c_b << 0);
		vars->parse.count_color_c++;
	}
}

static	void	get_w_h(t_vars *vars, char *str, int i)
{
	int k;
	int l;

	l = i;
	k = ft_space(str, i);
	if (str[k - 1] == ' ')
	{
		i = ft_skip_digit(str, k);
		if (str[i] == ' ')
		{
			l = ft_space(str, i);
			i = ft_skip_digit(str, l);
			i = ft_space(str, i);
			if (str[i] == '\0')
			{
				vars->window.width = ft_atoi(str + k);
				vars->window.height = ft_atoi(str + l);
				vars->parse.count_r++;
				vars->parse.erorrs.flag_smbl = 0;
			}
		}
	}
}

static	void	get_path_tex(t_vars *vars, char *str, int i, int flag)
{
	if (str[i] == ' ')
	{
		if (flag == 1)
			if (vars->parse.tex_no++ < 0 || (vars->l_tx.tex_no.rl_pth =
			ft_strtrim(str + i, " ")) == NULL)
				vars->parse.erorrs.flag_malloc_error = 1;
		if (flag == 2)
			if (vars->parse.tex_so++ < 0 || (vars->l_tx.tex_so.rl_pth =
			ft_strtrim(str + i, " ")) == NULL)
				vars->parse.erorrs.flag_malloc_error = 1;
		if (flag == 3)
			if (vars->parse.tex_we++ < 0 || (vars->l_tx.tex_we.rl_pth =
			ft_strtrim(str + i, " ")) == NULL)
				vars->parse.erorrs.flag_malloc_error = 1;
		if (flag == 4)
			if (vars->parse.tex_ea++ < 0 || (vars->l_tx.tex_ea.rl_pth =
			ft_strtrim(str + i, " ")) == NULL)
				vars->parse.erorrs.flag_malloc_error = 1;
		if (flag == 5)
			if (vars->parse.s++ < 0 || (vars->sp.rl_pth =
			ft_strtrim(str + i, " ")) == NULL)
				vars->parse.erorrs.flag_malloc_error = 1;
		vars->parse.erorrs.flag_smbl = 0;
	}
}

static	void	get_color(t_vars *vars, char *str, int i, int flag)
{
	int k;

	k = i;
	if (vars->rgb.color == 1)
		k = ft_space(str, i);
	i = ft_skip_digit(str, k);
	if (str[i] == ',' && vars->rgb.color == 1 && ft_isdigit(str[i - 1]) == 1)
		vars->rgb.c_r = ft_atoi(str + k);
	if (str[i] == ',' && vars->rgb.color == 2 && ft_isdigit(str[i - 1]) == 1)
		vars->rgb.c_g = ft_atoi(str + k);
	if (str[i] == '\0' && vars->rgb.color == 3 && ft_isdigit(str[i - 1]) == 1)
		vars->rgb.c_b = ft_atoi(str + k);
	if (str[i] == ',')
	{
		vars->rgb.color++;
		get_color(vars, str, i + 1, flag);
		return ;
	}
	if (str[i] == '\0' && vars->rgb.c_r >= 0 && vars->rgb.c_r <= 255
	&& vars->rgb.c_g >= 0 && vars->rgb.c_g <= 255 &&
	vars->rgb.c_b >= 0 && vars->rgb.c_b <= 255 && vars->rgb.color == 3)
	{
		get_rgb(vars, flag);
		vars->parse.erorrs.flag_smbl = 0;
	}
}

void			ft_parameter(t_vars *vars, char *str, int i)
{
	if (str[i] == 'R')
		get_w_h(vars, str, i + 1);
	else if (str[i] == 'N' && str[i + 1] == 'O')
		get_path_tex(vars, str, i + 2, 1);
	else if (str[i] == 'S' && str[i + 1] == 'O')
		get_path_tex(vars, str, i + 2, 2);
	else if (str[i] == 'W' && str[i + 1] == 'E')
		get_path_tex(vars, str, i + 2, 3);
	else if (str[i] == 'E' && str[i + 1] == 'A')
		get_path_tex(vars, str, i + 2, 4);
	else if (str[i] == 'S')
		get_path_tex(vars, str, i + 2, 5);
	else if (str[i] == 'F' && str[i + 1] == ' ')
		get_color(vars, str, i + 1, 1);
	else if (str[i] == 'C' && str[i + 1] == ' ')
		get_color(vars, str, i + 1, 2);
	if (vars->parse.erorrs.flag_smbl == 1 ||
	vars->parse.erorrs.flag_malloc_error == 1)
		ft_errors(vars);
}
