/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 11:29:37 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/26 19:31:34 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	ft_vlen_right(t_vars *vars, double angle)
{
	double vx;
	double vy;

	vx = 0;
	vy = 0;
	vx = ((unsigned int)(vars->player.x >> SCALE) << SCALE) + WIDTH;
	vy = vars->player.y - ((vars->player.x - vx) * tan(angle));
	while (((unsigned int)vy >> SCALE) < (unsigned int)vars->map.height &&
	((unsigned int)vx >> SCALE) < (unsigned int)vars->map.width &&
	vars->map.map[((unsigned int)vy >> SCALE)][(
		(unsigned int)vx >> SCALE)] != '1')
	{
		vx += WIDTH;
		vy += WIDTH * tan(angle);
	}
	vars->y = (vy - ((int)(vy / WIDTH) * WIDTH - 0.00000000001));
	return (sqrt(pow(vars->player.x - vx, 2) + pow(vars->player.y - vy, 2)));
}

double	ft_vlen_left(t_vars *vars, double angle)
{
	double vx;
	double vy;

	vx = 0;
	vy = 0;
	vx = ((unsigned int)(vars->player.x >> SCALE) << SCALE) - 0.00000000001;
	vy = vars->player.y - ((vars->player.x - vx) * tan(angle));
	while (((unsigned int)vy >> SCALE) < (unsigned int)vars->map.height &&
	((unsigned int)vx >> SCALE) < (unsigned int)vars->map.width &&
	vars->map.map[((unsigned int)vy >> SCALE)][(
		(unsigned int)vx >> SCALE)] != '1')
	{
		vx -= WIDTH;
		vy -= WIDTH * tan(angle);
	}
	vars->y = (vy - ((int)(vy / WIDTH) * WIDTH - 0.00000000001));
	return (sqrt(pow(vars->player.x - vx, 2) + pow(vars->player.y - vy, 2)));
}

double	ft_vlen(t_vars *vars, double angle)
{
	if ((angle > 3 * M_PI_2 && angle < 2 * M_PI) ||
	(angle > 0 && angle < M_PI_2))
		return (ft_vlen_right(vars, angle));
	if ((angle > M_PI_2 && angle < M_PI) ||
	(angle < 3 * M_PI_2 && angle > M_PI))
		return (ft_vlen_left(vars, angle));
	return (INFINITY);
}

double	ft_raycasting(t_vars *vars, double angle)
{
	double vlen;
	double hlen;

	angle += angle < 0 ? 2 * M_PI : 0;
	angle -= angle > 2 * M_PI ? 2 * M_PI : 0;
	vars->angle = angle;
	vlen = ft_vlen(vars, angle);
	hlen = ft_hlen(vars, angle);
	if (vlen < hlen)
	{
		if (angle > M_PI_2 && angle < 3 * M_PI_2)
			vars->flag = 1;
		else
			vars->flag = 2;
	}
	else
	{
		if (angle > M_PI && angle < M_PI * 2)
			vars->flag = 3;
		else
			vars->flag = 4;
	}
	if (hlen < vlen)
		return (hlen);
	return (vlen);
}
