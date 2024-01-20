/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_strings_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:08:17 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/21 03:02:44 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmystr.h"

void	my_strings_free(char ***strs)
{
	int	i;

	i = 0;
	if (!strs || !(*strs))
		return ;
	while ((*strs)[i])
		free((*strs)[i++]);
	free(*strs);
	*strs = (char **)0;
}
