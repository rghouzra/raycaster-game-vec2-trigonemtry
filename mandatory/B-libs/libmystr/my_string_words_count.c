/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_string_words_count.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 05:48:41 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/03 10:19:04 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmystr.h"

int	my_string_words_count(char *s, char *deliminators)
{
	int	i;
	int	count;

	if (!s || !deliminators)
		return (-1);
	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && my_string_have(deliminators, s[i]))
			i++;
		if (s[i])
			count++;
		while (s[i] && !my_string_have(deliminators, s[i]))
			i++;
	}
	return (count);
}
