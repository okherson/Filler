/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 18:25:29 by okherson          #+#    #+#             */
/*   Updated: 2019/05/14 15:30:26 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *s)
{
	size_t	n;

	n = 0;
	while (s[n] != '\0')
	{
		n++;
	}
	return (n);
}
