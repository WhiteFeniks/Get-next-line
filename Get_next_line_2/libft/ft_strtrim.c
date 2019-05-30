/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 20:13:01 by umoff             #+#    #+#             */
/*   Updated: 2019/05/21 14:34:23 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*delete_space(char const *s)
{
	int		i;
	int		j;
	char	*buf;
	char	*box;

	i = 0;
	j = 0;
	if ((box = ft_strnew(ft_strlen(s))) == '\0')
		return (0);
	if ((buf = ft_strnew(ft_strlen(s))) == '\0')
		return (0);
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (s[i] != '\0')
		buf[j++] = s[i++];
	while (j != 0 && (buf[j] == ' ' || buf[j] == '\n' || buf[j] == '\t'
												|| buf[j] == '\0'))
		j--;
	i = 0;
	while (i <= j)
	{
		box[i] = buf[i];
		i++;
	}
	return (box);
}

char		*ft_strtrim(char const *s)
{
	char	*res;
	char	*bask;
	int		j;

	if (s == '\0')
		return (0);
	if ((bask = ft_strnew(ft_strlen(s))) == '\0')
		return (0);
	bask = delete_space(s);
	if ((res = ft_strnew(ft_strlen(bask))) == '\0')
		return (0);
	j = 0;
	while (bask[j] != '\0')
	{
		res[j] = bask[j];
		j++;
	}
	return (res);
}
