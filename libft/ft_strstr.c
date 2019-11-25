/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 18:59:55 by okherson          #+#    #+#             */
/*   Updated: 2018/11/14 17:19:37 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	while (s1[a] != '\0')
	{
		b = 0;
		if (s1[a] != s2[b])
			a++;
		while (s2[b] != '\0' && s1[a] == s2[b])
		{
			a++;
			b++;
		}
		if (s2[b] != '\0' && s1[a - 1] == s2[b - 1])
			a = a - b + 1;
		else if (s2[b] == '\0')
			return ((char *)&s1[a - b]);
	}
	return (NULL);
}
