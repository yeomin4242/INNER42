/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-yeongjae <min-yeongjae@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:45:22 by min-yeongja       #+#    #+#             */
/*   Updated: 2023/03/13 18:08:15 by min-yeongja      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	str_len;
	size_t	i;

	str_len = ft_strlen(s);
	i = -1;
	if (!s)
		return (NULL);
	if (start > str_len)
	{
		substr = malloc(sizeof(char) * 1);
		substr[++i] = '\0';
		return (substr);
	}
	if (start + len > str_len)
		len = str_len - start;
	substr = malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (++i < len)
	{
		substr[i] = s[start + i];
	}
	substr[len] = '\0';
	return (substr);
}
