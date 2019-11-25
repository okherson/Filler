/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 10:51:01 by okherson          #+#    #+#             */
/*   Updated: 2018/11/05 17:34:37 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_bzero(void *s, size_t n)
{
	unsigned char	*set;
	size_t			i;

	set = (unsigned char*)s;
	i = 0;
	while (i < n)
	{
		set[i] = '\0';
		i++;
	}
}
