/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:54:25 by fhuang            #+#    #+#             */
/*   Updated: 2017/11/02 19:01:24 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <pthread.h>

# define NB_FRACTALS 3
# define NB_COLORS 6

# define IMAGE_SIZE 645

# define ITERATIONS 50
# define MAX_ITERATIONS 300
# define NB_THREADS 12

# define FPS 20

# define MANDELBROT_X1 -2.1
# define MANDELBROT_X2 0.6
# define MANDELBROT_Y1 -1.2
# define MANDELBROT_Y2 1.2

# define JULIA_X1 -1.3
# define JULIA_X2 2.2
# define JULIA_Y1 -1.6
# define JULIA_Y2 0.7
# define JULIA_INITIAL_REAL -1.0
# define JULIA_INITIAL_IMAGINARY 0.0

# define BURNING_SHIP_X1 -2.3
# define BURNING_SHIP_X2 1
# define BURNING_SHIP_Y1 -2
# define BURNING_SHIP_Y2 2

# define IMAGE_LOCK	(1 << 0)

enum				e_fractal_type
{
	MANDELBROT = 0,
	JULIA,
	BURNING_SHIP
};

enum				e_fractal_color
{
	F_BW = 0,
	F_RANDOM_1,
	F_PINK,
	F_RED,
	F_GREEN,
	F_BLUE
};

enum				e_key_hook
{
	KEY_L = 37,
	KEY_C = 8,
	KEY_N = 45,
	KEY_P = 35,
	KEY_R = 15,
	ESC = 53,
	ARROW_LEFT = 123,
	ARROW_RIGHT = 124,
	ARROW_DOWN = 125,
	ARROW_UP = 126
};

enum				e_mouse_hook
{
	LEFT_CLICK = 1,
	RIGHT_CLICK,
	SCROLL_WHEEL_CLICK,
	SCROLL_WHEEL_ZOOM_IN,
	SCROLL_WHEEL_ZOOM_OUT,
	SCROLL_WHEEL_LEFT,
	SCROLL_WHEEL_RIGHT
};

typedef struct		s_offset
{
	unsigned int			x;
	unsigned int			y;
}					t_offset;

typedef struct		s_range
{
	double					min;
	double					max;
}					t_range;

typedef struct		s_complex
{
	long double				real;
	long double				imaginary;
}					t_complex;

typedef struct		s_rgb
{
	int						r;
	int						g;
	int						b;
}					t_rgb;

typedef struct		s_fractal
{
	enum e_fractal_type		type;
	long double				zoom;
	t_range					abscissa;
	t_range					ordinate;
	t_complex				motion_complex;
	int						iteration;
}					t_fractal;

typedef struct		s_mlx_img
{
	void					*img;
	char					*address;
	double					size;
	int						bits_per_pixel;
	int						size_line;
	int						endian;
	t_rgb					rgb;
	enum e_fractal_color	color;
}					t_mlx_img;

typedef struct		s_draw_helper
{
	t_offset				offset;
	t_offset				range;
	t_mlx_img				*img;
	t_fractal				fractal;
	void					(*f)(struct s_draw_helper*, t_complex, t_complex);
}					t_draw_helper;

typedef struct		s_env
{
	void					*mlx;
	void					*win;
	pthread_t				thread[NB_THREADS];
	t_mlx_img				mlx_img;
	int						number_of_fractals;
	int						index;
	int						screen_cut_size;
	int						nb_screen_cut;
	t_fractal				*fractals;
	int						state;
}					t_env;

/*
**	BASIC
*/

void				fract_ol_quit(t_env *e);
int					init(t_env *e, const char **av);
void				init_fractal_parameters(t_fractal *fractal);

enum e_fractal_type	get_fractal_type(const char *name);
const char			*get_fractal_name(enum e_fractal_type type);

/*
**	HOOK
*/

int					fract_ol_mouse_hook(
						int button_code, int x, int y, t_env *e);
int					fract_ol_key_hook(int keycode, t_env *e);
int					fract_ol_motion_hook(int x, int y, t_env *e);

/*
**	HOOK CALLBACKS
*/

void				zoom_in(t_env *e, const int x, const int y);
void				zoom_out(t_env *e, const int x, const int y);

void				translate_left(t_env *e);
void				translate_right(t_env *e);
void				translate_up(t_env *e);
void				translate_down(t_env *e);

void				reset_parameters(t_env *e);

/*
**	DRAW IMAGE
*/

int					fract_ol_create_image(t_env *e);
void				put_pixel_in_fractal(
						t_mlx_img *mlx_img, t_fractal fractal,
						t_offset offset, int i);

void				draw_corresponding_fractal(
						t_draw_helper *helper, pthread_t *thread);

void				draw_mandelbrot(
						t_draw_helper *helper, t_complex z, t_complex c);
void				draw_julia(t_draw_helper *helper, t_complex z, t_complex c);
void				draw_burning_ship(
						t_draw_helper *helper, t_complex z, t_complex c);

#endif

/*
** BONUS:
** 	-	Color -> todo
** 	-	Deplacements
** 	-	Multi fractals
** 	-	Lock image + text on image
** 	-	Multi threads
*/
