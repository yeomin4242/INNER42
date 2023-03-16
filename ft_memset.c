/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-yeongjae <min-yeongjae@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:54:40 by min-yeongja       #+#    #+#             */
/*   Updated: 2023/03/15 00:00:38 by min-yeongja      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*char_dest;
	unsigned char	char_val;
	size_t			i;

	i = 0;
	char_dest = (unsigned char *)s;
	char_val = (unsigned char)c;
	while (i < n)
	{
		char_dest[i] = char_val;
		i++;
	}
	return ((void *)char_dest);
}
