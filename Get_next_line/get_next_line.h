/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/09 14:42:30 by umoff             #+#    #+#             */
/*   Updated: 2019/05/29 17:36:24 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# define FD_MAX 10240

# include <unistd.h>
# include <stdio.h>  //
#include <fcntl.h>   //
# include "./libft/libft.h"  //
# include <string.h>    //
# include <stdlib.h>	//
# include <unistd.h>	//

int	get_next_line(const int fd, char **line);

#endif
