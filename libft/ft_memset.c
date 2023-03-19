/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeomin <yeomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 00:54:40 by yeomin            #+#    #+#             */
/*   Updated: 2023/03/18 10:54:59 by yeomin           ###   ########.fr       */
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
