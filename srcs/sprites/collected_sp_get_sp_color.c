/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collected_sp_get_sp_color.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 23:57:08 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/26 11:13:57 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		get_cl(t_vars *vars, int x, int y)
{
	return (*(unsigned int*)(vars->sp.addr + (y * vars->sp.line_length +
	x * (vars->sp.bits_per_pixel / 8))));
}

void	colloceted_sp(t_vars *vars)
{
	int i;

	i = 0;
	if (vars->map.map[(unsigned int)vars->player.y >> SCALE][(
		unsigned int)(vars->player.x) >> SCALE] == '2')
	{
		vars->map.map[(unsigned int)vars->player.y >> SCALE][(
			(unsigned int)vars->player.x >> SCALE)] = '0';
		i++;
	}
	if (i > 0 && vars->count_sprite > 0)
	{
		ft_clear_list(&vars->sp_cor);
		vars->count_sprite--;
		vars->collected_sprites++;
	}
}
