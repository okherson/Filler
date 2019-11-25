/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:41:54 by okherson          #+#    #+#             */
/*   Updated: 2018/11/12 19:55:25 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new_list;
	t_list	*h_list;

	if (!lst)
		return (NULL);
	new_list = NULL;
	h_list = NULL;
	new_list = f(lst);
	h_list = new_list;
	while (lst->next)
	{
		new_list->next = f(lst->next);
		new_list = new_list->next;
		lst = lst->next;
	}
	if (!h_list)
		return (NULL);
	return (h_list);
}
