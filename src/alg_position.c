/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 12:14:37 by okherson          #+#    #+#             */
/*   Updated: 2019/05/22 18:46:52 by okherson         ###   ########.fr       */
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

static int	alg_force(t_stat *s, int y, int x)
{
	int		a;
	int		b;
	int		maby_l;
	int		l;

	a = -1;
	l = 400;
	maby_l = 400;
	while (s->r.map[++a])
	{
		b = -1;
		while (s->r.map[a][++b])
		{
			if (s->r.map[a][b] == s->c + 32)
				maby_l = ft_abs(y - a) + ft_abs(x - b);
			l = maby_l < l ? maby_l : l;
		}
	}
	if (l < s->r.l)
	{
		s->r.l = l;
		return (1);
	}
	return (0);
}

static void	alg_position_2(t_stat *s, int res)
{
	if (s->c_y >= s->my / 2)
	{
		if (s->c_x <= s->mx / 2 && s->dot[0] >= s->dot[3])
			res = alg_force(s, 0, 0);
		else if (s->c_x <= s->mx / 2 && s->dot[0] < s->dot[3])
			res = alg_force(s, s->my, s->mx);
		else if (s->c_x >= s->mx / 2 && s->dot[1] >= s->dot[2])
			res = alg_force(s, 0, s->mx);
		else
			res = alg_force(s, s->my, 0);
	}
}

int			alg_position(t_stat *s)
{
	int		res;

	res = 0;
	if (s->c_y <= s->my / 2)
	{
		if (s->c_x <= s->mx / 2 && s->dot[1] > s->dot[2])
			res = alg_force(s, 0, s->mx);
		else if (s->c_x <= s->mx / 2 && s->dot[1] <= s->dot[2])
			res = alg_force(s, s->my, 0);
		else if (s->c_x >= s->mx / 2 && s->dot[0] > s->dot[3])
			res = alg_force(s, 0, 0);
		else
			res = alg_force(s, s->my, s->c_x);
	}
	alg_position_2(s, res);
	if (res == 1)
		return (1);
	return (0);
}
