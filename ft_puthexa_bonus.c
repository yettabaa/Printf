/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:10:00 by yettabaa          #+#    #+#             */
/*   Updated: 2022/12/07 11:26:11 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	ft_putbase(unsigned long n, char *str)
{
	int	i;

	i = 0;
	if (n >= 16)
		i += ft_putbase(n / 16, str);
	i += ft_putc(str[n % 16]);
	return (i);
}

int	ft_puthexa_bonus(unsigned long n, char c, char f)
{
	int		i;
	char	*str;

	i = 0;
	if (n == 0 && f == '#')
		return (ft_putc('0'));
	if (f == '#' && c == 'x')
		i += ft_puts("0x");
	else if (f == '#' && c == 'X')
		i += ft_puts("0X");
	if (c == 'x')
		str = "0123456789abcdef";
	if (c == 'X')
		str = "0123456789ABCDEF";
	i += ft_putbase(n, str);
	return (i);
}
