/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeomin <yeomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 21:51:05 by yeomin            #+#    #+#             */
/*   Updated: 2023/03/18 13:52:32 by yeomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_remove_check(char const s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static size_t	ft_idx_check(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_remove_check(s1[i], set))
		i++;
	return (i);
}

static size_t	ft_str_check(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	while (s1[i] && ft_remove_check(s1[i], set))
		i++;
	while (s1[j] && ft_remove_check(s1[j], set) && i < j)
		j--;
	return (j - i + 2);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*new_str;

	i = ft_idx_check(s1, set);
	len = ft_str_check(s1, set);
	new_str = malloc(sizeof(char) * len);
	if (!new_str || !s1)
		return (NULL);
	if (!set)
		return ((char *)(s1));
	ft_strlcpy(new_str, &s1[i], len);
	return (new_str);
}
