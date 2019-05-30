/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:57:59 by umoff             #+#    #+#             */
/*   Updated: 2019/05/21 14:34:23 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *old_s, const char *new_s)
{
	unsigned int i;
	unsigned int j;

	if (!*new_s)
		return ((char*)old_s);
	i = 0;
	while (old_s[i] != '\0')
	{
		if (old_s[i] == new_s[0])
		{
			j = 1;
			while ((new_s[j] != '\0') && (old_s[i + j] == new_s[j]))
				j++;
			if (new_s[j] == '\0')
				return ((char*)&old_s[i]);
		}
		i++;
	}
	return (0);
}
