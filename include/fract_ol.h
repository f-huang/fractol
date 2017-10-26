#ifndef FRACT_OL_H
# define FRACT_OL_H

# include <pthread.h>

# define NB_FRACTALS 1

# define IMAGE_SIZE 644

# define ITERATIONS 100
# define MAX_ITERATIONS 1500
# define NB_THREADS 12

# define FPS 20

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
	long double		real;
	long double		imaginary;
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
	long double			zoom;
	t_range				abscissa;
	t_range				ordinate;
	int					iteration;
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

typedef struct	s_draw_helper
{
	t_offset	offset;
	t_offset	range;
	t_mlx_img	*img;
}				t_draw_helper;

typedef struct	s_env
{
	void				*mlx;
	void				*win;
	pthread_t			thread[NB_THREADS];
	pthread_mutex_t		mutex;
	t_mlx_img			mlx_img;
}				t_env;


int					fract_ol_error(const char *str);
void				fract_ol_quit(t_env *e);
int					init_threads(pthread_t **thread);


int					fract_ol_mouse_hook(int button_code, int x, int y, t_env *e);
int					fract_ol_key_hook(int keycode, t_env *e);


enum e_fractal_type	fract_ol_name_to_type(const char *name);
const char			*get_fractal_type_name(enum e_fractal_type type);

int					fract_ol_create_image(t_env *e);
void				put_pixel_in_fractal(t_mlx_img *mlx_img, t_offset offset, int i);
void				fract_ol_put_pixel_img(t_mlx_img *img, t_offset offset, t_rgb);

double				get_distance(double x2, double x1);

void				zoom_in(t_env *e, const int x, const int y);
void				zoom_out(t_env *e, const int x, const int y);

#endif
