/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhuang <fhuang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/02 23:13:27 by fhuang            #+#    #+#             */
/*   Updated: 2017/04/17 00:44:56 by fhuang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <locale.h>
# include <stdbool.h>
# include <limits.h>

# include "libft.h"

# define TYPES_PAT "sSpdDiboOuUxXcC"
# define FLAGS_PAT "#0-+ "
# define MODIFIERS_PAT "hljz"
# define HASH 0
# define ZERO 1
# define MINUS 2
# define PLUS 3
# define SPACE 4

# define E_TYPE link->e_types
# define U_VAR link->u_var
# define C link->c
# define FLAG link->flags
# define LEN link->len
# define PRECISION link->precision
# define WIDTH link->width
# define RET link->transformed_str
# define NEXT link->next
# define NEXT_ARG link->next_arg

# define PUSH_BACK(c, n) push_char_back(link, str, c, n)
# define PUSH_FRONT(c, n) push_char_front(link, str, c, n)

# define MASK1 "0xxxxxxx"
# define MASK2 "110xxxxx10xxxxxx"
# define MASK3 "1110xxxx10xxxxxx10xxxxxx"
# define MASK4 "11110xxx10xxxxxx10xxxxxx10xxxxxx"

/*
**	# -> c, d ,i, p, s -> NO EFFECT
**	  -> o -> force a 0 before
**	  -> xX -> force a 0x before
**	  -> f -> force a decimal point after
**
**	0 -> if precision with d, i, o, u, x/X  OR '-' -> NO EFFECT
**	  -> 0 padding instead blanks
**
**	+ -> if ' ' -> NO EFFECT
**    -> put the sign
**
** ' ' -> only on signed (d, i ,f) and positive numbers
**
**  Precision	 >>> 0
**      -		 >>> 0
**      +		 >>> ' '
*/

typedef enum			e_color
{
	T_RED, T_GREEN, T_YELLOW, T_BLUE, T_MAGENTA, T_CYAN
}						t_color;

typedef enum			e_types
{
	T_SHORT, T_USHORT, T_CHAR, T_UCHAR,\
	T_WCHAR, T_STR, T_WSTR,\
	T_VOID,\
	T_INT, T_UIN, T_INMAX, T_UINMAX,\
	T_LONG, T_LLONG, T_ULONG, T_ULLONG
}						t_types;

typedef union			u_var
{
	wchar_t				wc;
	char				*s;
	wchar_t				*ws;
	void				*p;
	int					i;
	intmax_t			imax;
	uintmax_t			uinmax;
	long				l;
	long long			ll;
	unsigned int		uin;
	unsigned long		ul;
	unsigned long long	ull;
}						t_var;

typedef struct			s_printf
{
	t_var				u_var;
	t_types				e_types;
	char				c;
	bool				flags[5];
	int					len;
	int					width;
	int					precision;
	char				*transformed_str;
	struct s_printf		*next;
	struct s_printf		*next_arg;
}						t_printf;

typedef struct			s_ft_printf_env
{
	va_list				ap;
	t_printf			*full_lst;
	t_printf			*arg_lst;
}						t_ft_printf_env;

int						ft_printf(const char *format, ...);
int						ft_printf_fd(int fd, const char *format, ...);
/*
** void					debug(t_printf *link, int *modifier);
*/

/*
**	SMALL FUNCTIONS
*/

char					*ft_printf_itoa_base(int n, int base, bool is_uin);
char					*ft_ctoa_base(char n, int base, bool is_uin, bool *is_neg);
char					*ft_stoa_base(short n, int base, bool is_uin, bool *is_neg);
char					*ft_ltoa_base(long n, int base, bool is_uin);
char					*ft_lltoa_base(long long n, int base, bool is_uin);

/*
**	ENV
*/

void					init_ft_printf_env(t_ft_printf_env *e);
void					destroy_ft_printf_env(t_ft_printf_env *e);

/*
**	LIST
*/

void					add_link(t_ft_printf_env *e, t_printf *new, bool arg);
int						new_link(t_ft_printf_env *e, char *str, char *type, bool arg);

/*
 **	PARSE FORMAT
*/

char					*get_color(t_ft_printf_env *e, char *str);
void					desactivate_flags(t_printf *link, char type);
void					get_type_int(t_printf *link, int *modifier, char type);
int						get_type(t_printf *link, int *modifier, char type);
int						get_struct(t_printf *link, char *str, char type, int i);
int						read_str(t_ft_printf_env *e, char *str);
void					no_type_conversion(t_printf *link);

/*
**	TRANSFORM
*/
void					transform_plus(t_printf *link, char *str,\
							int len, bool neg);
void					transform_space(t_printf *link, char *str,\
							int len, bool neg);
void					transform_hash(t_printf *link, char *str,\
							int len, bool neg);
void					transform_minus(t_printf *link, char *str,\
							int len, bool neg);
void					transform_zero(t_printf *link, char *str,\
							int len, bool neg);
unsigned char			*transform_wstr(t_printf *link, wchar_t *wstr);

void					read_and_transform_arg(t_ft_printf_env *e);
void					transform_for_numbers(t_printf *link);
void					transform_for_strings(t_printf *link);
void					push_char_front(t_printf *link, char *str,\
							char c, int n);
void					push_char_back(t_printf *link, char *str, char c, int n);

/*
**	PRINT
*/
int						print_entire_list(t_ft_printf_env *e, int fd);

#endif
