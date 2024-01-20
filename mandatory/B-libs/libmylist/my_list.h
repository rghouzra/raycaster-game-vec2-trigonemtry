/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:53:00 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/31 00:07:25 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_LIST_H
# define MY_LIST_H

# include <errno.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_my_list
{
	void				*data;
	struct s_my_list	*next;
}						t_my_list;

int						my_list_init(t_my_list **list);
int						my_list_clear(t_my_list **list,
							void (*data_clear)(void **));

t_my_list				*my_list_new_elem(void *data,
							void (*data_clear)(void **));

int						my_list_push_back(t_my_list **list, t_my_list *elem);
int						my_list_push_front(t_my_list **list, t_my_list *elem);

void					*my_list_front(t_my_list *list);
void					*my_list_back(t_my_list *list);

int						my_list_empty(t_my_list *list);
long long				my_list_size(t_my_list *list);

int						my_list_pop_front(t_my_list **list,
							void (*data_clear)(void **));
int						my_list_pop_back(t_my_list **list,
							void (*data_clear)(void **));

void					*my_list_get(t_my_list *list, long long index);
int						my_list_erase(t_my_list **list, long long index,
							void (*data_clear)(void **));

int						my_list_insert(t_my_list **list, t_my_list *elem,
							long long index);

#endif
