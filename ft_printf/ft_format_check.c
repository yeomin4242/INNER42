/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeomin <yeomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:42:37 by yeomin            #+#    #+#             */
/*   Updated: 2023/05/14 14:53:43 by yeomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_error_check(va_list ap, int print_len, int count)
{
	if (print_len == -1)
	{
		va_end(ap);
		return (-1);
	}
	else
	{
		va_end(ap);
		return (count);
	}
}

int	ft_idu_check(va_list *ap, const char format)
{
	unsigned long long	ll_num;
	int					print_len;
	int					num;

	print_len = 0;
	num = va_arg(*ap, int);
	if (format == 'u' && num < 0)
	{
		ll_num = 4294967295 + num + 1;
		ft_lln_len(ll_num, &print_len, 10);
		if (ft_dec_print(ll_num, format) != 0)
			return (-1);
	}
	else
	{
		print_len = ft_lencheck(num);
		if (ft_putnbr(num) != 0)
			return (-1);
	}
	return (print_len);
}

int	ft_c_and_s_check(va_list *ap, const char format)
{
	char	c;
	char	*str;
	int		print_len;

	print_len = 0;
	if (format == 'c')
	{
		c = (char)va_arg(*ap, int);
		print_len = ft_putchar(c);
	}
	else if (format == 's')
	{
		str = va_arg(*ap, char *);
		if (str != NULL)
			print_len = ft_putstr(str);
		else
			print_len = ft_putstr("(null)");
	}
	return (print_len);
}

int	ft_p_check(va_list *ap, const char format)
{
	void				*ptr;
	unsigned long long	ll_num;
	int					print_len;

	print_len = 0;
	if (format == 'p')
	{
		ptr = va_arg(*ap, void *);
		if (ptr < 0)
			ll_num = 4294967295 + (long long)ptr + 1;
		else
			ll_num = (unsigned long long)ptr;
		if (ft_putstr("0x") == -1)
			return (-1);
		ft_lln_len(ll_num, &print_len, 16);
		if (ft_hex_print(ll_num, 'x') != 0)
			return (-1);
		print_len += 2;
	}
	return (print_len);
}

int	ft_x_check(va_list *ap, const char format)
{
	unsigned long long	ll_num;
	int					num;
	int					print_len;

	print_len = 0;
	if (format == 'x' || format == 'X')
	{
		num = va_arg(*ap, int);
		if (num < 0)
			ll_num = 4294967295 + num + 1;
		else
			ll_num = num;
		ft_lln_len(ll_num, &print_len, 16);
		if (ft_hex_print(ll_num, format) != 0)
			return (-1);
	}
	return (print_len);
}
