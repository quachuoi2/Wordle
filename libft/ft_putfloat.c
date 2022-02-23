/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qnguyen <qnguyen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 18:39:42 by qnguyen           #+#    #+#             */
/*   Updated: 2022/02/11 20:15:54 by qnguyen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putfloat(long double lift, int i)
{
	int	temp;

	temp = (int)lift;
	ft_putnbr(temp);
	if (i > 0)
	{
		ft_putchar('.');
		lift -= temp;
		temp = ft_diglen(temp) + 1 + i;
		while (i > 0)
		{
			lift *= 10;
			i--;
		}
		if (lift - (int)lift >= 0.5)
			ft_putnbr((int)lift + 1);
		else
			ft_putnbr((int)lift);
	}
	else
		temp = ft_diglen(temp);
	return (temp);
}
