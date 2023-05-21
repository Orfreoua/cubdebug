/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orfreoua <ofreoua42student@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:58:03 by orfreoua          #+#    #+#             */
/*   Updated: 2023/03/31 19:34:20 by orfreoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "headers.h"

# define R_WIDTH 1000
# define R_HEIGHT 1000

# define OK 0
# define KO 1 

# define ERROR -1
# define ERROR_BIS -4
# define MAP_ERROR -1
# define EXIT_FAILLURE -1///////////////////
# define OK 0
# define RESO_X 1000
# define RESO_Y 1000

typedef enum s_cardinal_points
{
	EAST,
	SOUTH,
	WEST,
	NORTH,
	NORTHEAST,
	SOUTHEAST,
	SOUTHWEST,
	NORTHWEST,
}	t_cardinal_points;

typedef struct s_player
{
	t_point	pos;
	t_point	hit1;
	t_point	hit2;
	t_point	f_hit;
	char	dir;
	int		angle;
}	t_player;

typedef struct s_map
{
	char		**grid;
	t_size		size;
	t_player	player;
}				t_map;

typedef struct	s_texture
{
	char		*path;
	char		*addr;
	void		*img;
	int			img_width;
	int			img_height;
	int			bpp;
	int			line_lenght;
	int			endian;
}				t_texture;

typedef struct s_screen
{
	void		*img;
	char		*addr;
	int			bpp;
	int			l_len;
	int			endian;
}				t_screen;

typedef struct	s_args
{
	t_texture	north;
	t_texture	south;
	t_texture	east;
	t_texture	west;
	t_color		floor;
	t_color		ceiling;
	t_map		map;
	t_player	player;
}				t_args;

typedef struct s_ray
{
	double	*hypo;
	double	dist;
	int		wall_height;
	int		floored_wall_height;
	char	dir;
}			t_ray;

typedef struct s_textures
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
}	t_textures;

typedef struct s_file
{
	t_point		pos_player;
	t_textures	textures;
	t_color		ceiling;
	t_color		floor;
	double		rotate;
	char		**mapy;
	int			**taby;
	int			**map;
	int			**tab;
	char		*map_sep;
	char		*map_error;
	char		*parsing_map_msg;
	char		*p_map_msg;
	char		*src;
	int			ret_cei;
	int			ret_flo;
	int			ret;
	int			gnl;
	int			item;
	int			fd;
	int			parsing_map;
	int			pos;
	int			zone;
	int			free;
	int			x;
	int			n;
	int			len_y;
	int			y;
	int			stack;
	int			sep;
	int			big;
	int			two;
	int			fin;
}	t_file;

typedef struct s_data
{
	t_args			args;
	t_minimap		minimap;
	t_file			file;
	t_screen		buff1;
	t_screen		buff2;
	t_ray			ray;
	void			*mlx_ptr;
	void			*win_ptr;
	int				frame;
}	t_data;

int		print_error(char *msg);
void	free_error(t_data *data, char *msg);
int		load_file(t_data *data, char *file);
int		all_data_is_recovered(t_data *data);
void	init_file(t_file *file);
/*void	draw_point(t_data *data, int x, int y, int color);
void	display_minimap(t_data *data);
void	mini_map_init(t_data *data, t_minimap *minimap);
int		logic_raycasting(t_data *data);
void	draw_line(t_data *data, t_point a1, t_point a2, int color);*/
int		parsing_map(t_data *data, char *file);
int		parsing_map_nxt(t_data *data, int ret, char *line, char **str);
int		it_s_ok_to_be_line(t_data *data, char *line);
int		get_colors(char *line, int x, t_color *color, t_data *data);
int		ft_is_digit(int c);
int		ft_atoii(const char *str, int x);
char	*get_the_line(char *line, int x, t_data *data);
int		is_it_direction(char *line, int x);
int		pars_error(int ret, t_data *data);
int		map_error(t_data *data);
int		shake_colors(t_color *color, t_data *data);
char	*ft_itoa(int n);
void	ft_bzero(void *s, size_t n);
char	*malicious(char *str);
char	*mali(char c);
char	*joi(char *s1, char *s2);
char	*join_fr(char *s1, char *s2);
int		ft_strlenn(char *str);
char	*print_error_null(char *msg);
int		print_error_to_free(char *msg);
int		petf(char *msg);
char	*cftp(char *str, int s, int e);
char	*cut_spaces(char *str);
int		parsing_mapy(char *str, char *src, t_file *file);
int		create_map(char *str, t_data *data);
int		str_c(char *str, char c);
void	init_file_nxt(t_file *file);
int		pars_error_map(int ret, t_data *data);
void	create_tab(t_file *file, char *str);
int		**cpy_tab(t_file *file, int **tmp);
int		**add_to_tab(int **tab, char *str, int stop, int size);
int		convert(char c);
int		ft_is_cap_alpha(int c);
double	player_pos(char c, t_file *file, int x, int y);
void	free_tab(int **tab, int size);
void	free_tab_bis(int **tab, int y);
void	free_all(t_data *data);
void	free_strings(t_file *file);
void	free_alll(t_file *file);
int		space(char *str);
int		check_map(t_data *data);
void	cpy_map_tab(t_file *file);
int		len_x(int **map, int y);
int		len_y(int **map);
void	parse_tab(t_file *file);
int		is_one_space(char *line, int x);
char	*cftp(char *str, int s, int e);
int		get_rgb_r(char *line, int x, t_color *color);
int		get_rgb_g(char *line, int x, t_color *color);
int		get_rgb_b(char *line, int x, t_color *color);
int		convert(char c);
double	player_pos(char c, t_file *file, int x, int y);
int		**malloc_one_tab(t_file *file);
void	check_wall(t_file *file);
void	check_space_nxt(t_file *file, int y, int x);
void	check_space_nxt_bis(t_file *file, int y, int x);
void	check_space(t_file *file);
void	is_one(t_file *file, int y, int x);
void	is_one_nxt(t_file *file, int y, int x);
void	is_one_nxt_nxt(t_file *file, int y, int x);
void	is_one_nxt_nxt_end(t_file *file, int y, int x);
void	put_err_msg(t_file *file, char *msg);
int		**err_in_add(t_file *file, int y, char *msg);
void	check_missing_pos(t_data *data);
void	transformers(t_file *file, int zone, int new);
void	err_in_bis(t_file *file, int y, char *msg);
int		ft_check(char *str);
char	*ft_read_suite(int fd, int n, char *strr, int *rid);
int		ft_read(char **str, int fd);
int		get_next_lineo(int fd, char **line, char **str);
char	*ft_nextline(char **str);
int		free_for_rtn(void *ptr, int rtn);
char	*lolilol(char **str, char *strr, int x, int y);
int		s_y_tab(int **tab, int stop);
int		s_x_tab(int **tab, int stop, int y);
char	**last_for_screen(t_data *data, int y, int x);
void	print_map(char **tab);
void	check_wall_bis(t_file *file);
void	cpy_tab_tab_bis(t_file *file);
int		big_len_y(int **map);
void	map_moins_un(t_file *file, int y, int x);
void	cpy_next(t_file *file, int y, char *msg);
void	is_two(t_file *file, int y, int x);
void	transformers_bis(t_file *file);
void	check_wall_bis(t_file *file);
void	check_space_nxt_b(t_file *file, int y, int x, int **tab);
void	check_space_nxt_bis_b(t_file *file, int y, int x, int **tab);
void	check_taby(t_file *file, int x, int y);
void	taby_y_x(t_file *file, int x, int y);
void	taby_y(t_file *file, int x, int y);
void	taby_x(t_file *file, int x, int y);
void	taby_else(t_file *file, int x, int y);
void	extra_long_if(t_file *file, int x, int y);
void	for_is_two(t_file *file);
void	find_stack(t_file *file);
int		verif(int **tab, int y, int x, t_file *file);
void	new_small_stack(t_file *file);
void	map_moins_un_b(t_file *file, int y, int x);
void	free_tabs(t_data *data);
void    free_mapy(t_data *data);
void	free_all_nxt(t_data *data);
void    all_in_struct(t_data *data);
void	cpy_tab_tab_bis(t_file *file);
void	print_file(t_data *data);
void	print_tab(int **tab, int stop);
void	draw_full_circle(t_data *data, int x, int y, int radius);
void	draw_background(t_data *data);
void	raycasting(t_data *data);
int		key_hook(int key, t_data *data);
int		end(t_data *data);
int		get_file_position(t_data *data, double x, double y);
int		failed(t_data *data, char *msg);

/////////////////////////////

void	not_real_data(t_data *data);
int		load_textures(t_data *data, t_args *args);

void	render_scene(t_data *data, t_screen *buff);
double	update_angle(double angle, double rotation);
void	calculate_wall_height(t_data *data, double angle, double tmp);
double	calculate_distance_to_wall(t_data *data, double angle);
double	detect_wall_distance_east(t_data *data);
double	detect_wall_distance_west(t_data *data);
double	detect_wall_distance_south(t_data *data);
double	detect_wall_distance_north(t_data *data);

void	draw_textured_column(t_data *data, t_screen *buff, int x, int y);
t_texture	*choose_texture(t_data *data);
double	calculate_hit_decimal(t_data *data);
char	check_hit(t_data *data, char hit, double x, double y);

double	sw(t_data *data, t_point decimal, double angle);
double	sw_1(t_data *data, t_point decimal, double angle);
double	sw_2(t_data *data, t_point decimal, double angle);
double	*sw_y(t_data *data, t_point decimal, double angle);
double	sw_y_1(t_data *data, t_point decimal, double angle);
double	*sw_x(t_data *data, t_point decimal, double angle);
double	sw_x_1(t_data *data, t_point decimal, double angle);

double	se(t_data *data, t_point decimal, double angle);
double	se_1(t_data *data, t_point decimal, double angle);
double	se_2(t_data *data, t_point decimal, double angle);
double	*se_y(t_data *data, t_point decimal, double angle);
double	se_y_1(t_data *data, t_point decimal, double angle);
double	*se_x(t_data *data, t_point decimal, double angle);
double	se_x_1(t_data *data, t_point decimal, double angle);

double	nw(t_data *data, t_point decimal, double angle);
double	nw_1(t_data *data, t_point decimal, double angle);
double	nw_2(t_data *data, t_point decimal, double angle);
double	*nw_y(t_data *data, t_point decimal, double angle);
double	nw_y_1(t_data *data, t_point decimal, double angle);
double	*nw_x(t_data *data, t_point decimal, double angle);
double	nw_x_1(t_data *data, t_point decimal, double angle);

double	ne(t_data *data, t_point decimal, double angle);
double	ne_1(t_data *data, t_point decimal, double angle);
double	ne_2(t_data *data, t_point decimal, double angle);
double	*ne_y(t_data *data, t_point decimal, double angle);
double	ne_y_1(t_data *data, t_point decimal, double angle);
double	*ne_x(t_data *data, t_point decimal, double angle);
double	ne_x_1(t_data *data, t_point decimal, double angle);

void	turn(int keycode, t_data *data);
void	move(int keycode, t_data *data);
void	keycode(int keycode, t_data *data);
int		next_frame(int keycode, t_data *data);

#endif
