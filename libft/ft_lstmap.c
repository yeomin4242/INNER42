/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeomin <yeomin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 01:14:57 by yeomin            #+#    #+#             */
/*   Updated: 2023/03/19 17:16:19 by yeomin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_check(t_list *n, void (*d)(void *), void *test, t_list *temp)
{
	if (!test)
	{
		ft_lstclear(&n, *d);
		return (0);
	}
	if (!temp)
	{
		d(test);
		ft_lstclear(&n, *d);
		return (0);
	}
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*temp;
	void	*test;

	new_lst = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		test = (f)(lst->content);
		if (!ft_check(new_lst, (*del), test, temp))
			return (NULL);
		temp = ft_lstnew(test);
		if (!ft_check(new_lst, (*del), test, temp))
			return (NULL);
		ft_lstadd_back(&new_lst, temp);
		lst = lst->next;
	}
	return (new_lst);
}
