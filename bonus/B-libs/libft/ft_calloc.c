/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:40:17 by rghouzra          #+#    #+#             */
/*   Updated: 2023/07/05 18:50:25 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	char	*ptr;

	ptr = (char *)ft_malloc(nelem * elsize);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, '\0', (nelem * elsize));
	return (ptr);
}
