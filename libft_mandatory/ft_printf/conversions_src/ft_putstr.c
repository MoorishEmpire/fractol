/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-most <ael-most@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 18:49:04 by ael-most          #+#    #+#             */
/*   Updated: 2024/11/18 15:44:36 by ael-most         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr(char *str)
{
	int	count;

	if (!str)
		str = "(null)";
	count = 0;
	while (*str)
		count += ft_putchar(*str++);
	return (count);
}
