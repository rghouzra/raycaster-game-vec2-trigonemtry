/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouseup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:08:48 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/17 10:28:30 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	mouseup(int button, int x, int y, t_data *data)
{
	(void)button;
	(void)x;
	(void)y;
	data->mouse_on = false;
	return (0);
}
