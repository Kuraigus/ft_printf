/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joguntij <joguntij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:46:09 by joguntij          #+#    #+#             */
/*   Updated: 2020/02/05 18:01:07 by joguntij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

static int	ft_output(char *str, int num, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.dot >= 0 && num < 0 && num != -2147483648)
		ft_putchar('-');
	if (flags.dot >= 0)
		count += ft_print_width(flags.dot - 1, ft_strlen(str) - 1, 1);
	count += ft_putsp(str, ft_strlen(str));
	return (count);
}

static int	ft_put_int(char *str, int num, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count += ft_output(str, num, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_print_width(flags.width, 0, 0);
	}
	else
		count += ft_print_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		count += ft_output(str, num, flags);
	return (count);
}

int			ft_print_int(int i, t_flags flags)
{
	int		count;
	char	*str;
	int		num;

	count = 0;
	num = i;
	if (flags.dot == 0 && i == 0)
	{
		count += ft_print_width(flags.width, 0, 0);
		return (count);
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1) && num != -2147483648)
	{
		if (flags.dot < 0 && flags.zero == 1)
			ft_putsp("-", 1);
		i *= -1;
		flags.zero = 1;
		flags.width--;
		count++;
	}
	str = ft_itoa(i);
	count += ft_put_int(str, num, flags);
	free(str);
	return (count);
}
