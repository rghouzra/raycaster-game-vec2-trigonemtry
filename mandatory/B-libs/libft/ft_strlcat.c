/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:10:29 by rghouzra          #+#    #+#             */
/*   Updated: 2022/10/06 10:10:33 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	largsrc;
	size_t	largdestcomp;

	j = 0;
	largdestcomp = ft_strlen(dst);
	largsrc = ft_strlen(src);
	i = largdestcomp;
	if (!(dst) || !(src))
		return (0);
	if (size == 0)
		return (largsrc);
	if (size < largdestcomp)
		return (largsrc + size);
	while (src[j] && i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (largdestcomp + largsrc);
}
