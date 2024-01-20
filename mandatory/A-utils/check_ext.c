/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 05:10:17 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/11 05:22:09 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	check_ext(char *file_name, char *ext)
{
	int	i;
	int	j;

	j = my_string_len(file_name);
	i = my_string_len(ext);
	if (j <= i)
		return (false);
	while (i >= 0 && file_name[j] == ext[i])
	{
		j--;
		i--;
	}
	if (i != -1)
		return (false);
	return (true);
}
