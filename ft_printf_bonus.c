/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:20:26 by yettabaa          #+#    #+#             */
/*   Updated: 2022/11/06 00:52:19 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	chek_ft_print(va_list ptr, char f, char c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putc(va_arg(ptr, int));
	else if (c == 's')
		i += ft_puts(va_arg(ptr, char *));
	else if (c == 'd' || c == 'i')
		i += ft_putnbr_bonus(va_arg(ptr, int), f);
	else if (c == 'u')
		i += ft_putnbr_u(va_arg(ptr, unsigned int));
	else if (c == 'x' || c == 'X')
		i += ft_puthexa_bonus(va_arg(ptr, unsigned int), c, f);
	else if (c == 'p')
	{
		i += ft_puts("0x");
		i += ft_puthexa(va_arg(ptr, unsigned long), 'x');
	}
	else if (c == '%')
		i += ft_puts("%");
	return (i);
}

static	int	chek_bonus(va_list ptr, const char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == '%')
		{
			if (!(*(s + 1)))
				return (i);
			if (*(s + 1) == ' ' || *(s + 1) == '#' || *(s + 1) == '+')
			{
				while (*(s + 1) == ' ' || *(s + 1) == '#' || *(s + 1) == '+')
					s++;
				i += chek_ft_print(ptr,*s, *(s + 1));
			}
			else
				i += chek_ft_print(ptr,*(s + 1), *(s + 1));
			s++;
		}
		else
			i += ft_putc(*s);
		s++;
	}
	return (i);
}

#include <stdio.h>

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ptr;

	if (write(1, "1337", 0) < 0)
		return (-1);
	va_start(ptr, str);
	i = chek_bonus(ptr, str);
	va_end(ptr);
	return (i);
}


void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		write(fd, "-", 1);
		nb *= -1;
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
}
#include<assert.h>

int main()
{
    // ft_putnbr(c);
    close(STDOUT_FILENO);
    // int i = ft_printf("%s", "abc");
    // int j = printf("%s", "abc");
	// ft_putnbr_fd(j, STDERR_FILENO);
	// ft_putnbr_fd(i, STDERR_FILENO);
    // printf("%d\n",ft_printf("% d\n", c));
    // printf("%d\n",printf("% d\n", c));
    // ft_puthexa(476645396,'x');
	assert(printf("f") ==-1);
	
}