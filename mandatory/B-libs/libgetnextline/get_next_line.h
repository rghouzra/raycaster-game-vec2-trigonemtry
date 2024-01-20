/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 02:44:00 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/11 05:35:00 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

t_list				*ft_newnode(char *content, int fd);
int					ft_strlc(char *s, int len0_or_chr1);
char				*ft_join(char *s1, char *s2);
char				*get_next_line(int fd);
char				*ft_get_content(t_list **list_o, int fd);
void				delete_node(t_list **list, int fd);

#endif
