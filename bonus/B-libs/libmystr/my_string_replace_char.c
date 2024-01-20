/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_string_replace_char.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 14:04:50 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/17 11:14:33 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*my_string_replace_char(char *s, char c, char to)
{
	int	i;

	if (!s)
		return ((char *)0);
	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			s[i] = to;
	}
	return (s);
}

/*
Not Safe if You Pass s as read only Memory.!!!
*/