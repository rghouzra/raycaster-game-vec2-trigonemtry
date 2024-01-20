/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmystr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 04:33:13 by yrhiba            #+#    #+#             */
/*   Updated: 2023/05/03 10:16:45 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMYSTR_H
# define LIBMYSTR_H

/*
	A string is a list of characters end whit '\0' character.
	A list of Strings is a List os Strings end whit (null) address.
*/

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define LS_EQUAL 0
# define LS_GREAT 1
# define LS_LESS 2
# define LS_ERR -1

/*
	part one string
*/
int		my_string_compare(char *s1, char *s2);
char	*my_string_join(char *s1, char *s2);
int		my_string_append(char **s, char *to_append);
int		my_string_append_char(char **s, char c);
char	*my_string_dup(char *s);
int		my_string_swap(char **s1, char **s2);
int		my_string_update(char **s, char *to_update);
int		my_string_size(char *s);
int		my_string_len(char *s);
char	**my_string_split(char *s, char *deliminators);
char	*my_string_sub(char *s, int start, int len);
int		my_string_have(char *s, int c);
int		my_string_words_count(char *s, char *deliminators);
int		my_string_find_first(char *s, char *to_find);
int		my_string_find_last(char *s, char *to_find);
char	**my_string_split_by_first(char *s, char *del);
char	*my_string_replace_char(char *s, char c, char to);
bool	my_string_isnumber(char *s);
char	*my_string_dup_strfill_with_char(char c, int len);

/*
	part two strings
*/
int		my_strings_sort(char **strs);
int		my_strings_count(char **strs);
void	my_strings_free(char ***strs);
char	**my_strings_dup_count(char **strs, int count);
void	my_strings_free_count(char ***strs, int count);

#endif
