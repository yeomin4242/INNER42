/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeomin <yeomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:05:10 by yeomin            #+#    #+#             */
/*   Updated: 2023/03/18 10:54:59 by yeomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (src_len + 1));
	if (!dest)
		return (0);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		++i;
	}
	dest[i] = '\0';
	return (dest);
}
