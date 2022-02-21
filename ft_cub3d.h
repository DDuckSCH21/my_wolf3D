/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dduck <dduck@student.21-school.r>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 13:25:27 by dduck             #+#    #+#             */
/*   Updated: 2021/04/12 13:25:31 by dduck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUB3D_H
# define FT_CUB3D_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"

# define MAP_SYM_PL "2NSWE"
# define MAP_SYM_NW "02NSWE"
# define MAP_SYM "012NSWE "
# define MP_SPC "	 "
# define SPD_TR 0.04
# define SPMV 0.08

typedef struct	s_ray
{
	double		camerax;
	double		deltadistx;
	double		deltadisty;
	double		dirx;
	double		diry;
	int			drwstrt;
	int			drwnd;
	double		kf_res;
	int			mapx;
	int			mapy;
	double		plnx;
	double		planey;
	double		psx;
	double		psy;
	double		pwlld;
	double		rdrx;
	double		rdry;
	int			stpx;
	int			stpy;
	int			side;
	double		step;
	double		sidedistx;
	double		sidedisty;
	double		wall_x;
	int			x;
	double		zbuff[8000];
}				t_ray;

typedef	struct	s_sprite
{
	double		dist;
	int			drx;
	int			dry;
	int			drwsrtx;
	int			drwsrty;
	int			drwndx;
	int			drwndy;
	double		invdet;
	double		smapx;
	double		smapy;
	int			spr_h;
	int			spr_w;
	double		sposx;
	double		sposy;
	int			stex_x;
	int			stex_y;
	int			sprscrnx;
	double		trnsfrmx;
	double		trnsfrmy;
}				t_sprite;

typedef struct	s_config
{
	int			flag_done;

	char		**color_c;
	char		**color_f;
	int			res_w;
	int			res_h;
	int			color_c_rgb;
	int			color_f_rgb;
	int			count_lines;
}				t_config;

typedef struct	s_key
{
	int			up;
	int			down;
	int			right;
	int			left;
	int			rotat_left;
	int			rotat_right;
	int			esc;
}				t_key;

typedef struct	s_map
{
	int			cnt_sprt;
	int			count_spawn_player;
	char		**map;
	int			pl_x;
	int			pl_y;
	char		vector_eye;
}				t_map;

typedef struct	s_image
{
	char		*addr;
	int			bpp;
	int			img_h;
	int			img_w;
	int			line_len;
	void		*ptr;
	char		*txt_path;
	int			end;

}				t_image;

typedef struct	s_vars
{
	int			bpp;
	int			max_width;
	int			max_hight;
	int			mode_save;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			line_len;
	int			end;
	char		*filename_config;
	t_map		*map;
	t_image		artxt[5];
	t_config	*cnfg;
	t_key		*key;
	t_ray		*ray;
	t_sprite	**arspr;
	int			flag_frst;
	int			spr_d;
	double		pos;
	int			end_x_map;
}				t_vars;

void			ft_init_all(t_vars *vars);
int				ft_check_config(t_vars *vars);
int				ft_check_fileconfig(t_vars *vars, char *argv);
void			ft_check_null_config(int fd, char *line, t_vars *vars);
void			ft_check_resolution(t_vars *vars);
void			ft_check_processor(t_vars *vars);
void			ft_check_colorattach(t_vars *vars, char **colorattach);
void			ft_check_map(t_vars *vars, char **map);
int				ft_check_map_endline(t_vars *vars, char **map);
int				ft_count_lines(int fd, char *line, t_vars *vars);
void			ft_draw_line(t_vars *vars, t_ray *ray, int linehght, int i_tex);
void			ft_draw_sprite(t_ray *ray, t_vars *vars);
int				ft_game_over(t_vars *vars);
int				ft_get_count_sym(char *line, char c);
int				ft_get_rgb(t_vars *vars, char **colorattach);
void			ft_get_dirplayer(t_vars *vars, t_map *map);
int				ft_get_line(t_vars *vars);
int				ft_get_num(char *line, int endflag, t_vars *vars);
int				ft_get_pixel(int width, int hight, t_image img);
void			ft_get_sprites(t_vars *vars, char **map);
double			ft_get_tex_x(t_ray *ray, t_image img);
void			ft_get_wall_x(t_ray *ray);
void			ft_go(t_vars *vars);
void			ft_init_ray(t_ray *ray, t_vars *vars);
int				ft_key_press(int key, t_vars *vars);
int				ft_key_release(int key, t_vars *vars);
int				ft_main_draw_sprite(t_vars *vars);
void			ft_move(t_ray *ray, t_vars *vars);
int				ft_parse_player(t_vars *vars, char **map);
int				ft_play_game(t_vars *vars);
int				ft_put_error(t_vars *vars, char *error);
void			ft_putpixel_sprite(t_vars *vars, t_ray *ray, t_sprite *sprt);
int				ft_run_game(t_ray *ray, t_vars *vars);
int				ft_run_mlx(t_vars *vars);
int				ft_screen(t_vars *vars);
void			ft_side(t_ray *ray, t_map *map, t_vars *vars);
void			ft_size_sprite(t_ray *ray, t_sprite *sprt, t_config *config);
void			ft_sort_sprite(t_vars *vars);
int				ft_strstrchr(const char *dst, const char *srcs);
void			ft_turning(t_key *key, t_ray *ray);
int				ft_write_map(t_vars *vars, char *line, int i);
void			my_mlx_puxel_put(t_vars *vars, int x, int y, int color);

#endif
