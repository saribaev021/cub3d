/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/23 19:41:46 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/26 10:08:47 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			int_to_char(int n, unsigned char *src)
{
	src[0] = (unsigned char)(n);
	src[1] = (unsigned char)(n >> 8);
	src[2] = (unsigned char)(n >> 16);
	src[3] = (unsigned char)(n >> 24);
}

static void		put_pixels(t_vars *vars, int fd)
{
	int	i;
	int	j;
	int	color;

	i = vars->window.height - 1;
	while (i >= 0)
	{
		j = 0;
		while (j < vars->window.width)
		{
			color = *(unsigned int*)(vars->img.addr +
			(i * vars->img.line_length + j *
			(vars->img.bits_per_pixel / 8)));
			write(fd, &color, 3);
			j++;
		}
		i--;
	}
}

void			bmp_header(t_vars *vars, int file_size, int fd)
{
	unsigned char bmp_arr[54];

	ft_bzero(bmp_arr, 54);
	bmp_arr[0] = (unsigned char)('B');
	bmp_arr[1] = (unsigned char)('M');
	int_to_char(file_size, bmp_arr + 2);
	bmp_arr[10] = (unsigned char)(54);
	bmp_arr[14] = (unsigned char)(40);
	int_to_char(vars->window.width, bmp_arr + 18);
	int_to_char(vars->window.height, bmp_arr + 22);
	bmp_arr[26] = (unsigned char)(1);
	bmp_arr[28] = (unsigned char)(24);
	write(fd, bmp_arr, 54);
}

int				screenshot(t_vars *vars)
{
	int fd;
	int	file_size;

	file_size = 54 + (4 * (vars->window.width * vars->window.height));
	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT |
		O_TRUNC | O_APPEND, 0666)) < 0)
		return (-1);
	bmp_header(vars, file_size, fd);
	put_pixels(vars, fd);
	close(fd);
	return (0);
}
