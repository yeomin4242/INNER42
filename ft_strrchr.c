/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-yeongjae <min-yeongjae@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:22:35 by min-yeongja       #+#    #+#             */
/*   Updated: 2023/03/15 17:21:03 by min-yeongja      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t				i;
	const unsigned char	*str;

	i = 0;
	str = (const unsigned char *)s;
	while (s[i])
		i++;
	if ((unsigned char)c == '\0')
		return ((char *)(str + i));
	while (i > 0)
	{
		if (str[i] == (unsigned char)c)
			return ((char *)(str + i));
		i--;
	}
	if (str[i] == (unsigned char)c)
		return ((char *)(str + i));
	return (NULL);
}
