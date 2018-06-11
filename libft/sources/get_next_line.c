/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alikhtor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 13:18:08 by alikhtor          #+#    #+#             */
/*   Updated: 2018/05/30 14:50:58 by alikhtor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

static int	ft_find_n_or_end(char **ret, char **line)
{
	char	*n;
	char	*temp;

	n = NULL;
	n = ft_strchr(*ret, '\n');
	if (n == NULL)
		return (0);
	*line = ft_strsub(*ret, 0, n - *ret);
	n = n + 1;
	temp = ft_strdup(n);
	ft_strdel(ret);
	*ret = temp;
	return (1);
}

static int	ft_read_buf(const int fd, char **ret, char **line)
{
	char	*buf;
	char	*temp;

	buf = ft_strnew(BUFF_SIZE);
	while (read(fd, buf, BUFF_SIZE))
	{
		temp = ft_strjoin(*ret, buf);
		ft_strdel(ret);
		ft_strdel(&buf);
		*ret = temp;
		buf = ft_strnew(BUFF_SIZE);
		if (ft_find_n_or_end(ret, line))
		{
			ft_strdel(&buf);
			return (1);
		}
	}
	ft_strdel(&buf);
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static char	*ret[FD_AMOUNT];

	if (fd < 0 || line == NULL || read(fd, 0, 0))
		return (-1);
	if (ret[fd] == NULL)
		ret[fd] = ft_strnew(0);
	if (ft_find_n_or_end(&ret[fd], line))
		return (1);
	if (ft_read_buf(fd, &ret[fd], line))
		return (1);
	if (*ret[fd])
	{
		*line = ft_strdup(ret[fd]);
		ft_strdel(&ret[fd]);
		return (1);
	}
	ft_strdel(&ret[fd]);
	return (0);
}
