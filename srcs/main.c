/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 23:30:33 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/26 19:54:47 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void		put_string(t_vars *vars)
{
	char *str;
	char *num;

	if ((num = ft_itoa(vars->collected_sprites)) == NULL)
	{
		vars->parse.erorrs.flag_malloc_error = 1;
		ft_errors(vars);
	}
	if ((str = ft_strjoin("collected sprites ", num)) == NULL)
	{
		vars->parse.erorrs.flag_malloc_error = 1;
		free(num);
		ft_errors(vars);
	}
	mlx_string_put(vars->mlx.mlx, vars->mlx.win, vars->window.width / 2,
	vars->window.height - 300, 0xffffff, str);
	free(num);
	free(str);
}

static	int		ft_close(void)
{
	exit(0);
	return (0);
}

static void		replace(t_vars *vars)
{
	mlx_destroy_image(vars->mlx.mlx, vars->img.img);
	create_image(vars);
	paint_3d(vars);
	mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.win, vars->img.img, 0, 0);
	put_string(vars);
}

static int		events(int keycode, t_vars *vars)
{
	if (keycode == 53)
		ft_close();
	if (keycode == LEFT)
		ft_left(vars, keycode);
	if (keycode == RIGHT)
		ft_right(vars, keycode);
	if (keycode == RIGHT_ARROW)
		ft_right(vars, keycode);
	else if (keycode == LEFT_ARROW)
		ft_left(vars, keycode);
	else if (keycode == FORWARD)
		ft_forward(vars);
	else if (keycode == BACK)
		ft_back(vars);
	if (keycode == FORWARD || keycode == BACK ||
	keycode == LEFT_ARROW || keycode == RIGHT_ARROW ||
		keycode == LEFT || keycode == RIGHT)
		replace(vars);
	return (0);
}

int				main(int argc, char **argv)
{
	t_vars	vars;
	int		fd;

	init(&vars);
	if (argc > 1 && argc < 4)
	{
		if (ft_strncmp(".cub", (ft_strchr(argv[1], '\0') - 4), 4) == 0)
		{
			if ((fd = open(argv[1], O_RDONLY)) < 0)
			{
				vars.parse.erorrs.flag_invalid_file = 1;
				ft_errors(&vars);
			}
			start(&vars, fd, argc, argv);
			mlx_put_image_to_window(vars.mlx.mlx, vars.mlx.win,
			vars.img.img, 0, 0);
			mlx_hook(vars.mlx.win, 2, 1L, events, &vars);
			mlx_hook(vars.mlx.win, 17, 0L, ft_close, &vars);
			mlx_loop(vars.mlx.mlx);
		}
	}
	vars.parse.erorrs.flag_invalid_arg = 1;
	ft_errors(&vars);
	return (0);
}
