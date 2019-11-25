/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:49:08 by okherson          #+#    #+#             */
/*   Updated: 2018/11/08 19:11:59 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	int		a;
	int		z;
	int		i;
	char	*trim;

	if (!s)
		return (NULL);
	a = 0;
	z = ft_strlen(s);
	while ((s[a] == ' ' || s[a] == '\n' || s[a] == '\t') && s[a] != '\0')
		a++;
	while ((s[z - 1] == ' ' || s[z - 1] == '\n' || s[z - 1] == '\t') && z > a)
		z--;
	trim = (char *)malloc(z - a + 1);
	if (!trim)
		return (NULL);
	i = 0;
	while (a < z)
		trim[i++] = s[a++];
	trim[i] = '\0';
	return (trim);
}
