/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joguntij <joguntij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:16:15 by joguntij          #+#    #+#             */
/*   Updated: 2020/02/01 01:53:03 by joguntij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "helpers.h"

char	*ft_strdup(const char *s1)
{
	size_t		tam;
	char		*new_string;
	size_t		i;

	tam = ft_strlen(s1);
	new_string = (char*)malloc((sizeof(char) * tam) + 1);
	if (new_string == NULL)
		return (NULL);
	i = 0;
	while (i < tam)
	{
		new_string[i] = s1[i];
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
