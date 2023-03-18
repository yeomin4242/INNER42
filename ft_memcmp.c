/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeomin <yeomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:49:33 by yeomin            #+#    #+#             */
/*   Updated: 2023/03/18 10:54:59 by yeomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*char_s1;
	const unsigned char	*char_s2;
	size_t				i;

	char_s1 = (const unsigned char *)s1;
	char_s2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (char_s1[i] != char_s2[i])
			return ((int)(char_s1[i] - char_s2[i]));
		i++;
	}
	return (0);
}
