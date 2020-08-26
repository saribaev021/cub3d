/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 23:47:16 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/26 12:04:24 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_forward(t_vars *vars)
{
	double	y;
	double	x;
	int		i;

	i = 0;
	x = vars->player.x;
	y = vars->player.y;
	if (vars->map.map[(unsigned int)(y + SPEED * sin(vars->player.angle)) >>
	SCALE][(unsigned int)x >> SCALE] != '1')
		vars->player.y += SPEED * sin(vars->player.angle);
	if (vars->map.map[(unsigned int)y >> SCALE]
	[(unsigned int)(x + SPEED * cos(vars->player.angle)) >> SCALE] != '1')
		vars->player.x += SPEED * cos(vars->player.angle);
	colloceted_sp(vars);
}

void	ft_back(t_vars *vars)
{
	double y;
	double x;

	x = vars->player.x;
	y = vars->player.y;
	if (vars->map.map[(unsigned int)(y - SPEED * sin(vars->player.angle)) >>
	SCALE][(unsigned int)x >> SCALE] != '1')
		vars->player.y -= SPEED * sin(vars->player.angle);
	if (vars->map.map[(unsigned int)y >> SCALE][(unsigned int)(x -
	SPEED * cos(vars->player.angle)) >> SCALE] != '1')
		vars->player.x -= SPEED * cos(vars->player.angle);
	colloceted_sp(vars);
}

void	ft_left(t_vars *vars, int keycode)
{
	double y;
	double x;

	x = vars->player.x;
	y = vars->player.y;
	if (keycode == LEFT_ARROW)
	{
		vars->player.angle -= 0.1;
		if (vars->player.angle <= 0)
			vars->player.angle += 2 * M_PI;
		return ;
	}
	if (vars->map.map[(unsigned int)(y - SPEED * cos(vars->player.angle)) >>
	SCALE][(unsigned int)x >> SCALE] != '1')
		vars->player.y -= SPEED * cos(vars->player.angle);
	if (vars->map.map[(unsigned int)y >> SCALE][(unsigned int)(x +
	SPEED * sin(vars->player.angle)) >> SCALE] != '1')
		vars->player.x += SPEED * sin(vars->player.angle);
	colloceted_sp(vars);
}

void	ft_right(t_vars *vars, int keycode)
{
	double y;
	double x;

	x = vars->player.x;
	y = vars->player.y;
	if (keycode == RIGHT_ARROW)
	{
		vars->player.angle += 0.1;
		if (vars->player.angle >= 2 * M_PI)
			vars->player.angle -= 2 * M_PI;
		return ;
	}
	if (vars->map.map[(unsigned int)(y + (SPEED) *
	cos(vars->player.angle)) >> SCALE][(unsigned int)x >> SCALE] != '1')
		vars->player.y += SPEED * cos(vars->player.angle);
	if (vars->map.map[(unsigned int)y >> SCALE][(unsigned int)(x -
	(SPEED) * sin(vars->player.angle)) >> SCALE] != '1')
		vars->player.x -= SPEED * sin(vars->player.angle);
	colloceted_sp(vars);
}

void	player_dir(t_vars *vars)
{
	if (vars->map.map[(unsigned int)(vars->player.y >>
	SCALE)][(unsigned int)(vars->player.x >> SCALE)] == 'N')
		vars->player.angle = 3 * M_PI_2;
	if (vars->map.map[(unsigned int)(vars->player.y >>
	SCALE)][(unsigned int)(vars->player.x >> SCALE)] == 'S')
		vars->player.angle = M_PI_2;
	if (vars->map.map[(unsigned int)(vars->player.y >>
	SCALE)][(unsigned int)(vars->player.x >> SCALE)] == 'W')
		vars->player.angle = M_PI;
	if (vars->map.map[(unsigned int)(vars->player.y >>
	SCALE)][(unsigned int)(vars->player.x >> SCALE)] == 'E')
		vars->player.angle = 0;
}
