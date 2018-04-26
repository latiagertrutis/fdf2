/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrodrigu <mrodrigu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 19:05:37 by mrodrigu          #+#    #+#             */
/*   Updated: 2018/04/26 07:53:52 by mrodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <math.h>
# include <errno.h>
# include "mlx.h"
# include "get_next_line.h"

# define W_WIDTH	1920
# define W_HEIGHT	1080
# define ZOOM		2.0
# define TRASLATION	50.0
# define ANG		10.0

# ifdef linux
#  define K_ESC 65307
#  define K_SPACE 32
#  define K_MINUS 45
#  define K_PLUS 61
#  define K_A 97
#  define K_W 119
#  define K_D 100
#  define K_S 115
#  define K_L_ARR 65361
#  define K_U_ARR 65362
#  define K_R_ARR 65363
#  define K_D_ARR 65364
#  define K_POINT 46
#  define K_SLASH 47
#  define K_P1 49
#  define K_P2 19
#  define K_N 110
#  define K_M 109
#  define K_R 15
# endif

# ifdef __APPLE__
#  define K_ESC 53
#  define K_SPACE 49
#  define K_MINUS 27
#  define K_PLUS 24
#  define K_A 0
#  define K_W 13
#  define K_D 2
#  define K_S 1
#  define K_L_ARR 123
#  define K_U_ARR 126
#  define K_R_ARR 124
#  define K_D_ARR 125
#  define K_POINT 47
#  define K_SLASH 44
#  define K_P1 18
#  define K_P2 19
#  define K_N 45
#  define K_M 46
#  define K_R 15
# endif

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	struct s_point	*next;
}					t_point;

typedef struct		s_2dp
{
	double				x;
	double				y;
	double				z;
}					t_2dp;

typedef struct		s_2dpi
{
	int				x;
	int				y;
	int				z;
}					t_2dpi;

typedef struct		s_legend
{
	void		*win_id;
	void		*img_ptr;
	char		*img;
	int			ang_x;
	int			ang_y;
	int			ang_z;
	char		p1;
	char		p2;
}					t_legend;

typedef struct		s_win
{
	void		*mlx_id;
	void		*win_id;
	void		*img_ptr;
	char		*img;
	t_2dpi		**map;
	int			map_wid;
	int			map_hei;
	int			map_max;
	int			map_min;
	t_2dp		coord_x;
	t_2dp		coord_y;
	t_2dp		coord_z;
	t_2dp		origin;
	t_legend	legend;
}					t_win;

t_point				*input_reader(char *file);
void				success(char *message);
void				exit_failure(char *motive);
t_win				*window(void *mlx_id, t_point *map);
void				hooks(t_win *win);
int					key_pressed(int keycode, t_win *win);
int					leave_program(int keycode, t_win *win);
void				print_map(t_point *map);
void				line_interpret(t_win *win, t_2dpi p0, t_2dpi pf);
void				resize_point(t_2dp *p, double cuant);
void				traslate_point(t_2dp *p, double x, double y);
void				rotate_point(t_2dp *p, double x, double y, double z);
void				draw_line(t_win *win, t_2dpi ini_p0, t_2dpi p0, t_2dpi pf);
void				line_writter(t_win *win);
void				create_image(t_win *win);
void				project_point(t_win *win, t_2dpi *p);
void				put_legend(t_win *win);
void				update_legend(t_win *win);
void				restart(t_win *win);
void				end_fdf(void);
void				free_list_map(t_point *map);
#endif
