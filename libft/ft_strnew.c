/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:59:04 by okherson          #+#    #+#             */
/*   Updated: 2018/11/08 16:46:06 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strnew(size_t size)
{
	unsigned char	*str;

	str = (unsigned char *)malloc((size + 1) * sizeof(unsigned char));
	if (str == NULL)
		return (NULL);
	else
		ft_bzero(str, size + 1);
	return ((char *)str);
}
