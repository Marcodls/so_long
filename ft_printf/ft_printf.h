/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md-aless <md-aless@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 16:11:20 by md-aless          #+#    #+#             */
/*   Updated: 2022/04/01 15:58:28 by md-aless         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		flags(const char c, va_list param);
int		ft_num_len(unsigned int n);
int		ft_printf(const char *a, ...);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_printnbr(int n);
char	*ft_uitoa(unsigned int n);
int		ft_print_unsigned(unsigned int n);
int		ft_uprintnbr(int n);
int		print_hex(unsigned int n, const char format);
void	ft_converter(unsigned int n, const char format);
int		ft_hex_len(unsigned long num);
int		print_ptr(unsigned long long n);
void	ft_ptr_conv(unsigned long num);
void	ft_putchar_fd(char c, int fd);
char	*ft_itoa(int n);
#endif