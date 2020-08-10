#include "cub3d.h"
void            my_mlx_pixel_put(t_vars *vars, int x, int y, int color)
{
	char    *dst;

	dst = vars->img.addr + (y * vars->img.line_length + x * (vars->img.bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_black(t_vars *vars)
{
	int y = 0;
	int x = 0;
	while (y < vars->window.height)
	{
		x = 0;
		while (x < vars->window.width)
		{

			my_mlx_pixel_put(vars, x, y, 0x000000);
			x++;
		}
		y++;
	}
	
}


// int ft_get_color(t_vars *vars, int x, int y)
// {
// 	int color;
// 	//color = (int *)(vars->l_tx.tex1.addr + (y * vars->img.line_length + x * (vars->img.bits_per_pixel / 8)));
// 	color = vars->l_tx.tex1.addr[y * 64 + (abs(x % 64)];
// 	return(color);
// }

double ft_ray(t_vars *vars, double angle)
{
	double tmp_x = vars->player.x;
	double tmp_y = vars->player.y;
	double vx;
	double vy;
	double hx;
	double hy;
	double vlen = INFINITY;
	double hlen = INFINITY;
	double ray;

	ray = 0;
	vx = 0;
	vy = 0;
	hx = 0;
	hy = 0;
	angle += angle < 0 ? 2 * M_PI : 0;
	angle -= angle > 2 * M_PI ? 2 * M_PI : 0;
	vars->angle = angle;
	if (angle == 3 * M_PI_2) // ^
	{
		hy = ((unsigned int)(vars->player.y >> SCALE) << SCALE) - 0.0000001;
		tmp_x = (unsigned int)vars->player.x >> SCALE;
		tmp_y = (unsigned int)hy >> SCALE;
		while (tmp_y < MAPHEIGHT && tmp_x < MAPWIDTH && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 1 && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 2)
		{
			hy -= WIDTH; 
			tmp_y = (unsigned int)hy >> SCALE;
		}
		hlen = sqrt((vars->player.y - hy) * (vars->player.y - hy));
		ray = hlen;
	}
	//------------------------------------------------//
	//------------------------------------------------//
	//------------------------------------------------//
	if (angle > 3 * M_PI_2 && angle < 2 * M_PI) // ^>
	{
		vx = ((unsigned int)(vars->player.x >> SCALE) << SCALE) + WIDTH;
		vy = vars->player.y - ((vars->player.x - vx) * tan(angle));
		tmp_x = (unsigned int)vx >> SCALE;
		tmp_y = (unsigned int)vy >> SCALE;
		while (tmp_y < MAPHEIGHT && tmp_x < MAPWIDTH && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 1 && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 2)
		{
			vx += WIDTH; 
			vy += WIDTH * tan(angle);
			tmp_x = (unsigned int)vx >> SCALE;
			tmp_y = (unsigned int)vy >> SCALE;
		}
		vlen = sqrt((vars->player.x - vx) * (vars->player.x - vx) + (vars->player.y - vy) * (vars->player.y - vy));
		//-------------------------------------------//
		//-------------------------------------------//
		//-------------------------------------------//
		hy = ((unsigned int)(vars->player.y >> SCALE) << SCALE) - 0.0000001;
		hx = vars->player.x - ((vars->player.y - hy) / tan(angle));
		tmp_x = (unsigned int)hx >> SCALE;
		tmp_y = (unsigned int)hy >> SCALE;
		while (tmp_y < MAPHEIGHT && tmp_x < MAPWIDTH && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 1 && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 2)
		{
			hy -= WIDTH; 
			hx -= WIDTH / tan(angle);
			tmp_x = (unsigned int)hx >> SCALE;
			tmp_y = (unsigned int)hy >> SCALE;
		}
		hlen = sqrt((vars->player.x - hx) * (vars->player.x - hx) + (vars->player.y - hy) * (vars->player.y - hy));
		ray = vlen > hlen ? hlen : vlen;
	}

	if (angle == 0 || angle == 2 * M_PI) // >
	{
		vx = ((unsigned int)(vars->player.x >> SCALE) << SCALE) + WIDTH;
		tmp_x = (unsigned int)vx >> SCALE;
		tmp_y = (unsigned int)vars->player.y >> SCALE;
		while (tmp_y < MAPHEIGHT && tmp_x < MAPWIDTH && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 1 && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 2)
		{
			vx += WIDTH; 
			tmp_x = (unsigned int)vx >> SCALE;
		}
		vlen = sqrt((vars->player.x - vx) * (vars->player.x - vx));
		//-------------------------------------------//
		//-------------------------------------------//
		//-------------------------------------------//
		ray = vlen;
	}
	if (angle > 0 && angle < M_PI_2) // V>
	{
		vx = ((unsigned int)(vars->player.x >> SCALE) << SCALE) + WIDTH;
		vy = vars->player.y - ((vars->player.x - vx) * tan(angle));
		tmp_x = (unsigned int)vx >> SCALE;
		tmp_y = (unsigned int)vy >> SCALE;
		while (tmp_y < MAPHEIGHT && tmp_x < MAPWIDTH && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 1 && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 2)
		{
			vx += WIDTH; 
			vy += WIDTH * tan(angle);
			tmp_x = (unsigned int)vx >> SCALE;
			tmp_y = (unsigned int)vy >> SCALE;
		}
		vlen = sqrt((vars->player.x - vx) * (vars->player.x - vx) + (vars->player.y - vy) * (vars->player.y - vy));
		//-------------------------------------------//
		//-------------------------------------------//
		//-------------------------------------------//
		hy = ((unsigned int)(vars->player.y >> SCALE) << SCALE) + WIDTH;
		hx = vars->player.x - ((vars->player.y - hy) / tan(angle));
		tmp_x = (unsigned int)hx >> SCALE;
		tmp_y = (unsigned int)hy >> SCALE;
		while (tmp_y < MAPHEIGHT && tmp_x < MAPWIDTH && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 1 && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 2)
		{
			hy += WIDTH; 
			hx += WIDTH / tan(angle);
			tmp_x = (unsigned int)hx >> SCALE;
			tmp_y = (unsigned int)hy >> SCALE;
		}
		hlen = sqrt((vars->player.x - hx) * (vars->player.x - hx) + (vars->player.y - hy) * (vars->player.y - hy));
		ray = vlen > hlen ? hlen : vlen;
	}
//-----------------------------------------------//
	if (angle == M_PI_2) // V
	{
		hy = ((unsigned int)(vars->player.y >> SCALE) << SCALE) + WIDTH;
		tmp_x = (unsigned int)vars->player.x >> SCALE;
		tmp_y = (unsigned int)hy >> SCALE;
		while (tmp_y < MAPHEIGHT && tmp_x < MAPWIDTH && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 1 && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 2)
		{
			hy += WIDTH; 
			tmp_y = (unsigned int)hy >> SCALE;
		}
		hlen = sqrt((vars->player.y - hy) * (vars->player.y - hy));
		ray = hlen;
	}
//-----------------------------------------------------------//
	if (angle > M_PI_2 && angle < M_PI) // V<
	{
		vx = ((unsigned int)(vars->player.x >> SCALE) << SCALE) - 0.0000001;
		vy = vars->player.y - ((vars->player.x - vx) * tan(angle));
		tmp_x = (unsigned int)vx >> SCALE;
		tmp_y = (unsigned int)vy >> SCALE;
		while (tmp_y < MAPHEIGHT && tmp_x < MAPWIDTH && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 1 && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 2)
		{
			vx -= WIDTH; 
			vy -= WIDTH * tan(angle);
			tmp_x = (unsigned int)vx >> SCALE;
			tmp_y = (unsigned int)vy >> SCALE;
		}
		vlen = sqrt((vars->player.x - vx) * (vars->player.x - vx) + (vars->player.y - vy) * (vars->player.y - vy));
		//-------------------------------------------//
		//-------------------------------------------//
		//-------------------------------------------//
		hy = ((unsigned int)(vars->player.y >> SCALE) << SCALE) + WIDTH;
		hx = vars->player.x - ((vars->player.y - hy) / tan(angle));
		tmp_x = (unsigned int)hx >> SCALE;
		tmp_y = (unsigned int)hy >> SCALE;
		while (tmp_y < MAPHEIGHT && tmp_x < MAPWIDTH && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 1 && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 2)
		{
			hy += WIDTH; 
			hx += WIDTH / tan(angle);
			tmp_x = (unsigned int)hx >> SCALE;
			tmp_y = (unsigned int)hy >> SCALE;
		}
		hlen = sqrt((vars->player.x - hx) * (vars->player.x - hx) + (vars->player.y - hy) * (vars->player.y - hy));
		ray = vlen > hlen ? hlen : vlen;
	}
	if (angle == M_PI) // <
	{
		vx = ((unsigned int)(vars->player.x >> SCALE) << SCALE) - 0.0000001;
		tmp_x = (unsigned int)vx >> SCALE;
		tmp_y = (unsigned int)vars->player.y >> SCALE;
		while (tmp_y < MAPHEIGHT && tmp_x < MAPWIDTH && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 1 && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 2)
		{
			vx -= WIDTH; 
			tmp_x = (unsigned int)vx >> SCALE;
		}
		vlen = sqrt((vars->player.x - vx) * (vars->player.x - vx));
		//-------------------------------------------//
		//-------------------------------------------//
		//-------------------------------------------//
		ray = vlen;
	}
	//---------------------------------------------------------//
	if (angle < 3 * M_PI_2 && angle > M_PI) // ^<
	{
		vx = ((unsigned int)(vars->player.x >> SCALE) << SCALE) - 0.0000001;
		vy = vars->player.y - ((vars->player.x - vx) * tan(angle));
		tmp_x = (unsigned int)vx >> SCALE;
		tmp_y = (unsigned int)vy >> SCALE;
		while (tmp_y < MAPHEIGHT && tmp_x < MAPWIDTH && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 1 && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 2)
		{
			vx -= WIDTH; 
			vy -= WIDTH * tan(angle);
			tmp_x = (unsigned int)vx >> SCALE;
			tmp_y = (unsigned int)vy >> SCALE;
		}
		vlen = sqrt((vars->player.x - vx) * (vars->player.x - vx) + (vars->player.y - vy) * (vars->player.y - vy));
		//-------------------------------------------//
		//-------------------------------------------//
		//-------------------------------------------//
		hy = ((unsigned int)(vars->player.y >> SCALE) << SCALE) - 0.0000001;
		hx = vars->player.x - ((vars->player.y - hy) / tan(angle));
		tmp_x = (unsigned int)hx >> SCALE;
		tmp_y = (unsigned int)hy >> SCALE;
		while (tmp_y < MAPHEIGHT && tmp_x < MAPWIDTH && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 1 && map[(unsigned int)tmp_y][(unsigned int)tmp_x] != 2)
		{
			hy -= WIDTH; 
			hx -= WIDTH / tan(angle);
			tmp_x = (unsigned int)hx >> SCALE;
			tmp_y = (unsigned int)hy >> SCALE;
		}
		hlen = sqrt((vars->player.x - hx) * (vars->player.x - hx) + (vars->player.y - hy) * (vars->player.y - hy));
		ray = vlen > hlen ? hlen : vlen;
	}
	if (vlen < hlen)
	{
		if (angle > M_PI_2 && angle < 3 * M_PI_2)
			vars->flag = 1;
		else
			vars->flag = 2;
		vars->sp.sprite_x = (int)vx;
		vars->sp.sprite_y = (int)vy;
	}
	else
	{
		if (angle > M_PI && angle < M_PI * 2)
			vars->flag = 3;
		else
			vars->flag = 4;
		vars->sp.sprite_x = (int)hx;
		vars->sp.sprite_y = (int)hy;
	}
	
	
	vars->y = (vy - ((int)(vy / WIDTH) * WIDTH - 0.0000001));
	vars->x = (hx - ((int)(hx / WIDTH) * WIDTH - 0.0000001));
	
	
	vars->i = vlen < hlen ? 1 : 0;
	return ray;
}

void ft_draw_sprite(t_vars *vars, double len, int x, double angle)
{
	int i = 0;
}

void ft_draw_wall(t_vars *vars, double len, int screen_x, int xxx, double angle_ray)
{
	double h_koef = 0;
	int h = 0;
	int k = 0;
	int tex_y = 0;
	int tex_x = 0;
	int tmp = 0;
	int first_point;
	int l = 0;
	int color;
	int middle_screen = vars->window.height / 2;
	len = len * cos(vars->player.angle - angle_ray);
	int middle_wall = (vars->window.height  * 64) / (len);
	int start = middle_screen - middle_wall;
	int h_wall = middle_wall * 2;
	first_point = start;
	if (start < 0)
	  start = 0;
	if (start > 0)
		while (l < start && l < vars->window.height&& screen_x < vars->window.width)
		{
			my_mlx_pixel_put(vars, screen_x, l, 0x66ffff);
			l++;
		}
	h_koef = 64.0 / h_wall;
	tex_y = 0;
	while (start < (middle_wall + middle_screen) && start < vars->window.height && screen_x < vars->window.width)
	{
		tex_y = (int)((start - first_point) * h_koef);
		if (vars->flag == 1)
			color = *(unsigned int *)(vars->l_tx.tex1.addr + ((tex_y + 1) * vars->l_tx.tex1.line_length - (vars->y + 1) * (vars->l_tx.tex1.bits_per_pixel / 8)));
		else if (vars->flag == 2)
			color = *(unsigned int *)(vars->l_tx.tex2.addr + (tex_y * vars->l_tx.tex2.line_length +  vars->y * (vars->l_tx.tex2.bits_per_pixel / 8)));			
		else if (vars->flag == 3)
			color = *(unsigned int *)(vars->l_tx.tex3.addr + (tex_y * vars->l_tx.tex3.line_length +  vars->x * (vars->l_tx.tex3.bits_per_pixel / 8)));
		else if (vars->flag == 4)
			color = *(unsigned int *)(vars->l_tx.tex4.addr + ((tex_y + 1) * vars->l_tx.tex4.line_length -  (vars->x + 1) * (vars->l_tx.tex4.bits_per_pixel / 8)));
		my_mlx_pixel_put(vars, screen_x, start++, color);
	}
	l = middle_wall + middle_screen;
	if (first_point > 0)
	{
		while (l < vars->window.height && l > 0)
		{		
			color = *(unsigned int *)(vars->l_tx.tex2.addr + (tex_y * vars->l_tx.tex2.line_length +  vars->y * (vars->l_tx.tex2.bits_per_pixel / 8)));
			my_mlx_pixel_put(vars, screen_x, l, 0xffffff);
			l++;
		}
	}
}
void ft_tracer(t_vars *vars)
{
	int k;
	double ray;
		int l = 0;
	k = 0;
	int x = 0;
	int xxx = 0;
	double step = M_PI / (3.0 * vars->window.width);
	ray = 0;
	double start_angel;
	start_angel = vars->player.angle - M_PI / 6;
	double end_angel = vars->player.angle + M_PI / 6;
	vars->i = 0;
	vars->l_tx.tex1.tmp = 0;
	l = vars->x;
	vars->flag = 0;
	while (start_angel < end_angel)
	{
		vars->player.ray = ft_ray(vars, start_angel);
		if (map[(unsigned int)vars->sp.sprite_y >> SCALE][(unsigned int)vars->sp.sprite_x >> SCALE] != 2)
			ft_draw_wall(vars, vars->player.ray, x, xxx, start_angel);
		else
		{
			ft_draw_sprite(vars, vars->player.ray, x, start_angel);
		}
		
		// break;
		x++;
		// if (x == 64)
		// 	break;
		start_angel += step; 
	}
}

int create_dout(t_vars *vars, int x, int y, int color)
{
	double tmp_x = x;
	double tmp_y = y;
	int k = 0;
	//ft_tracer(vars);
	tmp_y = y - 5;
	tmp_x = x - 5;
	while (tmp_y < (y + 5) && x < 1919 && y < 1079 && x >= 5 && y >=5)
	{
		tmp_x = x - 5;
		while (tmp_x < (x + 5))
		{
			my_mlx_pixel_put(vars, tmp_x, tmp_y, color);
			tmp_x++;
		}
		tmp_y++;
	}
	while (k <= 10)
	{
		my_mlx_pixel_put(vars, x + k * cos(vars->player.angle), y + k * sin(vars->player.angle), 0xffffff);
		k++;
	}
	return 0;
}

void create_map(t_vars *vars)
{
	int count = 0;
	int x = 0;
	int y = 0;
	int i = 1;
	unsigned int yy = MAPHEIGHT << 3u;
	unsigned int xx = MAPWIDTH << 3u;
	ft_tracer(vars);
	
	while(y < yy)
	{
		x = 0;
		while (x < xx)
		{
			if (map[y >> 3u][x >> 3u] == 1)
				my_mlx_pixel_put(vars, x, y, 0x00ff00);
			if (map[y >> 3u][x >> 3u] == 0 || map[y >> 3u][x >> 3u] == 5)
				my_mlx_pixel_put(vars, x, y, 0xff0000);
			x++;
		}
		y++;
	}
	create_dout(vars, vars->player.x >> 3u, vars->player.y >> 3u, 0xfdfdda);
}
int             events(int keycode, t_vars *vars)
{
	unsigned int x;
	unsigned int xx;
	unsigned int y;
	unsigned int yy;
	
	xx = vars->player.x;
	yy = vars->player.y;
	if (vars->l++ == 1)
		vars->l = 4;
	if (keycode == 53) //esc
		exit(0);
	if (keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123 || keycode == 2 || keycode == 0 )
	{
		ft_black(vars);
		if (keycode == 0) //a
		{
			vars->player.angle -= 0.1;
			if (vars->player.angle <= 0)
				vars->player.angle += 2 * M_PI;
		}
		if (keycode == 2)//d
		{
			vars->player.angle += 0.1;
			if (vars->player.angle >= 2 * M_PI)
				vars->player.angle = 0;
			
		}
		if (keycode == 124) //->
		{
			vars->player.y += SPEED * cos(vars->player.angle);
			vars->player.x -= SPEED * sin(vars->player.angle);
			x = vars->player.x >> SCALE;
			y = vars->player.y >> SCALE;
			if (map[y][x] == 1)
			{
				vars->player.y -= SPEED * cos(vars->player.angle);
				vars->player.x += SPEED * sin(vars->player.angle);
			}
		}
		if (keycode == 123)//<-
		{
			vars->player.y -= SPEED * cos(vars->player.angle);
			vars->player.x += SPEED * sin(vars->player.angle);
			x = vars->player.x >> SCALE;
			y = vars->player.y >> SCALE;
			if (map[y][x] == 1)
			{
				vars->player.y += SPEED * cos(vars->player.angle);
				vars->player.x -= SPEED * sin(vars->player.angle);
			}
		}
		if (keycode == 126)//^
		{
			vars->player.y += SPEED * sin(vars->player.angle);
			vars->player.x += SPEED * cos(vars->player.angle);
			x = vars->player.x >> SCALE;
			y = vars->player.y >> SCALE;
			if (map[y][x] == 1)
			{
				if (vars->player.angle ==  3 * M_PI_2 || vars->player.angle == 0 || vars->player.angle == M_PI || vars->player.angle == M_PI_2 || vars->player.angle == 2 * M_PI) 
				{
					vars->player.y = yy;
					vars->player.x = xx;
				}
				else if (vars->player.angle <3 * M_PI_2)
				{
					vars->player.y += SPEED * cos(vars->player.angle);
					vars->player.x += SPEED * cos(vars->player.angle);
				}
			}
		}
		if (keycode == 125)//V
		{
			vars->player.y -= SPEED * sin(vars->player.angle);
			vars->player.x -= SPEED * cos(vars->player.angle);
			x = vars->player.x >> SCALE;
			y = vars->player.y >> SCALE;
			// if (map[y][x] == 1)
			// {
			// 	vars->player.y += SPEED * sin(vars->player.angle);
			// 	vars->player.x += SPEED * cos(vars->player.angle);
			// }
		}
		create_map(vars);
		mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.win, vars->img.img, 0, 0);
	}
	// if (keycode == 126 || keycode == 125 || keycode == 124 || keycode == 123 || keycode == 2 || keycode == 0)
	// {
	// 	mlx_destroy_image(vars->mlx.mlx, vars->img.img);
	// 	create_map(vars);
	// 	//create_dout(vars, 0xfdfdda);
	// 	mlx_put_image_to_window(vars->mlx.mlx, vars->mlx.win, vars->img.img, 0, 0);
	// }
	return 0;
}
void  create_image(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx.mlx, vars->window.width, vars->window.height);
	vars->l_tx.tex1.tex = mlx_xpm_file_to_image(vars->mlx.mlx, vars->l_tx.tex1.relative_path, &vars->l_tx.tex1.img_width, &vars->l_tx.tex1.img_height);
	vars->l_tx.tex1.addr = mlx_get_data_addr(vars->l_tx.tex1.tex,  &vars->l_tx.tex1.bits_per_pixel, &vars->l_tx.tex1.line_length,&vars->l_tx.tex1.endian);

	vars->l_tx.tex2.tex = mlx_xpm_file_to_image(vars->mlx.mlx, vars->l_tx.tex2.relative_path, &vars->l_tx.tex2.img_width, &vars->l_tx.tex2.img_height);
	vars->l_tx.tex2.addr = mlx_get_data_addr(vars->l_tx.tex2.tex,  &vars->l_tx.tex2.bits_per_pixel, &vars->l_tx.tex2.line_length,&vars->l_tx.tex2.endian);

	vars->l_tx.tex3.tex = mlx_xpm_file_to_image(vars->mlx.mlx, vars->l_tx.tex3.relative_path, &vars->l_tx.tex3.img_width, &vars->l_tx.tex3.img_height);
	vars->l_tx.tex3.addr = mlx_get_data_addr(vars->l_tx.tex3.tex,  &vars->l_tx.tex3.bits_per_pixel, &vars->l_tx.tex3.line_length,&vars->l_tx.tex3.endian);

	vars->l_tx.tex4.tex = mlx_xpm_file_to_image(vars->mlx.mlx, vars->l_tx.tex4.relative_path, &vars->l_tx.tex4.img_width, &vars->l_tx.tex4.img_height);
	vars->l_tx.tex4.addr = mlx_get_data_addr(vars->l_tx.tex4.tex,  &vars->l_tx.tex4.bits_per_pixel, &vars->l_tx.tex4.line_length,&vars->l_tx.tex4.endian);

	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
}
int             main(void)
{
	t_vars      vars;
	vars.i = 0;
	vars.l = 0;
	vars.player.x = 500;
	vars.player.y = 300;
	vars.window.width = 1920;
	vars.window.height = 1080;
	vars.l_tx.tex1.relative_path = "./www.xpm";
	vars.l_tx.tex2.relative_path = "./greystone.xpm";
	vars.l_tx.tex3.relative_path = "./texture_xpm/WALL74.xpm";
	vars.l_tx.tex4.relative_path = "./texture_xpm/WALL76.xpm";
	
	vars.player.angle = M_PI;
	vars.mlx.mlx = mlx_init();
	vars.mlx.win = mlx_new_window(vars.mlx.mlx, vars.window.width, vars.window.height, "Hello world!");
	vars.l_tx.tex1.tex = mlx_xpm_file_to_image(vars.mlx.mlx, vars.l_tx.tex1.relative_path, &vars.l_tx.tex1.img_width, &vars.l_tx.tex1.img_height);
	create_image(&vars);
	create_map(&vars);
	int h_wall ,w_k;
	int color;
	int a = 0;
	int b = 0;
	int y = 0;
	int x = 0;
	int i = 0;
	int k = 0;
	// while (a < 604)
	// {
	// 	b = 0;
	// 	//k = 0;
	// 	x = 0;
	// 	while (b < 1920)
	// 	{
	// 		color = *(unsigned int *)(vars.l_tx.tex1.addr + (y * vars.l_tx.tex1.line_length + x * (vars.l_tx.tex1.bits_per_pixel / 8)));
	// 		my_mlx_pixel_put(&vars, b, a, color);
	// 		b++;
	// 		k++;
	// 		if (k == 30)
	// 		{
	// 			k = 0;
	// 			x++;
	// 		}
	// 	}
	// 	i++;
	// 	a++;
	// 	if (i == 10)
	// 	{
	// 		y++;
	// 		i = 0;
	// 	}
	// }
	// a = 0;
	// b = 0;
	// while (a < 64)
	// {
	// 	b = 0;
	// 	while (b < 64)
	// 	{
	// 		color = *(unsigned int *)(vars.l_tx.tex1.addr + (a * vars.l_tx.tex1.line_length + b * (vars.l_tx.tex1.bits_per_pixel / 8)));
	// 		my_mlx_pixel_put(&vars, b, a, color);
	// 		b++;
	// 	}
	// 	a++;
	
	// }
	
	mlx_put_image_to_window(vars.mlx.mlx, vars.mlx.win, vars.l_tx.tex1.tex, 0, 0);
	mlx_hook(vars.mlx.win, 2,0L,events, &vars);
	mlx_loop(vars.mlx.mlx);
} 