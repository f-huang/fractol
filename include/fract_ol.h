#ifndef FRACT_OL_H
# define FRACT_OL_H

# define NB_FRACTALS 1

enum			e_fractal_type
{
	MANDELBROT = 0
};

enum			e_key_hook {
	ESC = 256
};

enum	 		e_mouse_hook
{
	LEFT_CLICK = 1, RIGHT_CLICK,\
	SCROLL_WHEEL_CLICK, SCROLL_WHEEL_ZOOM_IN, SCROLL_WHEEL_ZOOM_OUT,\
	SCROLL_WHEEL_LEFT, SCROLL_WHEEL_RIGHT
};

typedef struct	s_fractal
{
	enum e_fractal_type	type;
	double				zoom;
	double				coord[4]; /* [0][1] -> (x1, y1)		[2][3] -> (x2, y2) */
	int					iteration;
}				t_fractal;

typedef struct	s_mlx_img
{
	t_fractal			fractal;
	void				*img;
	char				*address;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}				t_mlx_img;

typedef struct	s_env
{
	void				*mlx;
	void				*win;
	t_mlx_img			mlx_img;
}				t_env;

enum e_fractal_type	fract_ol_name_to_type(const char *name);
const char			*get_fractal_type_name(enum e_fractal_type type);

int					fract_ol_mouse_hook(int button, int x, int y, void *param);
int					fract_ol_key_hook(int keycode, void *param);

int					fract_ol_error(const char *str);
int					fract_ol_create_image(t_env *e);

#endif