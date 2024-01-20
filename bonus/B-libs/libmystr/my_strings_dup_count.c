/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strings_dup_count.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 14:33:33 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/07 16:54:04 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmystr.h"

char	**my_strings_dup_count(char **strs, int count)
{
	char	**r;
	int		i;

	if (!strs)
		return (NULL);
	r = (char **)malloc(sizeof(char *) * count);
	if (!r)
		return (NULL);
	i = -1;
	while (++i < count)
		r[i] = my_string_dup(strs[i]);
	return (r);
}
