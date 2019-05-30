/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:43:23 by umoff             #+#    #+#             */
/*   Updated: 2019/05/30 11:48:11 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	**empty_line(char **stack)
{
	if (*stack == NULL)
		*stack = ft_strnew(0);
	return (stack);
}

static void	new_string(char **stack, char *buf)
{
	char *temp;

	temp = ft_strjoin(*stack, buf);
	free(*stack);
	*stack = ft_strdup(temp);
	free(temp);
}

static int	new_line(char **stack, char **line)
{
	char *temp;

	if ((*stack)[0] == 0)
		return (0);
	if (ft_strchr(*stack, '\n'))
	{
		*(ft_strchr(*stack, '\n')) = '\0';
		*line = ft_strdup(*stack);
		temp = ft_strdup(ft_strchr(*stack, '\0') + 1);
		free(*stack);
		if (temp != 0)
		{
			*stack = ft_strdup(temp);
			free(temp);
		}
	}
	else
	{
		*line = ft_strdup(*stack);
		ft_memdel((void **)stack);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*stack[FD_MAX];
	char		buf[BUFF_SIZE + 1];
	int			count;

	if (fd == -1 || line == NULL || read(fd, buf, 0) == -1 || fd > FD_MAX)
		return (-1);
	empty_line(&(stack[fd]));
	while (!(ft_strchr(stack[fd], '\n')))
	{
		count = read(fd, buf, BUFF_SIZE);
		buf[count] = '\0';
		if (count == 0)
			break ;
		new_string(&(stack[fd]), buf);
	}
	return (new_line(&(stack[fd]), line));
}
