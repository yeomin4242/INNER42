/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-yeongjae <min-yeongjae@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:14:11 by min-yeongja       #+#    #+#             */
/*   Updated: 2023/03/12 15:58:50 by min-yeongja      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (fd < 0)
		return ;
	if (n == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		n = 147483648;
	}	
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n *= -1;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + 48, fd);
		return ;
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
	}
	ft_putnbr_fd(n % 10, fd);
}
