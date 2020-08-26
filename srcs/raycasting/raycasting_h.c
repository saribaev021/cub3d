/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_h.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 13:14:26 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/26 19:52:08 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static double	ft_hlen_top(t_vars *vars, double angle)
{
	double hx;
	double hy;

	hx = 0;
	hy = 0;
	hy = ((unsigned int)(vars->player.y >> SCALE) << SCALE) - 0.00000000001;
	hx = vars->player.x - ((vars->player.y - hy) / tan(angle));
	while (((unsigned int)hy >> SCALE) < (unsigned int)vars->map.height &&
	((unsigned int)hx >> SCALE) < (unsigned int)vars->map.width &&
	vars->map.map[((unsigned int)hy >> SCALE)][(
		(unsigned int)hx >> SCALE)] != '1')
	{
		hy -= WIDTH;
		hx -= WIDTH / tan(angle);
	}
	vars->x = (hx - ((int)(hx / WIDTH) * WIDTH - 0.00000000001));
	return (sqrt(pow(vars->player.x - hx, 2) + pow(vars->player.y - hy, 2)));
}

static double	ft_hlen_bottom(t_vars *vars, double angle)
{
	double hx;
	double hy;

	hx = 0;
	hy = 0;
	hy = ((unsigned int)(vars->player.y >> SCALE) << SCALE) + WIDTH;
	hx = vars->player.x - ((vars->player.y - hy) / tan(angle));
	while (((unsigned int)hy >> SCALE) < (unsigned int)vars->map.height &&
	((unsigned int)hx >> SCALE) < (unsigned int)vars->map.width &&
	vars->map.map[((unsigned int)hy >> SCALE)][(
		(unsigned int)hx >> SCALE)] != '1')
	{
		hy += WIDTH;
		hx += WIDTH / tan(angle);
	}
	vars->x = (hx - ((int)(hx / WIDTH) * WIDTH - 0.00000000001));
	return (sqrt(pow(vars->player.x - hx, 2) + pow(vars->player.y - hy, 2)));
}

double			ft_hlen(t_vars *vars, double angle)
{
	if ((angle > 3 * M_PI_2 && angle < 2 * M_PI) ||
	(angle < 3 * M_PI_2 && angle > M_PI))
		return (ft_hlen_top(vars, angle));
	if ((angle > 0 && angle < M_PI_2) || (angle > M_PI_2 && angle < M_PI))
		return (ft_hlen_bottom(vars, angle));
	if (angle == 3 * M_PI_2)
		return (ft_hlen_up(vars));
	if (angle == 0 || angle == M_PI * 2)
		return (ft_hlen_right(vars));
	if (angle == M_PI_2)
		return (ft_hlen_down(vars));
	if (angle == M_PI)
		return (ft_hlen_left(vars));
	return (INFINITY);
}
