/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-yeongjae <min-yeongjae@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:41:07 by min-yeongja       #+#    #+#             */
/*   Updated: 2023/03/13 17:31:38 by min-yeongja      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*char_str;
	unsigned char		char_data;
	size_t				i;

	char_str = (const unsigned char *)s;
	char_data = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (char_str[i] == char_data)
		{
			return ((void *)(char_str + i));
		}
		i++;
	}
	return (0);
}
