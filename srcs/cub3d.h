/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndreadno <ndreadno@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 11:28:36 by ndreadno          #+#    #+#             */
/*   Updated: 2020/08/26 19:37:02 by ndreadno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"
# include <fcntl.h>
# define SPEED 15
# define STEP 32
# define LEFT 0
# define RIGHT 2
# define FORWARD 13
# define BACK 1
# define RIGHT_ARROW 124
# define LEFT_ARROW 123
# define SCALE 6u
# define WIDTH 64
# define MAPWIDTH 40
# define MAPHEIGHT 27
# define MAX_SIZE_SP 2000

typedef struct	s_mlx{
	void		*mlx;
	void		*win;
}				t_mlx;

typedef struct	s_img{
	void		*img;
	void		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct	s_texture{
	void		*tex;
	char		*addr;
	char		*rl_pth;
	int			img_wdh;
	int			img_ht;
	int			bs_pxl;
	int			length;
	int			endian;
}				t_texture;

typedef struct	s_sprite{
	void		*tex;
	char		*addr;
	char		*rl_pth;
	int			img_width;
	int			img_height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_sprite;

typedef struct	s_player{
	int			x;
	int			y;
	double		angle;
	double		ray;
	double		fov;
}				t_player;

typedef struct	s_sp_cor{
	int					x;
	int					y;
	int					sp_scn_sz;
	int					x_start;
	int					y_start;
	double				sprite_dir;
	double				len;
	struct s_sp_cor		*next;
}				t_sp_cor;

typedef struct	s_window{
	int			width;
	int			height;
	int			max_w;
	int			max_h;
}				t_window;

typedef struct	s_map{
	int			width;
	int			height;
	char		**map;
}				t_map;

typedef struct	s_l_tx{
	t_texture	tex_no;
	t_texture	tex_so;
	t_texture	tex_we;
	t_texture	tex_ea;
}				t_l_tx;

typedef struct	s_color{
	int			c_r;
	int			c_g;
	int			c_b;
	int			flag;
	int			color;
	int			color_f;
	int			color_c;
}				t_color;

typedef struct	s_errors{
	int			flag_r;
	int			flag_no;
	int			flag_so;
	int			flag_we;
	int			flag_ea;
	int			flag_s;
	int			flag_f;
	int			flag_c;
	int			flag_smbl;
	int			flag_malloc_error;
	int			flag_invalid_file;
	int			flag_invalid_arg;
	int			flag_invalid_map;
	int			flag_empty_line;
	int			parse_flag_stop;
	int			flag_gnl;
	int			flag_num;
}				t_errors;

typedef struct	s_parse
{
	t_errors	erorrs;
	int			count_r;
	int			tex_no;
	int			tex_so;
	int			tex_we;
	int			tex_ea;
	int			s;
	int			count_color_f;
	int			count_color_c;
	char		*map;
	int			p_x;
	int			p_y;
}				t_parse;

typedef struct	s_vars{
	t_mlx		mlx;
	t_img		img;
	t_player	player;
	t_window	window;
	t_l_tx		l_tx;
	t_sprite	sp;
	t_sp_cor	*sp_cor;
	t_sp_cor	*tmp;
	t_color		rgb;
	t_parse		parse;
	t_map		map;
	int			*sp_arr;
	int			i;
	int			l;
	int			x;
	int			y;
	int			flag;
	double		angle;
	int			r;
	int			count_sprite;
	int			collected_sprites;
	int			end;
}				t_vars;

t_sp_cor		*ft_add(t_vars *vars, int x, int y);
void			init(t_vars *vars);
void			colloceted_sp(t_vars *vars);
void			start(t_vars *vars, int fd, int argc, char **argv);
void			parse_parameter(t_vars *vars, char *str);
void			paint_3d(t_vars *vars);
void			check_flag(t_vars *vars);
void			parse_parameter(t_vars *vars, char *str);
void			create_image(t_vars *vars);
void			create_dout(t_vars *vars, int x, int y, int color);
void			draw_map(t_vars *vars, int x, int y);
void			ft_draw_wall(t_vars *vars, double len, int screen_x,
				double angle_ray);
void			ft_sprite(t_vars *vars, double *count_ray);
void			my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void			sort_sprite_len(t_sp_cor **root);
void			get_sprite(t_vars *vars);
void			ft_clear_list(t_sp_cor **head);
void			ft_len(t_vars *vars, t_sp_cor *root);
void			ft_swap(t_sp_cor **head, t_sp_cor *one, t_sp_cor *two);
void			ft_errors(t_vars *vars);
void			ft_parameter(t_vars *vars, char *str, int i);
void			ft_forward(t_vars *vars);
void			ft_back(t_vars *vars);
void			parse_map(t_vars *vars);
void			ft_clear_list(t_sp_cor **head);
void			ft_left(t_vars *vars, int keycode);
void			ft_right(t_vars *vars, int keycode);
void			ft_add_space(t_vars *vars, char **map);
void			check_map_validation(t_vars *vars, char **map);
void			ft_add_end(t_sp_cor *start, t_sp_cor *new);
void			player_dir(t_vars *vars);
void			check_flag(t_vars *vars);
int				get_file(t_vars *vars, int fd);
int				get_cl(t_vars *vars, int x, int y);
int				screenshot(t_vars *vars);
double			ft_hlen_up(t_vars *vars);
double			ft_hlen_right(t_vars *vars);
double			ft_hlen_down(t_vars *vars);
double			ft_hlen_left(t_vars *vars);
double			ft_hlen(t_vars *vars, double angle);
double			ft_raycasting(t_vars *vars, double angle);

#endif
