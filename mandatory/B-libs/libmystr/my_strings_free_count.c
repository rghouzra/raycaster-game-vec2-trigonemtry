/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strings_free_count.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 00:32:37 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/31 00:37:24 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmystr.h"

void	my_strings_free_count(char ***strs, int count)
{
	int	i;

	if (!(*strs))
		return ;
	i = -1;
	while (++i < count)
	{
		if ((*strs)[i])
			free((*strs)[i]);
	}
	free(*strs);
	*strs = NULL;
}
