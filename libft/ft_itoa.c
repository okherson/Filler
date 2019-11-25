/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:42:35 by okherson          #+#    #+#             */
/*   Updated: 2018/11/11 17:30:13 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_len(int n, unsigned int pn)
{
	int				i;

	i = 1;
	if (n < 0)
		i = 2;
	while (pn > 9)
	{
		i++;
		pn = pn / 10;
	}
	return (i);
}

static char			*ft_str(char *str, unsigned int pn, int ln)
{
	while (ln > 0)
	{
		ln--;
		if (str[ln] == '-')
			return (str);
		else
		{
			str[ln] = pn % 10 + '0';
			pn = pn / 10;
		}
	}
	return (str);
}

char				*ft_itoa(int n)
{
	char			*str;
	int				ln;
	unsigned int	pn;

	if (n < 0)
		pn = -n;
	else
		pn = n;
	ln = ft_len(n, pn);
	str = (char *)malloc((ln + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_bzero(str, ln + 1);
	if (n < 0)
		str[0] = '-';
	str = ft_str(str, pn, ln);
	return (str);
}
