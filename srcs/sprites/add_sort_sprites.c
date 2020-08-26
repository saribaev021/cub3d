/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sort_sprites.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 18:24:39 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/26 19:35:35 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_len(t_vars *vars, t_sp_cor *root)
{
	t_sp_cor *tmp;

	tmp = root;
	while (tmp != NULL)
	{
		tmp->len = sqrt(pow(tmp->x - vars->player.x, 2) +
		pow(tmp->y - vars->player.y, 2));
		tmp = tmp->next;
	}
}

void		ft_swap(t_sp_cor **head, t_sp_cor *one, t_sp_cor *two)
{
	t_sp_cor *tmp;
	t_sp_cor *root;

	root = *head;
	if (one == *head)
	{
		tmp = two->next;
		two->next = one;
		one->next = tmp;
		(*head) = two;
	}
	else
	{
		while (root->next != one)
			root = root->next;
		tmp = two->next;
		two->next = one;
		one->next = tmp;
		root->next = two;
	}
}

void		sort_sprite_len(t_sp_cor **root)
{
	t_sp_cor	*tmp;
	int			flag;

	flag = 1;
	tmp = *root;
	while (flag)
	{
		flag = 0;
		tmp = *root;
		while (tmp->next != NULL)
		{
			if (tmp->len < tmp->next->len)
			{
				ft_swap(root, tmp, tmp->next);
				flag = 1;
			}
			else
				tmp = tmp->next;
		}
	}
}

t_sp_cor	*ft_add(t_vars *vars, int x, int y)
{
	t_sp_cor *new;

	new = malloc(sizeof(t_sp_cor));
	if (new == NULL)
	{
		vars->parse.erorrs.flag_malloc_error = 1;
		ft_errors(vars);
	}
	new->x = x * WIDTH + WIDTH / 2;
	new->y = y * WIDTH + WIDTH / 2;
	new->next = NULL;
	return (new);
}

void		ft_add_end(t_sp_cor *start, t_sp_cor *new)
{
	t_sp_cor *tmp;

	tmp = start;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}
