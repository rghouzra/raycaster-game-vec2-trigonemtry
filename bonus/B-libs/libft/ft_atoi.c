/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:18:12 by rghouzra          #+#    #+#             */
/*   Updated: 2023/07/14 10:45:27 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "limits.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	n;
	int	i;

	n = 0;
	i = 0;
	sign = 1;
	while ((*(nptr + i) >= 9 && *(nptr + i) <= 13) || *(nptr + i) == ' ')
		i++;
	if (*(nptr + i) == '+' || *(nptr + i) == '-')
	{
		if (*(nptr + i) == '-')
			sign = -1;
		i++;
	}
	while ((*(nptr + i) >= '0' && *(nptr + i) <= '9') && *(nptr + i))
	{
		n *= 10;
		n += *(nptr + i) - 48;
		i++;
	}
	return (n * sign);
}
