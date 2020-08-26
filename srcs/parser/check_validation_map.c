/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validation_map.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 17:00:20 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/26 16:33:03 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		check_map_sprite(t_vars *vars, char **map, int x, int y)
{
	int	k;
	int	i;

	k = 0;
	i = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
			if (map[y][x++] == '2')
			{
				k++;
				if (map[y][x] == ' ' || map[y][x - 2] == ' ' ||
				map[y + 1][x - 1] == ' ' || map[y - 1][x - 1] == ' ')
					i++;
			}
		y++;
	}
	if (i != 0)
	{
		vars->parse.erorrs.flag_invalid_map = 1;
		ft_errors(vars);
	}
	vars->count_sprite = k;
}

static void		check_map_zero(t_vars *vars, char **map, int x, int y)
{
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '0')
			{
				if (map[y][x + 1] == ' ' || map[y][x - 1] == ' ' ||
				map[y + 1][x] == ' ' || map[y - 1][x] == ' ')
					vars->parse.erorrs.flag_invalid_map = 1;
			}
			x++;
		}
		y++;
	}
	if (vars->parse.erorrs.flag_invalid_map == 1)
		ft_errors(vars);
}

static void		check_map_player(t_vars *vars, char **map, int x, int y)
{
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'N' || map[y][x] == 'W' || map[y][x] == 'S' ||
			map[y][x] == 'E')
				if (map[y][x + 1] == ' ' || map[y][x - 1] == ' ' ||
				map[y + 1][x] == ' ' || map[y - 1][x] == ' ')
					vars->parse.erorrs.flag_invalid_map = 1;
			x++;
		}
		y++;
	}
	if (vars->parse.erorrs.flag_invalid_map == 1)
		ft_errors(vars);
}

void			check_map_validation(t_vars *vars, char **map)
{
	check_map_zero(vars, map, 0, 0);
	check_map_player(vars, map, 0, 0);
	check_map_sprite(vars, map, 0, 0);
}
