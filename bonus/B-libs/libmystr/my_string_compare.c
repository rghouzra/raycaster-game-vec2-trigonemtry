/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_string_compare.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 04:39:07 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/29 17:08:31 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmystr.h"

int	my_string_compare(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (LS_ERR);
	while (*s1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 > *s2)
		return (LS_GREAT);
	if (*s1 < *s2)
		return (LS_LESS);
	return (LS_EQUAL);
}
