/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_string_join.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 23:53:29 by yrhiba            #+#    #+#             */
/*   Updated: 2023/07/05 18:55:43 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmystr.h"

char	*my_string_join(char *s1, char *s2)
{
	char	*r;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	r = (char *)malloc(sizeof(char) * (my_string_len(s1) + my_string_len(s2)
				+ 1));
	if (!r)
		return (NULL);
	i = -1;
	while (s1[++i])
		r[i] = s1[i];
	j = -1;
	while (s2[++j])
		r[i++] = s2[j];
	return (r[i] = '\0', r);
}
