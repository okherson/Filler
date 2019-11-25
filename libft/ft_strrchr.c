/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:31:29 by okherson          #+#    #+#             */
/*   Updated: 2018/11/14 17:19:34 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int p;

	p = 0;
	while (s[p] != '\0')
		p++;
	while (p >= 0 && s[p] != (char)c)
		p--;
	if (s[p] == (char)c)
		return ((char *)&s[p]);
	else
		return (NULL);
}
