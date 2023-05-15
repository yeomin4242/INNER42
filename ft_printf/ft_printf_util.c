/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeomin <yeomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 13:42:34 by yeomin            #+#    #+#             */
/*   Updated: 2023/05/14 15:23:32 by yeomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (1);
	while (s[i])
	{
		if (write(1, &s[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_lencheck(int num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		num *= -1;
		count ++;
	}
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		if (write(1, "-2147483648", 11) == -1)
			return (-1);
		return (0);
	}	
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		nb *= -1;
	}
	if (nb < 10)
	{
		if (ft_putchar(nb + 48) == -1)
			return (-1);
		return (0);
	}
	else
	{
		if (ft_putnbr(nb / 10) == -1)
			return (-1);
	}
	ft_putnbr(nb % 10);
	return (0);
}

void	ft_lln_len(unsigned long long ll_n, int *p_l, unsigned long long b_l)
{
	if (ll_n < b_l)
	{
		*p_l += 1;
		return ;
	}
	else
		ft_lln_len(ll_n / b_l, p_l, b_l);
	ft_lln_len(ll_n % b_l, p_l, b_l);
}
