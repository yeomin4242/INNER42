/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeomin <yeomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:38:10 by yeomin            #+#    #+#             */
/*   Updated: 2023/03/19 18:21:11 by yeomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*char_dest;
	const unsigned char	*char_src;
	size_t				i;

	char_dest = (unsigned char *)dst;
	char_src = (const unsigned char *)src;
	i = -1;
	if (dst == src)
		return (dst);
	if (char_dest < char_src)
	{
		while (++i < len)
			char_dest[i] = char_src[i];
	}
	else
	{
		while (++i < len)
			char_dest[len - 1 - i] = char_src[len - 1 - i];
	}
	return (dst);
}
