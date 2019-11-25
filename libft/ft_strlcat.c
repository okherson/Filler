/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:38:30 by okherson          #+#    #+#             */
/*   Updated: 2018/11/14 16:10:08 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t ld;
	size_t ls;
	size_t dstl;

	dstl = ft_strlen(dst);
	ld = ft_strlen(dst);
	ls = 0;
	if (ld > dstsize)
		return (ft_strlen(src) + dstsize);
	while (src[ls] != '\0' && (ld + ls) < (dstsize - 1))
	{
		dst[ld + ls] = src[ls];
		ls++;
	}
	dst[ld + ls] = '\0';
	return (dstl + ft_strlen(src));
}
