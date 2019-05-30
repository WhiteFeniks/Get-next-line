/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 18:29:50 by umoff             #+#    #+#             */
/*   Updated: 2019/05/21 14:34:23 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int digt;

	if (n < 0)
	{
		ft_putchar('-');
		digt = -n;
	}
	else
		digt = n;
	if (digt >= 10)
	{
		ft_putnbr(digt / 10);
		ft_putnbr(digt % 10);
	}
	else
		ft_putchar(digt + '0');
}
