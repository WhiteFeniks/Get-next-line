/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 15:27:45 by umoff             #+#    #+#             */
/*   Updated: 2019/05/21 14:34:23 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buf;
	int		i;

	i = 0;
	buf = NULL;
	if ((s != '\0') && (*s != '\0') && (f != '\0') && (*f != '\0') &&
		(buf = ft_strnew(ft_strlen(s))))
	{
		while (s[i])
		{
			buf[i] = (*f)(((unsigned int)i), ((char)s[i]));
			i++;
		}
		buf[i] = '\0';
	}
	return (buf);
}
