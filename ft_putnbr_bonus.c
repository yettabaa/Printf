/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yettabaa <yettabaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 21:16:39 by yettabaa          #+#    #+#             */
/*   Updated: 2022/12/07 11:26:02 by yettabaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_bonus(int n, char c)
{
	int		i; 
	long	nb;

	nb = n;
	i = 0;
	if(nb < 0)
	{
		i += ft_putc('-');
		nb *= -1;
	}
	else if(c == ' ' || c == '+')
	{
		if (c == ' ')
			ft_putc(' ');
		else
			ft_putc('+');
		i++;
	}    
	if (nb > 9)
		i += ft_putnbr_bonus(nb / 10, 'o');
	i += ft_putc((nb % 10) + '0');
	return (i);
}
