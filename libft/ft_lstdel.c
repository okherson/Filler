/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:19:09 by okherson          #+#    #+#             */
/*   Updated: 2018/11/12 16:22:08 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *n;

	while (*alst)
	{
		n = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = n;
	}
	*alst = NULL;
}
