/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:42:30 by umoff             #+#    #+#             */
/*   Updated: 2019/05/30 11:52:01 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

# define BUFF_SIZE 32
# define FD_MAX 10240

int	get_next_line(const int fd, char **line);

#endif
