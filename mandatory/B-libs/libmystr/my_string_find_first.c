/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_string_find_first.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:42:06 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/13 16:47:16 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmystr.h"

int	my_string_find_first(char *s, char *to_find)
{
	int	i;
	int	j;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
	{
		j = 0;
		while (s[i + j] && s[i + j] == to_find[j])
			j++;
		if (to_find[j] == '\0')
			return (i);
		i++;
	}
	return (-1);
}
