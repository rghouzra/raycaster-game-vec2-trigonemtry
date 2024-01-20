/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 03:30:18 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/12 03:32:11 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

bool	is_valid_color(t_color *color)
{
	if (color->red < 0 || color->blue < 0 || color->green < 0)
		return (false);
	if (color->red > 255 || color->blue > 255 || color->green > 255)
		return (false);
	return (true);
}
