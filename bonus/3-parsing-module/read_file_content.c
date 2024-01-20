/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_content.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 00:44:42 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/12 00:45:22 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	read_file_content(t_data *data, char *file_path)
{
	int		fd;
	char	*line;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (false);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (my_list_push_back(&data->map_file_lines,
				my_list_new_elem(my_string_replace_char(line, '\n', '\0'),
					my_string_free)) == -1)
			return (my_list_clear(&(data->map_file_lines), my_string_free),
				close(fd), false);
	}
	return (close(fd), true);
}
