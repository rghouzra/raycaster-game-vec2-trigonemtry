/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 02:43:18 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/17 11:19:22 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_content(char *content, int fd, int *r)
{
	char	*c;

	c = (char *)ft_malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!c)
	{
		free(content);
		return (NULL);
	}
	*c = '\0';
	*r = read(fd, c, BUFFER_SIZE);
	if (*r == -1)
	{
		free(c);
		free(content);
		return (NULL);
	}
	c[*r] = '\0';
	if (*c)
		content = ft_join(content, c);
	free(c);
	return (content);
}

void	get_line_3(char *content, char *nw_content, char *line)
{
	int	i;
	int	j;

	i = 0;
	while (content[i] != '\n')
	{
		line[i] = content[i];
		i++;
	}
	line[i++] = '\n';
	line[i] = '\0';
	j = 0;
	while (content[i])
		nw_content[j++] = content[i++];
	nw_content[j] = '\0';
}

char	*get_line_2(char **content, int index)
{
	char	*line;
	char	*nw_content;

	line = (char *)ft_malloc(sizeof(char) * (index + 2));
	if (!line)
		return (NULL);
	nw_content = (char *)ft_malloc(sizeof(char) * (ft_strlc(*content, 0)
				- index));
	if (!nw_content)
	{
		free(line);
		return (NULL);
	}
	get_line_3(*content, nw_content, line);
	free(*content);
	*content = nw_content;
	if (content && *content == (char *) '\0')
		return (free(content), content = 0, line);
	return (line);
}

char	*get_line_1(char **content, int fd)
{
	char	*l;
	int		r;

	r = 1;
	l = (char *)ft_malloc(sizeof(char));
	if (!l)
		return (NULL);
	*l = '\0';
	while (*content && ft_strlc(*content, 1) == -1 && r != 0)
		*content = read_content(*content, fd, &r);
	if (!*content)
	{
		free(l);
		return (NULL);
	}
	if (r == 0)
	{
		l = ft_join(l, *content);
		free(*content);
		*content = 0;
		if (*l == '\0')
			return (free(l), l = NULL);
		return (l);
	}
	return (free(l), l = get_line_2(content, ft_strlc(*content, 1)), l);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	t_list			*tmp;
	char			*content;
	char			*line;

	if (fd < 0)
		return (NULL);
	content = ft_get_content(&list, fd);
	if (!content)
		return (NULL);
	line = get_line_1(&content, fd);
	tmp = list;
	while (tmp)
	{
		if (tmp->fd == fd)
			tmp->content = content;
		tmp = tmp->next;
	}
	if (!content)
		delete_node(&list, fd);
	return (line);
}
