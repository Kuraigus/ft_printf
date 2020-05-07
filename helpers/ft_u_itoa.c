/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_itoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joguntij <joguntij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 16:45:57 by joguntij          #+#    #+#             */
/*   Updated: 2020/02/05 18:12:21 by joguntij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.h"

char			*ft_u_itoa(unsigned int n)
{
	int					len;
	char				*str;
	unsigned int		num;

	len = n == 0 ? 1 : 0;
	num = n;
	while (num)
	{
		num /= 10;
		len++;
	}
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}
