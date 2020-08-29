/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 10:24:19 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/27 17:29:31 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_check_empty_line(t_vars *vars, char *str, int i)
{
	if (vars->parse.tex_ea == 1 && vars->parse.tex_no == 1
	&& vars->parse.tex_so == 1 &&
	vars->parse.tex_we == 1 && vars->parse.count_color_c == 1
	&& vars->parse.count_color_f == 1 &&
	vars->parse.s == 1 && str[i] == '\0')
	{
		vars->parse.erorrs.flag_empty_line = 1;
		return (1);
	}
	return (0);
}

void	parse_parameter(t_vars *vars, char *str)
{
	int i;

	i = 0;
	vars->rgb.c_r = -1;
	vars->rgb.c_g = -1;
	vars->rgb.c_b = -1;
	vars->rgb.color = 1;
	vars->parse.erorrs.flag_smbl = 1;
	i = ft_space(str, i);
	if (ft_check_empty_line(vars, str, i) == 1)
	{
		vars->parse.erorrs.flag_smbl = 0;
		return ;
	}
	else if (str[i] == '\0')
		return ;
	else
		ft_parameter(vars, str, i);
}
