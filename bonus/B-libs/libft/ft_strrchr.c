/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:16:08 by rghouzra          #+#    #+#             */
/*   Updated: 2022/10/06 09:19:37 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;
	char	ch;

	ch = (char)c;
	str = (char *)s;
	i = ft_strlen(str);
	while ((int)i >= 0)
	{
		if (str[i] == ch)
			return ((str + i));
		i--;
	}
	return (0);
}
