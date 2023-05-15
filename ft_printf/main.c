/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeomin <yeomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:42:15 by yeomin            #+#    #+#             */
/*   Updated: 2023/05/14 15:23:30 by yeomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_dec_print(unsigned long long ll_num, const char format)
{
	if (ll_num < 10)
	{
		if (ft_putchar(ll_num + 48) == -1)
			return (-1);
		return (0);
	}
	else
	{
		if (ft_dec_print(ll_num / 10, format) == -1)
			return (-1);
	}
	ft_dec_print(ll_num % 10, format);
	return (0);
}

int	ft_lln_print(unsigned long long ll_n, const char format)
{
	if (ll_n >= 0 && ll_n <= 9)
	{
		if (ft_putchar(ll_n + 48) == -1)
			return (-1);
	}
	else if (ll_n >= 10 && ll_n <= 15)
	{
		if (format == 'X')
		{
			if (ft_putchar(ll_n + 55) == -1)
				return (-1);
		}
		else if (format == 'x')
		{
			if (ft_putchar(ll_n + 87) == -1)
				return (-1);
		}
	}
	return (0);
}

int	ft_hex_print(unsigned long long ll_n, const char format)
{
	if (ll_n < 16)
	{
		if (ft_lln_print(ll_n, format) == -1)
			return (-1);
		return (0);
	}
	else
	{
		if (ft_hex_print(ll_n / 16, format) == -1)
			return (-1);
	}
	ft_hex_print(ll_n % 16, format);
	return (0);
}

int	ft_format_check(va_list *ap, const char format)
{
	int	print_len;

	if (format == 'i' || format == 'd' || format == 'u')
		print_len = ft_idu_check(ap, format);
	else if (format == 'c' || format == 's')
		print_len = ft_c_and_s_check(ap, format);
	else if (format == 'p')
		print_len = ft_p_check(ap, format);
	else
		print_len = ft_x_check(ap, format);
	return (print_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		count;
	int		print_len;

	i = -1;
	count = 0;
	print_len = 0;
	va_start(ap, format);
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			i++;
			print_len = ft_putchar('%');
		}
		else if (format[i] == '%')
			print_len = ft_format_check(&ap, format[++i]);
		else
			print_len = ft_putchar(format[i]);
		if (print_len == -1)
			return (ft_error_check(ap, print_len, count));
		count += print_len;
	}
	return (ft_error_check(ap, print_len, count));
}
