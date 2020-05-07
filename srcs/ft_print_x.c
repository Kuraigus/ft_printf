/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joguntij <joguntij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 18:38:59 by joguntij          #+#    #+#             */
/*   Updated: 2020/02/05 17:59:55 by joguntij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

static int	ft_output(char *hex, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.dot >= 0)
		count += ft_print_width(flags.dot - 1, ft_strlen(hex) - 1, 1);
	count += ft_putsp(hex, ft_strlen(hex));
	return (count);
}

static int	ft_put_hex(char *hex, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count += ft_output(hex, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hex))
		flags.dot = ft_strlen(hex);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_print_width(flags.width, 0, 0);
	}
	else
		count += ft_print_width(flags.width, ft_strlen(hex), flags.zero);
	if (flags.minus == 0)
		count += ft_output(hex, flags);
	return (count);
}

int			ft_print_x(unsigned int num, int lowercase, t_flags flags)
{
	char	*hex;
	int		count;

	count = 0;
	num = (unsigned int)(4294967295 + 1 + num);
	if (flags.dot == 0 && num == 0)
	{
		count += ft_print_width(flags.width, 0, 0);
		return (count);
	}
	hex = ft_utl_base(num, 16);
	if (lowercase == 1)
		hex = ft_str_to_lowercase(hex);
	count += ft_put_hex(hex, flags);
	free(hex);
	return (count);
}
