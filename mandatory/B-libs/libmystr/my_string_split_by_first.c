/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_string_split_by_first.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 23:20:39 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/12 02:24:57 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmystr.h"

static void	find_spliters_(char *s, char *del, int *indexs)
{
	int	i;

	i = 0;
	while (s[i] && my_string_have(del, s[i]))
		i++;
	indexs[0] = i;
	while (s[i])
	{
		if (my_string_have(del, s[i]))
			break ;
		i++;
	}
	indexs[1] = i;
	while (s[i])
	{
		if (!my_string_have(del, s[i]))
			break ;
		i++;
	}
	indexs[2] = i;
	i = my_string_len(s) - 1;
	while (i >= indexs[2] && my_string_have(del, s[i]))
		i--;
	indexs[3] = i + 1;
}

char	**my_string_split_by_first(char *s, char *del)
{
	char	**r;
	int		indexs[4];

	r = (char **)malloc(sizeof(char *) * 3);
	if (!r)
		return (NULL);
	r[2] = NULL;
	find_spliters_(s, del, indexs);
	r[0] = my_string_sub(s, indexs[0], indexs[1] - indexs[0]);
	r[1] = my_string_sub(s, indexs[2], indexs[3] - indexs[2]);
	if (!r[0])
		return (my_strings_free_count(&r, 2), NULL);
	return (r);
}
