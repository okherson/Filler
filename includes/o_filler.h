/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_filler.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 19:24:11 by okherson          #+#    #+#             */
/*   Updated: 2019/05/22 19:26:35 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef O_FILLER_H
# define O_FILLER_H
# include "../libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

typedef struct		s_rewr
{
	char			**map;
	char			**token;
	int				ty;
	int				tx;
	int				ff_sy;
	int				ff_sx;
	int				lf_sy;
	int				lf_sx;
	int				dot_y;
	int				dot_x;
	int				p_y;
	int				p_x;
	int				p2_y;
	int				p2_x;
	int				l;
	int				n;
	int				flag;
	int				ox;
}					t_rewr;

typedef struct		s_stat
{
	int				player;
	char			c;
	int				c_y;
	int				c_x;
	char			c2;
	int				c2_num;
	int				c2_round;
	int				c2_y;
	int				c2_x;
	int				dot[4];
	int				my;
	int				mx;
	int				miy;
	int				mix;
	int				tiy;
	int				tix;
	int				t;
	int				is_touch;
	t_rewr			r;
}					t_stat;

int					alg_position(t_stat *s);
void				place_search(t_stat *s);
int					alg_congestion(t_stat *s);
void				first_s(t_stat *s);
void				search_c2_pos(t_stat *s);
int					find_touch(t_stat *s);
void				dot_calculate(t_stat *s);
void				reverse(t_stat *s);
int					token_cases(t_stat *s, int *at, int *am);
void				sending_place(t_stat *s);
#endif
