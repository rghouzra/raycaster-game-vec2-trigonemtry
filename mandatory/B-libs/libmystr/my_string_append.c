/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_string_append.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:21:32 by yrhiba            #+#    #+#             */
/*   Updated: 2023/06/13 15:49:58 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmystr.h"

int	my_string_append(char **s, char *to_append)
{
	char	*r;

	if (!to_append)
		return (-1);
	if (!(*s))
	{
		r = my_string_dup(to_append);
		if (!r)
			return (-1);
		return (*s = r, 0);
	}
	r = my_string_join(*s, to_append);
	if (!r)
		return (-1);
	return (free(*s), *s = r, 0);
}
