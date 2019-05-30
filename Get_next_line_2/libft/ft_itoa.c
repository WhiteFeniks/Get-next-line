/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 21:33:17 by umoff             #+#    #+#             */
/*   Updated: 2019/05/21 14:34:23 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	len_number(int n)
{
	int	len;

	len = 1;
	while ((n = n / 10))
		len++;
	return (len);
}

char		*ft_itoa(int n)
{
	char			*buf;
	int				len;
	unsigned int	num;

	len = len_number(n);
	num = n;
	if (n < 0)
	{
		num = -n;
		len++;
	}
	if (!(buf = ft_strnew(len)))
		return (NULL);
	buf[len--] = '\0';
	buf[len--] = num % 10 + '0';
	while (len != -1)
	{
		num = num / 10;
		buf[len] = num % 10 + '0';
		len--;
	}
	if (n < 0)
		buf[0] = '-';
	return (buf);
}
