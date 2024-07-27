/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: candriam <candriam@student.42antananarivo  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 09:34:50 by candriam          #+#    #+#             */
/*   Updated: 2024/07/17 09:05:31 by candriam         ###   ########.mg       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define TITLE "FdF"
# define SCALE 20
# define WIN_WIDTH 920.0
# define WIDTH 950.0
# define WIN_HEIGHT 680.0
# define HEIGHT 710.0
# define MAX_ZOOM 100
# define MIN_ZOOM 1.2
# define ALTITUDE 0.1
# define ZOOM_FACTOR 1.05
# define DEFAULT_HEIGHT_FACTOR 1.0
# define DEFAULT_ANGLE_X 0.523599
# define DEFAULT_ANGLE_Y 0.523599
# define TRANS_FACTOR_X 1
# define TRANS_FACTOR_Y 1
# define ROT 0.01
# define BRIGHT 0.1
# define MAX_BRIGHT 1
# define MIN_BRIGHT 0.2
# define LONG 1
# define LAT 0
# define MARGIN 100
# define READ 500000
# define SIZED 1

# define ESC 65307
# define CTRL_L 65507
# define CTRL_R 65508
# define SHIFT_L 65505
# define SHIFT_R 65506

# define UP 65362
# define DOWN 65364
# define LEFT 65361
# define RIGHT 65363

# define K_SUM 65451
# define K_MIN 65453

# define K_A 97
# define K_B 98
# define K_C 99
# define K_D 100
# define K_E 101
# define K_F 102
# define K_G 103
# define K_H 104
# define K_I 105
# define K_J 106
# define K_K 107
# define K_L 108
# define K_M 109
# define K_N 110
# define K_O 111
# define K_P 112
# define K_Q 113
# define K_R 114
# define K_S 115
# define K_T 116
# define K_U 117
# define K_V 118
# define K_W 119
# define K_X 120
# define K_Y 121
# define K_Z 122

# define K_0 65438
# define K_1 65436
# define K_2 65433
# define K_3 65435
# define K_4 65430
# define K_5 65437
# define K_6 65432
# define K_7 65429
# define K_8 65431
# define K_9 65434

# define LOW_COLOR 0x0000FF
# define HIGH_COLOR 0xFF0000
# define BLACK 0x000000
# define DARK 0x151515
# define DEFAULT 0xEF8633
# define OFF_WHITE 0xF3F4F2
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define BOTTOM_COLOR 0x1B8EFA
# define TOP_COLOR 0xC2294E
# define GROUND_COLOR 0xF3AF3D

# define ROJO 		0xc1272d
# define VERDE		0x33cc55
# define FUCSIA 	0xff255c
# define AZUL		0x1B8EFA
# define SUPERAZUL	0x0000FF
# define CARBON		0x151515
# define WHITE		0xBBBBBB
# define DISCO		0x9A1F6A
# define BRICK_RED	0xC2294E
# define FLAMINGO	0xEC4B27
# define JAFFA		0xEF8633
# define SAFFRON	0xF3AF3D

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <math.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include "../includes/get_next_line.h"
# include "../includes/libft.h"
# include "../includes/libft.h"
# include "../includes/libftprintf.h"

typedef struct s_dot
{
	int		color;
	int		hexa_color;
	int		is_paint;
	float	pol[2];
	float	ax[3];
}				t_dot;

typedef struct s_color
{
	int	start_color;
	int	end_color;
	int	s_red;
	int	s_green;
	int	s_blue;
	int	e_red;
	int	e_green;
	int	e_blue;
	int	n_red;
	int	n_green;
	int	n_blue;
	int	topco;
	int	botco;
	int	backco;
	int	groundco;
}				t_color;

typedef struct s_bmap
{
	void	*img;
	char	*buffer;
	int		bpix;
	int		lines;
	int		endi;
}				t_bmap;

typedef struct s_set
{
	void	*mlx;
	void	*win;
}				t_set;

typedef struct s_mouse
{
	int		start_drag[2];
	int		is_leftmouse;
	int		is_rightmouse;
	int		leftmouse;
	int		rightmouse;
	t_dot	bef_leftmouse;
	t_dot	bef_rightmouse;
}				t_mouse;

typedef struct s_key
{
	int	leftctrl;
	int	rightctrl;
	int	leftshift;
	int	rightshift;
}				t_key;

typedef struct s_map
{
	char	**lines;
	char	*mem;
	int		min_z;
	int		min_x;
	int		min_y;
	int		length;
	int		height;
	int		is_lines;
	int		is_dots;
	int		is_suplines;
	int		is_geom;
	int		is_shad;
	int		translation[2];
	int		pos;
	float	prop;
	float	render;
	float	height_factor;
	float	brange;
	float	scale;
	float	divide_z;
	float	angle[3];
	float	rad;
	float	alt;
	float	zoom;
	double	perf;
	t_dot	lim;
	t_dot	from;
	t_dot	*dots;
	t_color	colors;
}				t_map;

typedef struct s_fdf
{
	int			pixels;
	int			length;
	int			height;
	int			first_line_len;
	int			is_first_line;
	int			pos;
	int			delta_x;
	int			delta_y;
	char		*stash;
	char		*buf;
	char		*maps;
	char		*line;
	char		**splits;
	char		**sub;
	char		*last;
	t_dot		discr;
	t_dot		pix;
	t_color		color;
	t_set		set;
	t_key		key;
	t_mouse		mouse;
	t_map		map;
	t_bmap		b_map;
}				t_fdf;

void	for_map_get_dots(t_fdf *fdf);
void	to_clean(t_fdf *fdf);
void	bi_free(void **str);
void	free_split(char **str);
void	init_mat(float mat[3][3]);
void	mapcpy(t_dot *from, t_dot *to, int length);
void	orto_proj(t_dot *dots, t_dot *proj, int length);
void	rotate_on_x(t_dot *dots, t_dot *proj, float angle, int length);
void	rotate_on_y(t_dot *dots, t_dot *proj, float angle, int length);
void	rotate_on_z(t_dot *dots, t_dot*proj, float angle, int length);
void	import_color(int max, int min, t_dot *dot, t_color colors);
void	initcolor(t_map *map);
void	_init_map(t_map *map, int sum);
void	divide_z(t_dot *dots, float divisor, int dot_nbr);
void	is_doted(t_fdf *fdf, t_dot *dots);
void	wireframe(t_dot *dot, t_fdf *fdf, int density, int line);
void	wired(t_fdf *fdf, t_dot *wire);
void	do_color(t_map *map);
void	parsing(t_fdf *fdf, t_dot *proj);
void	corres_screen(t_fdf *fdf, t_dot *proj);
void	drawing(t_fdf *fdf, t_dot *proj, int fit);
void	map_size(t_map *map);
void	map_get_dots(t_fdf *fdf);
void	main_init(t_fdf *fdf);
void	moves(t_dot *dots, t_dot move, int length);
void	scales(t_dot *dots, int scale, int length);
void	to_isometric(t_map *map);
void	from_top(t_map *map);
void	to_profil(t_map *map);
void	applynew_z(t_dot *dots, int length, float range);
void	to_sphere(t_map *map, t_dot *dots);
void	to_pol(t_map *map);
void	dot_aux(t_fdf *fdf, t_dot pixel, t_dot dot, int ref);
void	drawing_dot(t_fdf *fdf, t_dot dot, int rad);
void	dot_to_paint(t_dot *dots, int length);
void	set_color(char *buff, int endian, int color, int trans);
void	set_background(t_fdf *fdf, int bg_color);
void	tools_one(int keycode, t_fdf *fdf);
void	tools_two(int keycode, t_fdf *fdf);
void	tools_three(int keycode, t_fdf *fdf);
void	angle(float *angle, float value);
void	angle_control(int keycode, t_fdf *fdf);
void	terminate(char *str);
void	control_colorscheme(int keycode, t_map *map);
void	all_hooks(t_fdf *fdf);
void	clean_up(t_fdf *fdf);
void	init_var(t_fdf *fdf);
void	init_mlx(t_fdf *fdf);
void	init_mlx_utils(t_fdf *fdf);
void	move_all_dir(int keycode, t_fdf *fdf);
void	free_var(t_fdf *fdf);

int		check_init(t_fdf *fdf, int ac, char *filename);
int		is_fdf_file(const char *filename);
int		to_round(double value);
int		is_valid_pix(t_dot pix);
int		is_hexaco(char *line);
int		ft_isxdigit(int c);
int		ft_htoi(const char *str);
int		is_valid_dot(char *value);
int		lim_checks(t_dot *dots, int length);
int		draw_fdf(t_fdf *fdf, int sized);
int		import_dots(char *line, t_fdf *fdf, int line_nbr);
int		main(int argc, char **argv);
int		inter_color(int start_co, int end_co, int length, int pix);
int		dot_to_line(t_fdf *fdf, t_dot start, t_dot end);
int		put_pix(t_fdf *fdf, t_dot pix);
int		get_color(t_fdf *fdf, int color);
int		key_press(int keycode, t_fdf *fdf);
int		key_release(int keycode, t_fdf *fdf);
int		exit_program(t_fdf *fdf);
int		altitude(int keycode, t_fdf *fdf);
int		mouse_zoom(int mousecode, int x, int y, t_fdf *fdf);
int		ft_strcmp(const char *s1, const char *s2);
int		is_fdf_ext(const char *filename);
int		import_mcheck(t_fdf *fdf, char *filepath);
int		drawing_check(t_fdf *fdf);
int		mouse_release(int mousecode, int x, int y, t_fdf *fdf);
int		mouse_press(int mousecode, int x, int y, t_fdf *fdf);
int		mouse_step(int x, int y, t_fdf *fdf);
int		mouse_drag(int x, int y, t_fdf *fdf);
int		count_dots(t_fdf *fdf, const char *filename);
int		puterror(char *msg);
int		import_map(t_fdf *fdf, char *filepath);
int		check_imp_dots(t_fdf *fdf, int index);
int		count_sub(const char *str, char delimiter);
t_dot	multi_mat(float mat[3][3], t_dot dot);

char	*reading(int fd, t_fdf *fdf);

#endif