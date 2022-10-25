/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-aless <md-aless@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:09:55 by md-aless          #+#    #+#             */
/*   Updated: 2022/02/01 11:58:52 by md-aless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printnbr(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_putstr(num);
	free(num);
	return (len);
}

int	ft_putstr(char *str)
{
	char	c;
	int		i;

	i = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (str[i] != '\0')
	{
		c = str[i];
		write (1, &c, 1);
		i++;
	}
	return (i);
}

void	ft_converter(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_converter(n / 16, format);
		ft_converter(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + 48, 1);
		else
		{
			if (format == 'X')
				ft_putchar_fd(n - 10 + 65, 1);
			if (format == 'x')
				ft_putchar_fd(n - 10 + 97, 1);
		}
	}
}

int	ft_hex_len(unsigned long num)
{
	int	l;

	l = 0;
	while (num != 0)
	{
		l++;
		num = num / 16;
	}
	return (l);
}
