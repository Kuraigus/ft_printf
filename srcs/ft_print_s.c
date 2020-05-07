/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joguntij <joguntij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:40:33 by joguntij          #+#    #+#             */
/*   Updated: 2020/02/05 18:06:01 by joguntij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_output(char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.dot >= 0)
	{
		count += ft_print_width(flags.dot, ft_strlen(str), 0);
		count += ft_putsp(str, flags.dot);
	}
	else
		count += ft_putsp(str, ft_strlen(str));
	return (count);
}

int				ft_print_s(char *str, t_flags flags)
{
	int count;

	count = 0;
	if (!str)
		str = ("(null)");
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		count += ft_output(str, flags);
	if (flags.dot >= 0)
		count += ft_print_width(flags.width, flags.dot, 0);
	else
		count += ft_print_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		count += ft_output(str, flags);
	return (count);
}
