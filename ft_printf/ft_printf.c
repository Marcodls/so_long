/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-aless <md-aless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:22:33 by md-aless          #+#    #+#             */
/*   Updated: 2022/02/01 12:11:23 by md-aless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list c)
{
	char	buff;

	buff = va_arg(c, int);
	return (ft_putchar(buff));
}

int	flags(const char c, va_list param)
{
	if (c == 'c')
		return (print_char(param));
	else if (c == 's')
		return (ft_putstr(va_arg(param, char *)));
	else if (c == 'p')
		return (print_ptr(va_arg(param, unsigned long)));
	else if (c == 'd')
		return (ft_printnbr(va_arg(param, int)));
	else if (c == 'i')
		return (ft_printnbr(va_arg(param, int)));
	else if (c == 'u')
		return (ft_print_unsigned(va_arg(param, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (print_hex(va_arg(param, unsigned int), c));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *a, ...)
{
	va_list	params;
	int		i;
	int		count;

	va_start(params, a);
	i = 0;
	count = 0;
	if (!a)
		return (count);
	while (a[i])
	{
		if (a[i] == '%')
		{
			count += flags(a[++i], params);
			i++;
			continue ;
		}
		else
			count++;
		ft_putchar(a[i]);
		i++;
	}
	return (count);
}
