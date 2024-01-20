/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 08:35:26 by rghouzra          #+#    #+#             */
/*   Updated: 2022/10/08 23:07:17 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*help;

	head = NULL;
	while (lst)
	{
		help = ft_lstnew(f(lst->content));
		if (!help)
		{
			ft_lstclear(&help, del);
			return (NULL);
		}
		ft_lstadd_back(&head, help);
		lst = lst->next;
	}
	return (head);
}
