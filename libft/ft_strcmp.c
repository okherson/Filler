/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 18:15:04 by okherson          #+#    #+#             */
/*   Updated: 2018/11/13 16:36:45 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while ((unsigned char)s1[i] != '\0' && (unsigned char)s2[i] != '\0' &&
			(unsigned char)s1[i] == (unsigned char)s2[i])
		i++;
	if ((unsigned char)s1[i] == '\0' && (unsigned char)s2[i] == '\0')
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
