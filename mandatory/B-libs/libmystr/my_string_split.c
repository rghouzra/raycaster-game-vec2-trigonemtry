/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_string_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 05:14:15 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/03 10:20:38 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmystr.h"

static void	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
}

static int	remp_strs(char **strs, char *s, char *deliminators)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && my_string_have(deliminators, s[i]))
			i++;
		if (s[i])
		{
			start = i;
			while (s[i] && !my_string_have(deliminators, s[i]))
				i++;
			strs[j] = my_string_sub(s, start, i - start);
			if (!strs[j])
				return (free_strs(strs), -1);
			j++;
		}
	}
	strs[j] = (char *)0;
	return (0);
}

char	**my_string_split(char *s, char *deliminators)
{
	char	**strs;

	if (!s)
		return (NULL);
	strs = (char **)malloc(sizeof(char *) * (my_string_words_count(s,
					deliminators) + 1));
	if (!strs)
		return (NULL);
	if (remp_strs(strs, s, deliminators) == -1)
		return (free(strs), NULL);
	return (strs);
}
