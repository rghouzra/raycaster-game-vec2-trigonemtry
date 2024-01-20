/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousedown.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:06:05 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/17 10:28:31 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	mousedown(int button, int x, int y, t_data *data)
{
	(void)button;
	if (x >= 0 && x < WIN_WIDTH && y >= 0 && y < WIN_HEIGHT)
		data->mouse_on = true;
	return (0);
}
