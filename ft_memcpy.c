/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeomin <yeomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:48:26 by yeomin            #+#    #+#             */
/*   Updated: 2023/03/18 10:54:59 by yeomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*char_dest;
	const unsigned char	*char_src;
	size_t				i;

	char_dest = (unsigned char *)dst;
	char_src = (const unsigned char *)src;
	i = 0;
	if (dst == src)
		return (dst);
	while (i < n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dst);
}
