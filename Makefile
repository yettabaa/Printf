# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/31 22:17:58 by yettabaa          #+#    #+#              #
#    Updated: 2022/11/05 22:58:55 by yettabaa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

MANDA = ft_printf.c ft_putc.c ft_puts.c ft_putnbr_u.c ft_putnbr.c ft_puthexa.c

BONUS = ft_printf_bonus.c ft_putc.c ft_puts.c ft_putnbr_u.c ft_putnbr_bonus.c ft_puthexa_bonus.c ft_puthexa.c

OBJM = $(MANDA:.c=.o)

OBON = $(BONUS:.c=.o)

NAME = libftprintf.a

all:	$(NAME)

%.o : %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJM)
		ar -rc $(NAME) $(OBJM)

bonus: $(OBON)
		ar -rc $(NAME) $(OBON)

clean:
		rm -f $(OBJM) $(OBON)

fclean:	clean
		rm -f $(NAME)
		
re: fclean all bonus
		