/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeomin <yeomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:45:22 by yeomin            #+#    #+#             */
/*   Updated: 2023/03/18 20:49:48 by yeomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	str_len;
	size_t	i;

	if (!s)
		return (NULL);
	i = -1;
	str_len = ft_strlen(s);
	if (start > str_len)
	{
		substr = malloc(sizeof(char) * 1);
		if (!substr)
			return (NULL);
		substr[++i] = '\0';
		return (substr);
	}
	if (start + len > str_len)
		len = str_len - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (++i < len)
		substr[i] = s[start + i];
	substr[len] = '\0';
	return (substr);
}
