/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 13:37:15 by okherson          #+#    #+#             */
/*   Updated: 2018/11/14 15:18:44 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_set(char **mas, char const *s, char c, int n)
{
	int			a;
	int			b;
	int			i;

	i = 0;
	a = 0;
	while (s[i] != '\0' && a < n)
	{
		b = 0;
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			mas[a][b] = s[i];
			b++;
			i++;
		}
		a++;
	}
}

static void		ft_mem(char **mas, char const *s, char c, int n)
{
	int			b;
	int			a;
	int			l;

	l = 0;
	a = 0;
	while (s[l] != '\0' && a < n)
	{
		b = 0;
		while (s[l] == c)
			l++;
		while (s[l] != c && s[l] != '\0')
		{
			b++;
			l++;
		}
		if (b > 0)
			mas[a] = (char *)malloc((b + 1) * sizeof(char));
		if (b > 0)
			ft_bzero(mas[a], b + 1);
		a++;
		if (a == n - 1)
			mas[a] = NULL;
	}
}

static int		ft_word_n(char const *s, char c, int l, int n)
{
	while (s[l] != '\0')
	{
		if ((s[l] != c && s[l + 1] == c) || (s[l] != c && s[l + 1] == '\0'))
			n++;
		l++;
	}
	return (n);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**mas;
	int			n;
	int			l;

	l = 0;
	n = 1;
	if (!s)
		return (NULL);
	n = ft_word_n(s, c, l, n);
	mas = (char **)malloc(n * sizeof(char *));
	if (!mas)
		return (NULL);
	if (n == 1)
	{
		mas[0] = NULL;
		return (mas);
	}
	ft_mem(mas, s, c, n);
	ft_set(mas, s, c, n);
	return (mas);
}
