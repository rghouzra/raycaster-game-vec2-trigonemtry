/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 17:15:31 by rghouzra          #+#    #+#             */
/*   Updated: 2022/10/05 17:15:35 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last;
	int		counter;

	last = lst;
	counter = 0;
	while (lst)
	{
		lst = lst->next;
		counter++;
	}
	while (counter > 1)
	{
		last = last->next;
		counter--;
	}
	return (last);
}
