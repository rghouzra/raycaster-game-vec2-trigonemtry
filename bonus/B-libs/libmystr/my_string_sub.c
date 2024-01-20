/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_string_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 05:20:30 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/12 01:56:18 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmystr.h"

char	*my_string_sub(char *s, int start, int len)
{
	int		i;
	char	*r;

	i = my_string_len(s);
	if (start < 0)
		start = 0;
	if (start >= i || len <= 0)
		return (my_string_dup(""));
	if (len > (i - start))
		len = (i - start);
	r = (char *)malloc(sizeof(char) * (len + 1));
	if (!r)
		return (NULL);
	i = start - 1;
	while (++i < (start + len))
		r[i - start] = s[i];
	return (r[i - start] = '\0', r);
}
