/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_string_find_last.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 16:42:28 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/13 16:47:12 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmystr.h"

int	my_string_find_last(char *s, char *to_find)
{
	int	i;
	int	j;

	if (!s)
		return (-1);
	i = my_string_len(s);
	while (i >= 0)
	{
		j = 0;
		while (s[i + j] && s[i + j] == to_find[j])
			j++;
		if (to_find[j] == '\0')
			return (i);
		i--;
	}
	return (-1);
}
