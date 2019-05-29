/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/20 16:59:06 by umoff             #+#    #+#             */
/*   Updated: 2019/05/21 14:34:23 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t res;
	size_t i;

	i = 0;
	res = 0;
	if (!s2 || !s1)
		return (0);
	if (s1 && s2)
	{
		while (i < n)
		{
			if (s1[i] != s2[i])
				res = (s1[i] - s2[i]);
			i++;
		}
		if (res != 0)
			return (0);
	}
	return (1);
}
