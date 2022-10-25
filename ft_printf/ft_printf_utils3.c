/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-aless <md-aless@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 12:43:13 by md-aless          #+#    #+#             */
/*   Updated: 2022/04/01 15:58:46 by md-aless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	print_ptr(unsigned long long n)
{
	int	len;

	len = 0;
	len += write(1, "0x", 2);
	if (n == 0)
	{
		len += write(1, "0", 1);
		return (len);
	}
	else
	{
		ft_ptr_conv(n);
		len += ft_hex_len(n);
	}
	return (len);
}

void	ft_ptr_conv(unsigned long num)
{
	if (num >= 16)
	{
		ft_ptr_conv(num / 16);
		ft_ptr_conv(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + 48), 1);
		else
			ft_putchar_fd((num - 10 + 97), 1);
	}
}

int	lenght(int a, int b)
{
	int		count;

	count = 0;
	if (a <= 0)
		++count;
	while (a && ++count)
		a /= b;
	return (count);
}

char	*ft_itoa(int n)
{
	char	*x;
	int		len;
	char	*num;

	len = lenght(n, 10);
	x = malloc(sizeof(char) * (len + 1));
	if (!x)
		return (NULL);
	num = "0123456789";
	x[len] = '\0';
	if (n == 0)
		x[0] = '0';
	if (n < 0)
		x[0] = '-';
	while (n)
	{
		if (n > 0)
			x[--len] = num[n % 10];
		else
			x[--len] = num[n % 10 * -1];
		n /= 10;
	}
	return (x);
}
