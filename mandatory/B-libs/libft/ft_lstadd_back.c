/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:40:44 by rghouzra          #+#    #+#             */
/*   Updated: 2022/10/06 10:17:45 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*copy;

	if ((*lst) == NULL)
	{
		*lst = new;
		return ;
	}
	copy = *lst;
	while (copy->next != NULL)
	{
		copy = copy->next;
	}
	copy->next = new;
}
