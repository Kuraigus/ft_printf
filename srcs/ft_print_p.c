/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joguntij <joguntij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 14:41:21 by joguntij          #+#    #+#             */
/*   Updated: 2020/02/05 18:05:17 by joguntij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_output(char *str, t_flags flags)
{
	int	count;

	count = 0;
	count += ft_putsp("0x", 2);
	if (flags.dot >= 0)
	{
		count += ft_print_width(flags.dot, ft_strlen(str), 1);
		count += ft_putsp(str, flags.dot);
	}
	else
		count += ft_putsp(str, ft_strlen(str));
	return (count);
}

static int		ft_handle_p(t_flags flags)
{
	int	count;

	count = 0;
	if (flags.width >= 0 && flags.minus == 0)
	{
		count += ft_print_width(flags.width - 2, 0, 0);
		count += ft_putsp("0x", 2);
	}
	else
	{
		count += ft_putsp("0x", 2);
		count += ft_print_width(flags.width - 2, 0, 0);
	}
	return (count);
}

int				ft_print_p(size_t num, t_flags flags)
{
	char	*str;
	int		count;

	count = 0;
	if (flags.dot == 0 && !num)
	{
		return (ft_handle_p(flags));
	}
	str = ft_utl_base(num, 16);
	str = ft_str_to_lowercase(str);
	if ((size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		count += ft_output(str, flags);
	count += ft_print_width(flags.width, ft_strlen(str) + 2, 0);
	if (flags.minus == 0)
		count += ft_output(str, flags);
	free(str);
	return (count);
}
