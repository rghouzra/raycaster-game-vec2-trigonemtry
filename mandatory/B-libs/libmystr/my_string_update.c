/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_string_update.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 22:46:47 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/03 10:19:04 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmystr.h"

int	my_string_update(char **s, char *to_update)
{
	char	*r;

	if (!to_update)
	{
		if (!(*s))
			return (0);
		return (free(*s), *s = NULL, 0);
	}
	r = my_string_dup(to_update);
	if (!r)
		return (-1);
	if (*s != NULL)
		free(*s);
	return (*s = r, 0);
}
