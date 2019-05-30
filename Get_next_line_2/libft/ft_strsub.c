/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 17:05:59 by umoff             #+#    #+#             */
/*   Updated: 2019/05/21 14:34:23 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*buf;

	i = 0;
	buf = NULL;
	if ((!s) || (!*s) || (start + len > ft_strlen(s)))
		return (0);
	if ((buf = ft_strnew(len)) != '\0')
	{
		while (len > 0)
		{
			len--;
			buf[i] = s[start];
			i++;
			start++;
		}
		buf[i] = '\0';
	}
	return (buf);
}
