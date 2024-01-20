/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:23:04 by rghouzra          #+#    #+#             */
/*   Updated: 2023/07/05 18:51:46 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int			i;
	int			j;
	int			length;
	char		*strings;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	strings = (char *)ft_malloc(length * sizeof (char));
	if (!strings)
		return (strings);
	while (*(s1 + i))
	{
		*(strings + i) = *(s1 + i);
		i++;
	}
	while (*(s2 + j))
		strings[i++] = s2[j++];
	*(strings + i) = '\0';
	return (strings);
}
