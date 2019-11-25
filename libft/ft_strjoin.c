/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:17:24 by okherson          #+#    #+#             */
/*   Updated: 2019/05/14 15:30:18 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*concat;
	int		i;
	int		a;

	if (!s1 || !s2)
		return (NULL);
	i = (ft_strlen(s1) + ft_strlen(s2));
	concat = (char *)malloc((i + 1) * sizeof(char));
	if (!concat)
		return (NULL);
	a = 0;
	while (s1[a] != '\0')
	{
		concat[a] = s1[a];
		a++;
	}
	while (s2 && a < i)
	{
		concat[a] = *s2;
		a++;
		s2++;
	}
	concat[i] = '\0';
	return (concat);
}
