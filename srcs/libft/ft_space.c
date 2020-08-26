/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 17:49:50 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/26 11:25:19 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_space(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' ||
	str[i] == '\f' || str[i] == '\r')
	{
		i++;
	}
	return (i);
}