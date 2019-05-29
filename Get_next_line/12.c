/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcope <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 21:15:04 by jcope             #+#    #+#             */
/*   Updated: 2019/01/28 21:15:06 by jcope            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl		*gnl_new(int fd)
{
	t_gnl *new;

	if (!(new = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	new->buf = '\0';
	new->fd = fd;
	return (new);
}


t_gnl	get_cur_file(int fd, t_gnl **files)
{
	t_gnl	*temp;

	temp = *files;
	while (temp) // go through the list of files and see if the fd matches any we have so far.
	{
		if (temp->fd == fd)
			return (temp);
		temp = temp->next;
	}
	temp = gnl_new(fd); // if it doesn't match anything in the list already make a new file
	temp->next = *files; // add the new gnl struct to the begining of the files list.
	*files = temp; // then set the head of the files list to now be the newest gnl struct.
	return (temp);
}


int		get_next_line(const int fd, char  **line)
{
	char	buf[BUFF_SIZE + 1]; // +1 for null terminator
	static t_gnl	*files;		// The linked list of all the files the application is curly reading from. Has to stay at the head of list so you can always go through the whole list when you come back to this function.
	t_gnl			*cur;	// a pointer to the current file we're reading from.
	int				ret;

	if (fd < 0 || !line || BUFF_SIZE < 0) //fd is an error code || line is null || Bad Buff Size
		return (-1); //Error
	cur = get_cur_file(fd, &files);
	while (ret = read(fd, buf, BUFF_SIZE)) //reading through the file buff_size bytes at a time.
	{
		buf[ret] = '\0'; // null terminator for the end of buff since read returns number of bytes actually read.
		cur->buf = ft_strjoin(cur->buf, buf); // add to the gnl struct's buff...
		if (ft_strchr(buf, '\n')) // until you hit a newline somewhere in the buf.
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(cur->buf)) //no bytes read or the length of that file's buffer is 0.
		return (0);
	ft_strncpy(line, cur->buf, cur->buf - ft_strchr(cur->buf, '\n')) //# of characters before /n //copy the current line into **line that was passed in so the main can print the current line for current fd.

	WORKING HERE// you'll potentially have some characters after the /n in the buf and will need to set them to null


	return (1); // Line was read
	// return (0); // Reading Completed
}