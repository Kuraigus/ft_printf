/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joguntij <joguntij@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:05:49 by joguntij          #+#    #+#             */
/*   Updated: 2020/02/05 18:09:37 by joguntij         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_H
# define HELPERS_H

# include <stdlib.h>
# include <unistd.h>

int		ft_putchar(char c);
char	*ft_itoa(int n);
char	*ft_str_to_lowercase(char *str);
char	*ft_strdup(const char *s1);
char	*ft_utl_base(size_t nbr, int base);
int		ft_isupper(int c);
int		ft_putsp(char *str, int len);
int		ft_tolower(int c);
size_t	ft_strlen(const char *s);
char	*ft_u_itoa(unsigned int n);
int		ft_isdigit(int c);

#endif
