# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joguntij <joguntij@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 16:28:47 by joguntij          #+#    #+#              #
#    Updated: 2020/02/01 01:59:31 by joguntij         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

SRCS = 	ft_printf.c srcs/ft_print_p.c srcs/ft_print_s.c srcs/ft_print_u.c srcs/ft_print_x.c srcs/ft_print_int.c srcs/ft_print_width.c srcs/ft_flags.c \
		srcs/ft_handle.c srcs/ft_print_c.c srcs/ft_print_percent.c \
		helpers/ft_isdigit.c helpers/ft_isupper.c helpers/ft_itoa.c helpers/ft_putchar.c helpers/ft_putsp.c helpers/ft_str_to_lowercase.c \
		helpers/ft_strdup.c helpers/ft_strlen.c helpers/ft_tolower.c helpers/ft_u_itoa.c helpers/ft_utl_base.c

OBJECTS = ft_printf.o ft_print_p.o ft_print_s.o ft_print_u.o ft_print_x.o ft_print_int.o ft_print_width.o ft_flags.o \
		ft_handle.o ft_print_c.o ft_print_percent.o \
		ft_isupper.o ft_itoa.o ft_putchar.o ft_putsp.o ft_str_to_lowercase.o ft_strdup.o ft_strlen.o ft_tolower.o ft_u_itoa.o ft_utl_base.o ft_isdigit.o


INCLUDES = includes/ft_printf.h


all: $(NAME)

$(NAME): $(OBJECTS)

$(OBJECTS): $(SRCS) $(INCLUDES)
	@gcc -Wextra -Werror -Wall -c $(SRCS)
	@ar rcs $(NAME) $(OBJECTS)

clean:
	@rm -rf $(OBJECTS)
	
fclean: clean
	@rm -rf $(NAME)

re: fclean all