/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 09:34:50 by candriam          #+#    #+#             */
/*   Updated: 2024/07/01 14:09:19 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define TITLE "FdF "
# define SCALE 20
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define MAX_ZOOM 42
# define MIN_ZOOM 1
# define ALTITUDE 0.009
# define ZOOM_FACTOR 2
# define TRANS_FACTOR_X 1
# define TRANS_FACTOR_Y 1
# define ROT 0.01
# define BRIGHT 0.1
# define MAX_BRIGHT 1
# define MIN_BRIGHT 0.2

# define LOW_COLOR 0x0000FF
# define HIGH_COLOR 0xFF0000
# define BLACK 0x000000
# define DARK 0x080808
# define DEFAULT 0xAE9C69
# define WHITE 0xFFFFFF
# define OFF_WHITE 0xF3F4F2
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../Libft/libft.h"

typedef struct s_finp
{
	float	x;
	float	y;
	//float	z;
	//float	alt;
}				t_finp;

typedef struct s_initp
{
	int	x;
	int	y;
	int	z;
}				t_initp;

typedef struct s_diff
{
	float	dx;
	float	dy;
}				t_diff;

typedef struct s_3D
{
	float	x;
	float	y;
	float	z;
}				t_3D;

typedef struct s_calc
{
	float	x;
	float	y;
	float	move;
	t_diff	diff;
}				t_calc;

typedef struct s_dot
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_dot;

typedef struct s_set
{
	void	*mlx;
	void	*win;
	void	*img;
	int		**map;
	float	brightness;
	int		bg;
	int		is_ctrl;
	int		is_shift;
	int		color;
	int		x;
	int		y;
	int		pos;
	int		bpp;
	int		len;
	int		endi;
	int		scale;
	int		x_translation;
	int		y_translation;
	int		c_x;
	int		c_y;
	int		x_end;
	int		y_end;
	int		is_dragging;
	int		last_x;
	int		last_y;
	int		offset_x;
	int		offset_y;
	int		map_width;
	int		map_height;
	int		**tab;
	char	*map_filepath;
	char	*addr;
	char	*argv;
	float	altitude;
	float	zoom;
	float	angle;
	float	angle_x;
	float	angle_y;
	float	angle_z;
	t_finp	*finp;
	t_initp	*initp;
	t_diff	*diff;
}				t_set;

void	pixel_put(t_set *set, int x, int y, int color);
int	is_fdf_ext(const char *filename);
int		ftoi(float value);
float	fract_part(float value);
float	rest_fract_part(float value);
void	ft_swap(int *x, int *y);
int		set_map_brightness(int keycode, t_set *set);
void	pixel_put_antialiasing(t_set *set, int x, int y, int color);
int		get_min_z(t_set *set);
int		get_max_z(t_set *set);
void	load_dot(t_dot *dot, t_set *set);
int		get_color(int z, int min_z, int max_z);
int		inter_z(t_finp start, t_finp end, int pos, int move);

int		mouse_move(int x, int y, t_set *set);
int		mouse_release(int buton, int x, int y, t_set *set);
int		mouse_press(int buton, int x, int y, t_set *set);

int		map_rotate(int keycode, t_set *set);
int		move_all_dir(int keycode, t_set *set);
int		altitude(int keycode, t_set *set);
int		set_map_color_dyn(int keycode, t_set *set);
int		set_bg_color_dyn(int keycode, t_set *set);

void	all_rot(t_set *set, t_finp *start, t_finp *end);
void	calculate(t_calc *calc, t_finp start, t_finp end);
void	rotate_on_x(t_3D *point, float angle);
void	rotate_on_y(t_3D *point, float angle);
void	rotate_on_z(t_3D *point, float angle);

float	vabs(float value);
void	main_input(t_set *set);

int	ft_strcmp(const char *s1, const char *s2);
void	puterror(const char *msg);
void	map_info(t_set *set, char *filename);
void	check_map(t_set *set, char *filename);
void	parsing(t_set *set, char *filename);

void	x_y_dimension(t_set *set);
void	x_y_z_dim(t_set *set);
void	display_background(t_set *set);
void	pixel_put(t_set *set, int x, int y, int color);
void	draw_line(t_set *set, t_finp start, t_finp end);

int		mouse_zoom(int mousecode, int x, int y, t_set *set);
void	limits(t_set *set);
void	borderless(t_set *set);
void	base_level(t_set *set);

void	free_tab(t_set *set);

int		init_set(t_set *set, char *filename);
int		performer(t_set *set);
void	borders(t_set *set);
void	all_hook(t_set *set);
int		set_def_color(t_set set);

#endif
