/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 02:07:05 by cquillet          #+#    #+#             */
/*   Updated: 2017/06/09 20:22:31 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include "libft.h"

int			get_next_line(const int fd, char **line)
{
	static t_buffer	b[MAX_FD];
	ssize_t			len;
	char			*s;

	if (!line || read(fd, *line, 0) < 0 || BUFF_SIZE <= 0 || fd >= MAX_FD)
		return (-1);
	len = b[fd].len;
	*line = ft_memcpy(ft_memalloc(len), b[fd].str, len);
	while (!(s = ft_memchr(b[fd].str, '\n', b[fd].len)))
	{
		b[fd].len = read(fd, b[fd].str, BUFF_SIZE);
		b[fd].ret_value = (len + b[fd].len) > 0 ? 1 : b[fd].len;
		if (b[fd].len < BUFF_SIZE && b[fd].str[b[fd].len - 1] != '\n')
			b[fd].str[b[fd].len++] = '\n';
		ft_bzero(b[fd].str + b[fd].len, BUFF_SIZE + 1 - b[fd].len);
		s = ft_memcpy(ft_memalloc(len + b[fd].len), *line, len);
		ft_memmove(s + len, b[fd].str, b[fd].len);
		ft_strdel(line);
		*line = s;
		len += b[fd].len;
	}
	(*line)[len - b[fd].len + (s - b[fd].str)] = '\0';
	b[fd].len = b[fd].len - (s + 1 - b[fd].str);
	ft_strncpy(b[fd].str, s + 1, b[fd].len);
	return (b[fd].ret_value);
}
