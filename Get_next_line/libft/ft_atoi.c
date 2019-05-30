/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 20:25:56 by umoff             #+#    #+#             */
/*   Updated: 2019/05/21 14:34:23 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	unsigned long		i;
	unsigned long long	otvet;
	int					minus;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	otvet = 0;
	minus = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] != '\0' && ((str[i] >= '0' && str[i] <= '9')))
	{
		otvet = (unsigned long long)(otvet * 10 + (str[i] - '0'));
		if (otvet > (long long)FT_MAX_ATOI && minus == 1)
			return (-1);
		if (otvet > (long long)FT_MAX_ATOI && minus == -1)
			return (0);
		i++;
	}
	return ((int)minus * otvet);
}
