/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_get_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 11:55:59 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/14 12:50:38 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	frame_get_color(t_frame *frame, int i, int j)
{
	char	*dst;

	dst = frame->addr + (j * frame->line_length + i * (frame->bits_per_pixel
				/ 8));
	return (*((int *)dst));
}
