/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:19:48 by rghouzra          #+#    #+#             */
/*   Updated: 2022/10/06 09:20:55 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find_str(char *str, char *to_find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*str && i < len)
	{
		j = 0;
		while ((*(str + j) == *(to_find + j)) && (i + j) < len && *(str + j)
			&& *(to_find + j))
		{
			if (*(to_find + j + 1) == '\0')
				return (str);
			j++;
		}
		str++;
		i++;
	}
	return (0);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*str;
	char	*to_find;
	size_t	len_l;

	len_l = ft_strlen(little);
	str = (char *)big;
	to_find = (char *)little;
	if (!len_l)
		return (str);
	return (find_str(str, to_find, len));
}
