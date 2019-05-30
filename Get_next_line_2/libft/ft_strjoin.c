/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 19:27:03 by umoff             #+#    #+#             */
/*   Updated: 2019/05/21 14:34:23 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*buf;

	i = 0;
	j = 0;
	if ((!(s1)) || (!(s2)))
		return (0);
	if (!(buf = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (0);
	while (s1[i])
	{
		buf[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		buf[i] = s2[j];
		j++;
		i++;
	}
	return (buf);
}
