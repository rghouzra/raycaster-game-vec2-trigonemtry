/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 13:57:26 by rghouzra          #+#    #+#             */
/*   Updated: 2022/10/08 17:44:38 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*dst;
	char	*source;
	size_t	i;

	i = -1;
	dst = (char *)dest;
	source = (char *)src;
	if (!dst && !source)
		return (NULL);
	if (src < dest && n > i + 1)
	{
		while (n)
		{
			n--;
			*(dst + n) = *(source + n);
		}
	}
	else
	{
		while (++i < n)
		{
			*(dst + i) = *(source + i);
		}
	}
	return (dst);
}
