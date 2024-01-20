/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 02:57:40 by yrhiba            #+#    #+#             */
/*   Updated: 2023/07/05 18:53:25 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_join(char *s1, char *s2)
{
	char	*rtn;
	char	*tmp;
	int		i;

	rtn = (char *)ft_malloc(sizeof(char) * (ft_strlc(s1, 0) + ft_strlc(s2, 0)
				+ 1));
	if (!rtn)
		return (NULL);
	tmp = rtn;
	i = 0;
	while (s1[i])
		*tmp++ = s1[i++];
	i = 0;
	while (s2[i])
		*tmp++ = s2[i++];
	*tmp = '\0';
	free(s1);
	return (rtn);
}

int	ft_strlc(char *s, int len0_or_chr1)
{
	int	i;

	i = 0;
	while (s[i] && len0_or_chr1)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	if (!len0_or_chr1)
	{
		while (s[i])
			i++;
		return (i);
	}
	return (-1);
}

t_list	*ft_newnode(char *content, int fd)
{
	t_list	*node;

	node = (t_list *)ft_malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->fd = fd;
	node->next = 0;
	return (node);
}

char	*ft_get_content(t_list **list_o, int fd)
{
	t_list	*new;
	t_list	*list;
	char	*rtn;

	list = *list_o;
	while (list)
	{
		if (list->fd == fd)
			return (list->content);
		list = list->next;
	}
	rtn = (char *)ft_malloc(sizeof(char));
	if (!rtn)
		return (NULL);
	*rtn = '\0';
	new = ft_newnode(rtn, fd);
	if (!new)
	{
		free(rtn);
		return (NULL);
	}
	new->next = *list_o;
	*list_o = new;
	return ((*list_o)->content);
}

void	delete_node(t_list **list, int fd)
{
	t_list	*tmp;
	t_list	*nex;
	t_list	*prev;

	tmp = *list;
	prev = NULL;
	while (tmp)
	{
		nex = tmp->next;
		if (tmp->fd == fd)
		{
			free(tmp->content);
			free(tmp);
			if (prev)
				prev->next = nex;
			else
				*list = nex;
			return ;
		}
		prev = tmp;
		tmp = tmp->next;
	}
}
