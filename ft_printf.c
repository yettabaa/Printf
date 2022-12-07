/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 22:20:26 by yettabaa          #+#    #+#             */
/*   Updated: 2022/12/07 11:26:17 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	chek_ft_print(va_list ptr, int c)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putc(va_arg(ptr, int));
	else if (c == 's')
		i += ft_puts(va_arg(ptr, char *));
	else if (c == 'd' || c == 'i')
		i += ft_putnbr(va_arg(ptr, int));
	else if (c == 'u')
		i += ft_putnbr_u(va_arg(ptr, unsigned int));
	else if (c == 'x' || c == 'X')
		i += ft_puthexa(va_arg(ptr, unsigned int), c);
	else if (c == 'p')
	{
		i += ft_puts("0x");
		i += ft_puthexa(va_arg(ptr, unsigned long), 'x');
	}
	else if (c == '%')
		i += ft_puts("%");
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	ptr;

	if (write(1, "1337", 0) < 0)
		return (-1);
	i = 0;
	va_start(ptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			if (!(*(str + 1)))
				return (i);
			i += chek_ft_print(ptr, *(str + 1));
			str++;
		}
		else
			i += ft_putc(*str);
		str++;
	}
	va_end(ptr);
	return (i);
}
