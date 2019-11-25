/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:20:42 by okherson          #+#    #+#             */
/*   Updated: 2019/05/23 10:00:55 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/o_filler.h"

void		sending_place(t_stat *s)
{
	int		a;
	int		y;
	int		x;

	y = s->r.p_y;
	x = s->r.p_x;
	a = 0;
	while (s->r.map[a])
		ft_strdel(&s->r.map[a++]);
	free(s->r.map);
	a = 0;
	while (s->r.token[a])
		ft_strdel(&s->r.token[a++]);
	free(s->r.token);
	ft_bzero(&s->r, sizeof(s->r));
	s->miy = 0;
	s->tiy = 0;
	ft_putnbr(y);
	ft_putchar(32);
	ft_putnbr(x);
	ft_putchar('\n');
}

static void	token_mem(char *line, t_stat *s)
{
	char	**str;
	int		a;

	a = 0;
	str = ft_strsplit(line, ' ');
	s->r.ty = ft_atoi(str[1]);
	s->r.tx = ft_atoi(str[2]);
	s->r.token = malloc((s->r.ty + 1) * sizeof(char *));
	s->r.token[s->r.ty] = NULL;
	ft_strdel(&str[0]);
	ft_strdel(&str[1]);
	ft_strdel(&str[2]);
	free(str);
}

static void	map_mem(char *line, t_stat *s)
{
	char	**str;
	int		a;

	a = 0;
	str = ft_strsplit(line, ' ');
	s->my = ft_atoi(str[1]);
	s->mx = ft_atoi(str[2]);
	s->r.map = malloc((s->my + 1) * sizeof(char *));
	s->r.map[s->my] = NULL;
	ft_strdel(&str[0]);
	ft_strdel(&str[1]);
	ft_strdel(&str[2]);
	free(str);
}

static void	set_bs(t_stat *s)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "$$$ exec") && s->player == 0)
		{
			s->player = ft_strstr(line, "p1") ? 1 : 2;
			s->c = s->player == 1 ? 'O' : 'X';
			s->c2 = s->player == 1 ? 'X' : 'O';
		}
		if (s->r.n == 1 && ft_strstr(line, "Plateau"))
			map_mem(line, s);
		if (s->r.n > 2 && s->r.n < s->my + 3)
			s->r.map[s->miy++] = ft_strdup(line + 4);
		if (s->r.n == s->my + 3 && ft_strstr(line, "Piece"))
			token_mem(line, s);
		if ((s->r.n > s->my + 3 && s->r.n <= s->my + 3 + s->r.ty)
		&& (*line == '*' || *line == '.'))
			s->r.token[s->tiy++] = ft_strdup(line);
		if (s->r.n == s->my + s->r.ty + 3)
			place_search(s);
		s->r.n++;
		free(line);
	}
}

int			main(void)
{
	t_rewr	r;
	t_stat	s;

	ft_bzero(&r, sizeof(t_rewr));
	ft_bzero(&s, sizeof(t_stat));
	s.r = r;
	set_bs(&s);
	return (0);
}
