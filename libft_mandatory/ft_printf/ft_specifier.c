/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:16:23 by ael-most          #+#    #+#             */
/*   Updated: 2024/11/18 15:48:52 by ael-most         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specifier(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(args, char *));
	else if (specifier == 'i' || specifier == 'd')
		count += ft_putnbr(va_arg(args, int));
	else if (specifier == 'u')
		count += ft_putnbr_unsigned(va_arg(args, unsigned int));
	else if (specifier == 'p')
		count += ft_putptr(va_arg(args, void *));
	else if (specifier == 'X')
		count += ft_putnbr_hex(va_arg(args, unsigned int), 1);
	else if (specifier == 'x')
		count += ft_putnbr_hex(va_arg(args, unsigned int), 0);
	else if (specifier == '%')
		count += ft_putchar('%');
	else
	{
		count += ft_putchar('%');
		count += ft_putchar(specifier);
	}
	return (count);
}
