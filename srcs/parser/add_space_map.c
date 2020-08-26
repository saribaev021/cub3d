/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_space_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 17:31:56 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/26 10:13:39 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char		*ft_add_chars(t_vars *vars, char *line, char c, int count)
{
	char	*tmp;
	int		len;

	while (count > 0)
	{
		len = ft_strlen(line);
		tmp = line;
		if ((line = (char*)malloc(len + 2)) == NULL)
		{
			vars->parse.erorrs.flag_malloc_error = 1;
			ft_errors(vars);
		}
		ft_memcpy(line, tmp, len);
		line[len] = c;
		line[len + 1] = '\0';
		free(tmp);
		count--;
	}
	return (line);
}

void			ft_add_space(t_vars *vars, char **map)
{
	int		y;

	y = 0;
	while (map[y] != NULL)
	{
		map[y] = ft_add_chars(vars, map[y], ' ', (vars->map.width -
		ft_strlen(map[y])));
		y++;
	}
}
