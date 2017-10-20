#ifndef FRACT_OL_H
# define FRACT_OL_H

# define NB_FRACTALS 1

# define IMAGE_WIDTH 900
# define IMAGE_HEIGHT 900

# define MANDELBROT_X1 -2.1
# define MANDELBROT_X2 0.6
# define MANDELBROT_Y1 -1.2
# define MANDELBROT_Y2 1.2

enum			e_fractal_type
{
	MANDELBROT = 0
};

enum			e_key_hook {
	ESC = 53,
	ARROW_LEFT = 123,
	ARROW_RIGHT = 124,
	ARROW_DOWN = 125,
	ARROW_UP = 126
};

enum	 		e_mouse_hook
{
	LEFT_CLICK = 1,
	RIGHT_CLICK,
	SCROLL_WHEEL_CLICK,
	SCROLL_WHEEL_ZOOM_IN,
	SCROLL_WHEEL_ZOOM_OUT,
	SCROLL_WHEEL_LEFT,
	SCROLL_WHEEL_RIGHT
};

typedef struct	s_offset
{
	unsigned int		x;
	unsigned int		y;
}				t_offset;

typedef struct	s_range
{
	double			min;
	double			max;
}				t_range;

typedef struct	s_complex
{
	double		real;
	double		imaginary;
}				t_complex;

typedef struct	s_rgb
{
	int					r;
	int					g;
	int					b;
}				t_rgb;

typedef struct	s_fractal
{
	enum e_fractal_type	type;
	t_rgb				color;
	double				zoom;
	t_range				abscissa;
	t_range				ordinate;
	// double				x; /* [0][1] -> (x1, y1)		[2][3] -> (x2, y2) */
	// double				y; /* [0][1] -> (x1, y1)		[2][3] -> (x2, y2) */
	unsigned int		iteration;
}				t_fractal;

typedef struct	s_mlx_img
{
	t_fractal			fractal;
	void				*img;
	char				*address;
	double				height;
	double				width;
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

void				fract_ol_put_pixel_img(t_mlx_img *img, t_offset offset, t_rgb);

int					fract_ol_mouse_hook(int button_code, int x, int y, t_env *e);
int					fract_ol_key_hook(int keycode, t_env *e);

int					fract_ol_error(const char *str);
int					fract_ol_create_image(t_env *e);
void				fract_ol_quit(t_env *e);


double				get_distance(double x2, double x1);


#endif

/*

|x| = |(0.6--2.1)|
|y| = |(-1.2-1.2)|

0		->	800
					/ 296.296         => x / coef - 2.1
0		->	2.7
(-2.1	->	0.6)

ex:
	720 / 296 - (x = )2.1 - (tocenter->)2.1 = -1.76
	720 / 296 - 1.76 -2.1 = - 1.42

Zoom sur 1pt en partic. :
x1 = x-h
x2 = x+h
y1 = y-h
y2 = y+h

*/
