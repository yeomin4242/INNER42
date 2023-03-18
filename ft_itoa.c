/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeomin <yeomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:20:19 by yeomin            #+#    #+#             */
/*   Updated: 2023/03/18 10:54:59 by yeomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_divcheck(int len)
{
	int	count;
	int	temp;

	count = 2;
	temp = 10;
	if (len == 1)
		return (1);
	else if (len == 2)
		return (temp);
	while (count < len)
	{
		temp = 10 * temp;
		count++;
	}
	return (temp);
}

static int	ft_lencheck(long long int num)
{
	int	count;

	count = 0;
	if (num < 0)
	{
		count++;
		num *= -1;
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

static void	ft_toarr(char *str, size_t len, long long int num, size_t i)
{
	while (len)
	{
		str[i] = (num / ft_divcheck(len)) + '0';
		num = num % ft_divcheck(len);
		i++;
		len--;
	}
	str[i] = '\0';
}

char	*ft_itoa(int n)
{
	size_t			i;
	size_t			len;
	char			*str;
	long long int	num;

	i = 0;
	num = (long long int)n;
	len = ft_lencheck(num);
	str = malloc(sizeof(char) *(len + 1));
	if (!str)
		return (NULL);
	if (num < 0)
	{
		str[i++] = '-';
		num *= -1;
		len--;
	}
	ft_toarr(str, len, num, i);
	return (str);
}
