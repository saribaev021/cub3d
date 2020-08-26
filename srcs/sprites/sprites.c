/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:25:35 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/26 19:37:26 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void			ft_clear_list(t_sp_cor **head)
{
	t_sp_cor *tmp;
	t_sp_cor *tmp2;

	tmp = (*head);
	tmp2 = (*head);
	if (tmp->next == NULL)
	{
		free(tmp);
		(*head) = NULL;
		return ;
	}
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp2 = tmp->next;
	free(tmp2);
	tmp->next = NULL;
}

static void		paint_sprite(t_vars *vars, t_sp_cor *sp, double *count_ray,
					double h_koef)
{
	int x;
	int y;

	x = -1;
	while (++x < sp->sp_scn_sz)
	{
		if (!((sp->x_start + x < 0 || sp->x_start + x >= vars->window.width) ||
		(count_ray[x + sp->x_start] < sp->len)))
		{
			y = -1;
			while (++y < sp->sp_scn_sz)
			{
				if (!(sp->y_start + y < 0 ||
				sp->y_start + y >= vars->window.height))
				{
					if (get_cl(vars, x * h_koef, y * h_koef) > 0
					&& sp->y_start + y < vars->window.height)
						my_mlx_pixel_put(vars, sp->x_start + x, sp->y_start +
						y, get_cl(vars, x * h_koef, y * h_koef));
				}
			}
		}
	}
}

static void		ft_draw_sprite(t_vars *vars, t_sp_cor *sp, double *count_ray)
{
	double h_koef;

	sp->sp_scn_sz = (int)(vars->window.height / sp->len * 64);
	sp->sprite_dir = atan2(sp->y - vars->player.y, sp->x - vars->player.x);
	while (sp->sprite_dir - vars->player.angle > M_PI)
		sp->sprite_dir -= 2 * M_PI;
	while (sp->sprite_dir - vars->player.angle < -M_PI)
		sp->sprite_dir += 2 * M_PI;
	sp->x_start = (sp->sprite_dir - vars->player.angle) *
	vars->window.width / (M_PI / 3)
	+ vars->window.width / 2 - sp->sp_scn_sz / 2;
	sp->y_start = vars->window.height / 2 - sp->sp_scn_sz / 2;
	h_koef = (double)vars->sp.img_height / (double)sp->sp_scn_sz;
	paint_sprite(vars, sp, count_ray, h_koef);
}

void			ft_sprite(t_vars *vars, double *count_ray)
{
	if (vars->count_sprite > 0)
	{
		ft_len(vars, vars->sp_cor);
		sort_sprite_len(&vars->sp_cor);
		vars->tmp = vars->sp_cor;
		while (vars->tmp != NULL)
		{
			ft_draw_sprite(vars, vars->tmp, count_ray);
			vars->tmp = vars->tmp->next;
		}
	}
}

void			get_sprite(t_vars *vars)
{
	int x;
	int y;
	int flag;

	flag = 1;
	y = -1;
	x = -1;
	while (++y < vars->map.height)
	{
		x = -1;
		while (++x < vars->map.width)
		{
			if (vars->map.map[y][x] == '2' && flag == 1)
			{
				vars->sp_cor = ft_add(vars, x, y);
				flag = 0;
			}
			if (vars->map.map[y][x] == '2' && flag == 2)
				ft_add_end(vars->sp_cor, ft_add(vars, x, y));
			if (flag == 0)
				flag = 2;
		}
	}
}
