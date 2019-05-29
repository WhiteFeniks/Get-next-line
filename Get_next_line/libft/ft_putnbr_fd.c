/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: umoff <umoff@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 20:35:36 by umoff             #+#    #+#             */
/*   Updated: 2019/05/21 14:34:23 by umoff            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int digt;

	if (fd > 0)
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			digt = -n;
		}
		else
			digt = n;
		if (digt >= 10)
		{
			ft_putnbr_fd(digt / 10, fd);
			ft_putnbr_fd(digt % 10, fd);
		}
		else
			ft_putchar_fd(digt + '0', fd);
	}
}
