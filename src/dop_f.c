/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dop_f.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 14:07:53 by okherson          #+#    #+#             */
/*   Updated: 2019/05/22 19:20:53 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/o_filler.h"

static void	last_s_2(t_stat *s)
{
	int		a;
	int		b;

	b = s->r.tx;
	while (--b >= 0)
	{
		a = s->r.ty - 1;
		while (a >= 0 && s->r.token[a][b] && s->r.token[a][b] != '*')
			a--;
		if (a >= 0 && s->r.token[a][b] && s->r.token[a][b] == '*')
		{
			s->r.lf_sx = b;
			break ;
		}
	}
}

static void	last_s(t_stat *s)
{
	int		a;
	int		b;

	a = s->r.ty;
	while (--a >= 0)
	{
		b = s->r.tx - 1;
		while (b >= 0 && s->r.token[a][b] && s->r.token[a][b] != '*')
			b--;
		if (b >= 0 && s->r.token[a][b] && s->r.token[a][b] == '*')
		{
			s->r.lf_sy = a;
			break ;
		}
	}
	last_s_2(s);
}

static void	first_s_2(t_stat *s)
{
	int		a;
	int		b;

	b = -1;
	while (++b < s->r.tx)
	{
		a = 0;
		while (a < s->r.ty && s->r.token[a][b] != '*')
			a++;
		if (a < s->r.ty && s->r.token[a][b] == '*')
		{
			s->r.ff_sx = b;
			break ;
		}
	}
	last_s(s);
}

void		first_s(t_stat *s)
{
	int		a;
	int		b;

	a = -1;
	while (++a < s->r.ty)
	{
		b = 0;
		while (b < s->r.tx && s->r.token[a][b] != '*')
			b++;
		if (b < s->r.tx && s->r.token[a][b] == '*')
		{
			s->r.ff_sy = a;
			break ;
		}
	}
	first_s_2(s);
}

int			token_cases(t_stat *s, int *at, int *am)
{
	if (am[0] < 0 || am[0] >= s->my || am[1] < 0 || am[1] >= s->mx)
		return (1);
	else if (at[0] < 0 || at[0] >= s->r.ty || at[1] < 0 || at[1] >= s->r.tx)
		return (1);
	else if (s->r.token[at[0]][at[1]] == '*' && s->r.flag == 1 &&
	(s->r.map[am[0]][am[1]] == s->c || s->r.map[am[0]][am[1]] == s->c + 32))
		return (1);
	else if (s->r.token[at[0]][at[1]] == '*' && (s->r.map[am[0]][am[1]] ==
	s->c2 + 32 || s->r.map[am[0]][am[1]] == s->c2))
		return (1);
	else if (s->r.token[at[0]][at[1]] == '*' && s->r.flag == 0 &&
	(s->r.map[am[0]][am[1]] == s->c || s->r.map[am[0]][am[1]] == s->c + 32))
	{
		s->r.map[am[0]][am[1]] = s->c + 32;
		s->r.flag = 1;
		s->r.dot_y = am[0];
		s->r.dot_x = am[1];
	}
	else if (s->r.token[at[0]][at[1]] == '*' && s->r.map[am[0]][am[1]] == '.')
		s->r.map[am[0]][am[1]] = s->c + 32;
	else if (s->r.token[at[0]][at[1]] == '*')
		return (1);
	return (0);
}
