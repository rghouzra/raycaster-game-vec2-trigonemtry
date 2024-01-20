/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strings_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:11:05 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/03 10:29:51 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmystr.h"

static void	dump_sort(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		if (i && my_string_compare(strs[i], strs[i - 1]) == LS_LESS)
			my_string_swap(&strs[i], &strs[i - 1]);
}

int	my_strings_sort(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		dump_sort(strs);
	return (0);
}
