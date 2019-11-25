/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okherson <okherson@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 14:55:13 by okherson          #+#    #+#             */
/*   Updated: 2019/05/14 15:31:02 by okherson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	new_lines(char **al, char **line, int r, int fd)
{
	size_t	i;
	char	*t;

	i = 0;
	while (al[fd][i] != '\n' && al[fd][i])
		i++;
	if (al[fd][i] == '\n')
	{
		*line = ft_strsub(al[fd], 0, i);
		t = ft_strdup(&al[fd][i + 1]);
		free(al[fd]);
		al[fd] = t;
		if (al[fd][0] == '\0')
			ft_strdel(&al[fd]);
	}
	else if (al[fd][i] == '\0')
	{
		if (r == BUFF_SIZE)
			get_next_line(fd, line);
		*line = ft_strdup(al[fd]);
		ft_strdel(&al[fd]);
	}
}

int			get_next_line(const int fd, char **line)
{
	static char	*a[4096];
	char		buff[BUFF_SIZE + 1];
	char		*t;
	int			d;

	if (fd < 0 || read(fd, 0, 0) < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	if (a[fd] == NULL)
		a[fd] = ft_strnew(1);
	while (ft_strchr(a[fd], '\n') == NULL &&
		(d = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[d] = '\0';
		t = ft_strjoin(a[fd], buff);
		free(a[fd]);
		a[fd] = t;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (d == 0 && (a[fd] == NULL || a[fd][0] == '\0'))
		return (0);
	new_lines(a, line, d, fd);
	return (1);
}
