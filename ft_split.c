/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeomin <yeomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 22:14:06 by yeomin            #+#    #+#             */
/*   Updated: 2023/03/18 10:54:59 by yeomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_check(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (!c)
		return (1);
	while (s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && (!(s[i] == c)))
			i++;
		while (s[i] && (s[i] == c))
			i++;
		count++;
	}
	return (count);
}

static void	ft_strcpy(char *new_str, char const *str, size_t temp, size_t i)
{
	size_t	k;

	k = 0;
	while (temp < i)
	{
		new_str[k] = str[temp];
		k++;
		temp++;
	}
		new_str[k] = '\0';
	k = 0;
}

static char	**ft_to_free(char **new_str)
{
	size_t	i;

	i = 0;
	while (new_str[i])
	{
		free(new_str[i]);
		i++;
	}
	free(new_str);
	return (NULL);
}

static char	**ft_arrjoin(char **new_str, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	temp;

	i = 0;
	j = 0;
	temp = 0;
	while (i < ft_strlen(s))
	{
		if (!(s[i] == c))
		{
			temp = i;
			while (s[i] && (!(s[i] == c)))
				i++;
			new_str[j] = malloc(sizeof(char) * (i - temp + 1));
			if (!new_str[j])
				return (ft_to_free(new_str));
			ft_strcpy(new_str[j], s, temp, i);
			j++;
		}
		i++;
	}
	new_str[j] = NULL;
	return (new_str);
}

char	**ft_split(char const *s, char c)
{
	size_t	total_len;
	char	**new_str;

	total_len = ft_size_check(s, c);
	new_str = malloc(sizeof(char *) * (total_len + 1));
	if (!new_str)
		return (new_str);
	new_str = ft_arrjoin(new_str, s, c);
	return (new_str);
}
