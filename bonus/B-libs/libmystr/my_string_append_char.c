/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_string_append_char.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 00:15:11 by yrhiba            #+#    #+#             */
/*   Updated: 2023/07/05 18:56:15 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmystr.h"

static void	my_string_copy(char *from, char *to)
{
	int	i;

	i = -1;
	while (from[++i])
		to[i] = from[i];
	to[i] = '\0';
}

int	my_string_append_char(char **s, char c)
{
	char	*r;
	int		size;

	if (!(*s))
	{
		r = (char *)malloc(sizeof(char) * 2);
		if (!r)
			return (-1);
		return (*r = c, *(r + 1) = '\0', *s = r, 0);
	}
	size = my_string_size(*s);
	r = (char *)malloc(sizeof(char) * (size + 1));
	if (!r)
		return (-1);
	my_string_copy(*s, r);
	r[size - 1] = c;
	r[size] = '\0';
	return (free(*s), *s = r, 0);
}
