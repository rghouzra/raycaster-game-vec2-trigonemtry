/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evector_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:21:12 by rghouzra          #+#    #+#             */
/*   Updated: 2024/01/18 06:33:38 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec2	scalevec(t_vec2 vector, double scale)
{
	return ((t_vec2){scale * vector.cord.x, scale * vector.cord.y});
}

double	dot_product(t_vec2 vec1, t_vec2 vec2)
{
	return (vec1.cord.x * vec2.cord.x + vec1.cord.y * vec2.cord.y);
}
