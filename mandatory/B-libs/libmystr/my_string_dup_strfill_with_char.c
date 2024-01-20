/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_string_dup_strfill_with_char.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 02:55:41 by yrhiba            #+#    #+#             */
/*   Updated: 2023/08/05 03:21:52 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmystr.h"

char	*my_string_dup_strfill_with_char(char c, int len)
{
	char	*s;
	int		i;

	s = (char *)malloc(sizeof(char) * (len + 1));
	if (!s)
		return ((char *)0);
	i = 0;
	while (i < len)
		s[i++] = c;
	s[i] = '\0';
	return (s);
}
