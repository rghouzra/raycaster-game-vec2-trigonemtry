/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:24:27 by rghouzra          #+#    #+#             */
/*   Updated: 2022/10/06 09:24:41 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;
	char	character;

	character = (char)c;
	str = (char *)s;
	i = 0;
	while (*(str + i) != character)
	{
		if (*(str + i) == '\0')
			return (NULL);
		i++;
	}
	return (str + i);
}
