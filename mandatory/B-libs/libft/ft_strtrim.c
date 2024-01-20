/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:34:08 by rghouzra          #+#    #+#             */
/*   Updated: 2023/07/05 18:51:53 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	comp(char cs, char cset)
{
	if (cs == cset)
		return (1);
	return (0);
}

static int	first_set(char const *s, char const *set)
{
	int	i;
	int	j;
	int	check_set;

	i = 0;
	while (*(s + i))
	{
		j = 0;
		check_set = 0;
		while (set[j])
		{
			if (comp(s[i], set[j]))
				check_set++;
			j++;
		}
		if (!check_set)
			break ;
		i++;
	}
	return (i);
}

static int	second_set(char const *s1, char const *set, int index)
{
	int	j;
	int	check_set;

	while (index)
	{
		j = 0;
		check_set = 0;
		while (*(set + j))
		{
			if (comp(s1[index], *(set + j)))
				check_set++;
			j++;
		}
		if (!check_set)
			break ;
		index--;
	}
	return (index);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int			i;
	int			j;
	char const	*first;
	char		*str_trim;
	int			k;

	if (!s1 || !set)
		return (NULL);
	first = s1 + first_set(s1, set);
	k = ft_strlen(first) - 1;
	i = second_set(first, set, k);
	j = ft_strlen(first) - i;
	str_trim = (char *)ft_malloc((j + 2) * sizeof(char));
	if (!str_trim)
		return (NULL);
	j = 0;
	while (j < (i + 1))
	{
		str_trim[j] = first[j];
		j++;
	}
	str_trim[j] = '\0';
	return (str_trim);
}
