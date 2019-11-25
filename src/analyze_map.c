/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 12:13:39 by okherson          #+#    #+#             */
/*   Updated: 2019/05/22 19:13:18 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/o_filler.h"

static void	calculate_c2(t_stat *s)
{
	int		a;
	int		b;
	int		c2;

	a = 0;
	c2 = 0;
	while (a < s->my)
	{
		b = -1;
		while (++b < s->mx)
			if (s->r.map[a][b] == s->c2)
				c2++;
		a++;
	}
	if (c2 > s->c2_num)
		s->c2_num = c2;
	else
		s->c2_round = 1;
	s->dot[0] = ft_strstr(s->r.map[0], "O") ? 0 : s->dot[0];
	s->dot[1] = ft_strstr(s->r.map[0], "O") ? 0 : s->dot[1];
	s->dot[2] = ft_strstr(s->r.map[s->my - 1], "O") ? 0 : s->dot[2];
	s->dot[3] = ft_strstr(s->r.map[s->my - 1], "O") ? 0 : s->dot[3];
}

static void	dot_2_calculate(t_stat *s)
{
	int		a;
	int		b;

	a = s->my / 2;
	while (a < s->my)
	{
		b = -1;
		while (++b <= s->mx / 2)
			s->dot[2] = s->r.map[a][b] == '.' ? s->dot[2] + 1 : s->dot[2];
		b = b - 2;
		while (++b < s->mx)
			s->dot[3] = s->r.map[a][b] == '.' ? s->dot[3] + 1 : s->dot[3];
		a++;
	}
	calculate_c2(s);
	if (s->is_touch == 0)
		s->is_touch = find_touch(s);
	first_s(s);
}

void		dot_calculate(t_stat *s)
{
	int		a;
	int		b;

	a = 0;
	while (a <= s->my / 2)
	{
		b = -1;
		while (++b <= s->mx / 2)
			s->dot[0] = (s->r.map[a][b] == '.') ? s->dot[0] + 1 : s->dot[0];
		b = b - 2;
		while (++b < s->mx)
			s->dot[1] = s->r.map[a][b] == '.' ? s->dot[1] + 1 : s->dot[1];
		a++;
	}
	dot_2_calculate(s);
}

int			find_touch(t_stat *s)
{
	int		a;
	int		b;
	int		to;

	a = -1;
	to = 0;
	while (++a < s->my)
	{
		b = -1;
		while (++b < s->mx)
		{
			if (s->r.map[a][b] == s->c)
			{
				(a > 0 && s->r.map[a - 1][b] == s->c2) ? to++ : to;
				(a < s->r.ty - 1 && s->r.map[a + 1][b] == s->c2) ? to++ : to;
				(b > 0 && s->r.map[a][b - 1] == s->c2) ? to++ : to;
				(b < s->r.tx - 1 && s->r.map[a][b + 1] == s->c2) ? to++ : to;
			}
			if (to > 0)
				return (1);
		}
	}
	return (0);
}

void		reverse(t_stat *s)
{
	int		a;
	int		b;

	if (s->r.map[s->r.dot_y][s->r.dot_x] == s->c + 32)
		s->r.map[s->r.dot_y][s->r.dot_x] = s->c;
	a = 0;
	while (a < s->my)
	{
		b = 0;
		while (b < s->mx)
		{
			if (s->r.map[a][b] == s->c + 32)
				s->r.map[a][b] = '.';
			b++;
		}
		a++;
	}
	s->r.dot_y = 0;
	s->r.dot_y = 0;
}
