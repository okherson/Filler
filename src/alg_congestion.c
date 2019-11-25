/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_congestion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 15:28:54 by okherson          #+#    #+#             */
/*   Updated: 2019/05/22 17:55:33 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/o_filler.h"

static int	ft_abs(int a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

static int	search_p22(t_stat *s, int a, int b)
{
	int		y;
	int		x;
	int		ml;
	int		l;

	y = 0;
	l = 500;
	while (s->r.map[y])
	{
		x = 0;
		while (s->r.map[y][x])
		{
			if (s->r.map[y][x] == s->c2)
			{
				ml = ft_abs(y - a) + ft_abs(x - b);
			}
			l = ml < l ? ml : l;
			x++;
		}
		y++;
	}
	return (l);
}

int			alg_congestion(t_stat *s)
{
	int		a;
	int		b;
	int		maby_l;

	a = 0;
	while (s->r.map[a])
	{
		b = 0;
		while (s->r.map[a][b])
		{
			if (s->r.map[a][b] == s->c + 32)
				maby_l = search_p22(s, a, b);
			b++;
		}
		a++;
	}
	if (maby_l < s->r.l)
	{
		s->r.l = maby_l;
		return (1);
	}
	return (0);
}
