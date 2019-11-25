/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 15:29:16 by okherson          #+#    #+#             */
/*   Updated: 2019/05/22 19:20:07 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/o_filler.h"

static int		put_token_s(t_stat *s, int *m, int *t)
{
	int			am[2];
	int			at[2];

	at[0] = t[0];
	am[0] = m[0];
	s->r.flag = 0;
	while (at[0] < s->r.ty && s->r.token[at[0]] != NULL)
	{
		am[1] = m[1];
		at[1] = t[1];
		while (at[1] < s->r.tx && s->r.token[at[0]][at[1]])
		{
			if (token_cases(s, at, am) == 1)
				return (1);
			am[1]++;
			at[1]++;
		}
		at[0]++;
		am[0]++;
	}
	if (s->r.flag == 0)
		return (1);
	return (0);
}

static void		algoritm_desizion(t_stat *s, int *p)
{
	if (s->is_touch == 1 && s->c2_round == 1)
	{
		s->r.p_y = p[0];
		s->r.p_x = p[1];
	}
	else if (s->is_touch == 0 && s->mx < 30 && s->c2_round == 0 &&
	alg_position(s) == 1)
	{
		s->r.p_y = p[0];
		s->r.p_x = p[1];
	}
	else if ((s->is_touch == 1 || s->mx >= 30) && alg_congestion(s) == 1)
	{
		s->r.p_y = p[0];
		s->r.p_x = p[1];
	}
}

static void		put_token(t_stat *s, int *tp, int *mp)
{
	int			m[2];
	int			t[2];
	int			p[2];

	t[0] = mp[0] + tp[0] >= 0 ? 0 : 0 - (tp[0] + mp[0]);
	t[1] = mp[1] + tp[1] >= 0 ? 0 : 0 - (tp[1] + mp[1]);
	m[0] = mp[0] + tp[0] >= 0 ? mp[0] + tp[0] : 0;
	m[1] = mp[1] + tp[1] >= 0 ? mp[1] + tp[1] : 0;
	p[0] = mp[0] + tp[0];
	p[1] = mp[1] + tp[1];
	if (p[0] + s->r.lf_sy < s->my && p[1] + s->r.lf_sx < s->mx
	&& p[0] + s->r.ff_sy >= 0 && p[1] + s->r.ff_sx >= 0)
	{
		if (put_token_s(s, m, t) == 0)
			algoritm_desizion(s, p);
		reverse(s);
	}
}

static void		check_token(t_stat *s, int *mp)
{
	int			tp[2];

	tp[0] = -s->r.ff_sy;
	s->tiy = s->r.ff_sy;
	while (s->tiy <= s->r.lf_sy)
	{
		s->tix = s->r.ff_sx - 1;
		tp[1] = -s->r.ff_sx;
		while (++s->tix <= s->r.lf_sx)
		{
			if (s->r.token[s->tiy][s->tix] == '*' && tp[0] + s->r.ty > 0
			&& tp[1] + s->r.tx > 0)
				put_token(s, tp, mp);
			if (s->is_touch == 1 && s->c2_round == 1 && (s->r.p_y != 0
			|| s->r.p_x != 0))
				break ;
			tp[1]--;
		}
		if (s->is_touch == 1 && s->c2_round == 1 && (s->r.p_y != 0
		|| s->r.p_x != 0))
			break ;
		tp[0]--;
		s->tiy++;
	}
}

void			place_search(t_stat *s)
{
	int			mp[2];

	s->r.l = 500;
	mp[0] = 0;
	dot_calculate(s);
	while (mp[0] < s->my)
	{
		mp[1] = 0;
		while (mp[1] < s->mx)
		{
			if (s->r.map[mp[0]][mp[1]] == s->c || s->r.map[mp[0]][mp[1]]
			== s->c + 32)
				check_token(s, mp);
			if (s->is_touch == 1 && s->c2_round == 1 && (s->r.p_y != 0
			|| s->r.p_x != 0))
				break ;
			mp[1]++;
		}
		if (s->is_touch == 1 && s->c2_round == 1 && (s->r.p_y != 0
		|| s->r.p_x != 0))
			break ;
		mp[0]++;
	}
	sending_place(s);
}
