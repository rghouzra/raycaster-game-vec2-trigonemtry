/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:40:28 by rghouzra          #+#    #+#             */
/*   Updated: 2023/07/05 18:50:35 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlength(int n)
{
	int		length;
	long	nbr;

	nbr = n;
	length = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		length++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		length++;
		nbr /= 10;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len_of_n;
	long	nbr;
	char	*number;

	nbr = n;
	len_of_n = ft_numlength(n);
	i = len_of_n ;
	number = ft_malloc((len_of_n + 1) * sizeof(char));
	if (!number)
		return (NULL);
	number[i--] = '\0';
	if (nbr < 0)
		nbr = -nbr;
	if (nbr == 0)
		number[0] = '0';
	while (nbr > 0)
	{
		number[i--] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (n < 0)
		number[i] = '-';
	return (number);
}
