/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 22:20:58 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/26 19:44:17 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void		get_map(t_vars *vars, char *line)
{
	char	*tmp;
	int		i;

	i = 0;
	if (vars->parse.erorrs.flag_empty_line == 1)
	{
		i = ft_space(line, i);
		tmp = vars->parse.map;
		if ((vars->parse.map = ft_strjoin(vars->parse.map, line)) == NULL)
			vars->parse.erorrs.flag_malloc_error = 1;
		if (tmp != NULL)
			free(tmp);
		tmp = vars->parse.map;
		if ((vars->parse.map = ft_strjoin(vars->parse.map, " \n")) == NULL)
			vars->parse.erorrs.flag_malloc_error = 1;
		if (tmp != NULL)
			free(tmp);
	}
	if (vars->parse.erorrs.flag_empty_line == 0 ||
		vars->parse.erorrs.flag_malloc_error == 1)
		ft_errors(vars);
}

static void		check_file(t_vars *vars, int i, char *line)
{
	if (i == -1)
	{
		vars->parse.erorrs.flag_gnl = 1;
		ft_errors(vars);
	}
	get_map(vars, line);
	get_map(vars, " ");
	check_flag(vars);
	free(line);
	parse_map(vars);
}

int				get_file(t_vars *vars, int fd)
{
	char	*line;
	int		i;

	line = NULL;
	if ((vars->parse.map = ft_strdup("")) == NULL)
	{
		vars->parse.erorrs.flag_malloc_error = 1;
		ft_errors(vars);
	}
	while ((i = ft_get_next_line(fd, &line)) > 0)
	{
		if (vars->parse.erorrs.flag_empty_line == 0)
			parse_parameter(vars, line);
		else if (vars->parse.erorrs.flag_empty_line == 1)
			get_map(vars, line);
		free(line);
	}
	check_file(vars, i, line);
	close(fd);
	return (0);
}
