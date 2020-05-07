/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joguntij <joguntij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:19:58 by joguntij          #+#    #+#             */
/*   Updated: 2020/02/05 18:13:18 by joguntij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include "../helpers/helpers.h"

typedef struct	s_flags
{
	int			minus;
	int			dot;
	int			star;
	int			zero;
	int			width;
	int			type;
}				t_flags;

t_flags			ft_digit_flag(char c, t_flags flags);
t_flags			ft_minus_flag(t_flags flags);
t_flags			ft_width_flag(va_list args, t_flags flags);
int				ft_printf(const char *format, ...);
int				ft_dot_flag(const char *str, int start, va_list args,
							t_flags *flags);
int				ft_print_p(size_t num, t_flags flags);
char			*ft_base(size_t nbr, int base, int count, char *str);
int				ft_print_x(unsigned int num, int lowercase, t_flags flags);
int				ft_print_s(char *str, t_flags flags);
int				ft_print_int(int i, t_flags flags);
int				ft_print_u(unsigned int num, t_flags flags);
int				ft_print_c(char c, t_flags flags);
int				ft_handle_input(const char *str, va_list args);
int				ft_print_width(int width, int minus, int zero);
int				ft_isconversion(int c);
int				ft_isflag(int c);
int				ft_print_percent(t_flags flags);
int				ft_handle(int c, t_flags flags, va_list args);

#endif
