/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 16:14:31 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/26 19:50:15 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		ft_check_line(t_vars *vars, char **map)
{
	int	i;
	int	j;
	int	flag;

	flag = 0;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[0][j] != '1' && map[0][j] != ' ')
				vars->parse.erorrs.flag_invalid_map = 1;
			if (map[i][0] != '1' && map[i][0] != ' ')
				vars->parse.erorrs.flag_invalid_map = 1;
			if (map[i][j + 1] == '\0' || map[i][j + 1] == ' ')
				if (map[i][j] != '1' && map[i][j] != ' ')
					vars->parse.erorrs.flag_invalid_map = 1;
			j++;
		}
		i++;
	}
	if (vars->parse.erorrs.flag_invalid_map == 1)
		ft_errors(vars);
}

static void		ft_check_symbol(t_vars *vars, char **str)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (str[y] != NULL)
	{
		while (str[y][x] == '1' || str[y][x] == '0' || str[y][x] == 'N'
		|| str[y][x] == 'W' || str[y][x] == 'E'
		|| str[y][x] == 'S' || str[y][x] == '2' || str[y][x] == ' ')
			x++;
		y++;
	}
	if (str[y] != NULL)
	{
		vars->parse.erorrs.flag_invalid_map = 1;
		ft_errors(vars);
	}
}

static void		ft_find_max_w_h(t_vars *vars, char **str)
{
	int x;
	int y;
	int tmp;

	x = 0;
	y = 0;
	while (str[y] != NULL)
	{
		tmp = 0;
		while (str[y][tmp] != '\0')
		{
			tmp++;
		}
		x = x < tmp ? tmp : x;
		y++;
	}
	vars->map.width = x;
	vars->map.height = y;
}

void			ft_find_player(t_vars *vars, char **map, int x, int y)
{
	int i;

	i = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'N' || map[y][x] == 'W' ||
			map[y][x] == 'S' || map[y][x] == 'E')
			{
				vars->player.x = x * WIDTH + WIDTH / 2;
				vars->player.y = y * WIDTH + WIDTH / 2;
				i++;
			}
			x++;
		}
		y++;
	}
	if (i != 1)
		vars->parse.erorrs.flag_invalid_map = 1;
	if (i != 1)
		ft_errors(vars);
}

void			parse_map(t_vars *vars)
{
	char **map;

	if ((map = ft_split(vars->parse.map, '\n')) == NULL)
	{
		vars->parse.erorrs.flag_malloc_error = 1;
		ft_errors(vars);
	}
	free(vars->parse.map);
	vars->parse.map = NULL;
	ft_check_symbol(vars, map);
	ft_find_max_w_h(vars, map);
	ft_find_player(vars, map, 0, 0);
	ft_add_space(vars, map);
	ft_check_line(vars, map);
	check_map_validation(vars, map);
	vars->map.map = map;
}
