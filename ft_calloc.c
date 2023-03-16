/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-yeongjae <min-yeongjae@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:12:05 by min-yeongja       #+#    #+#             */
/*   Updated: 2023/03/14 15:40:27 by min-yeongja      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t	size)
{
	void	*arr;

	arr = malloc(count * size);
	if (!arr)
		return (NULL);
	ft_memset(arr, 0, count * size);
	return (arr);
}
