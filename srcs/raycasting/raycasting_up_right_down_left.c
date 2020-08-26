/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_up_right_down_left.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 12:46:04 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/26 19:51:33 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	ft_hlen_up(t_vars *vars)
{
	double hx;
	double hy;

	hx = 0;
	hy = 0;
	hy = ((unsigned int)(vars->player.y >> SCALE) << SCALE) - 0.00000000001;
	hx = vars->player.x;
	while (((unsigned int)hy >> SCALE) < (unsigned int)vars->map.height &&
	((unsigned int)hx >> SCALE) < (unsigned int)vars->map.width &&
	vars->map.map[((unsigned int)hy >>
	SCALE)][((unsigned int)hx >> SCALE)] != '1')
		hy -= WIDTH;
	vars->y = (hy - ((int)(hy / WIDTH) * WIDTH - 0.00000000001));
	return (sqrt(pow(vars->player.x - hx, 2) + pow(vars->player.y - hy, 2)));
}

double	ft_hlen_right(t_vars *vars)
{
	double hx;
	double hy;

	hx = 0;
	hy = 0;
	hx = ((unsigned int)(vars->player.x >> SCALE) << SCALE) + WIDTH;
	hy = (unsigned int)vars->player.y >> SCALE;
	while (((unsigned int)hy >> SCALE) < (unsigned int)vars->map.height &&
	((unsigned int)hx >> SCALE) < (unsigned int)vars->map.width &&
	vars->map.map[((unsigned int)hy >>
	SCALE)][((unsigned int)hx >> SCALE)] != '1')
		hx += WIDTH;
	vars->x = (hx - ((int)(hx / WIDTH) * WIDTH - 0.00000000001));
	return (sqrt(pow(vars->player.x - hx, 2) + pow(vars->player.y - hy, 2)));
}

double	ft_hlen_down(t_vars *vars)
{
	double hx;
	double hy;

	hx = 0;
	hy = 0;
	hy = ((unsigned int)(vars->player.y >> SCALE) << SCALE) + WIDTH;
	hx = vars->player.x;
	while (((unsigned int)hy >> SCALE) < (unsigned int)vars->map.height &&
	((unsigned int)hx >> SCALE) < (unsigned int)vars->map.width &&
	vars->map.map[((unsigned int)hy >>
	SCALE)][((unsigned int)hx >> SCALE)] != '1')
		hy += WIDTH;
	vars->y = (hy - ((int)(hy / WIDTH) * WIDTH - 0.00000000001));
	return (sqrt(pow(vars->player.x - hx, 2) + pow(vars->player.y - hy, 2)));
}

double	ft_hlen_left(t_vars *vars)
{
	double hx;
	double hy;

	hx = 0;
	hy = 0;
	hx = ((unsigned int)(vars->player.x >> SCALE) << SCALE) - 0.00000000001;
	hy = (unsigned int)vars->player.y;
	while (((unsigned int)hy >> SCALE) < (unsigned int)vars->map.height &&
	((unsigned int)hx >> SCALE) < (unsigned int)vars->map.width &&
	vars->map.map[((unsigned int)hy >>
	SCALE)][((unsigned int)hx >> SCALE)] != '1')
		hx -= WIDTH;
	vars->x = (hx - ((int)(hx / WIDTH) * WIDTH - 0.00000000001));
	return (sqrt(pow(vars->player.x - hx, 2) + pow(vars->player.y - hy, 2)));
}
