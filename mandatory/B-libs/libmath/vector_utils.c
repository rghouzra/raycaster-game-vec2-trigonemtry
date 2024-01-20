/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rghouzra <rghouzra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 06:32:58 by rghouzra          #+#    #+#             */
/*   Updated: 2024/01/18 06:33:15 by rghouzra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

size_t	veclength(t_vec2 vector)
{
	return (sqrt((vector.cord.x * vector.cord.x) + (vector.cord.y
				* vector.cord.y)));
}

t_vec2	normalize_vector(t_vec2 vector, size_t length)
{
	if (length)
		return ((t_vec2){vector.cord.x / length, vector.cord.y / length});
	return (vector);
}

t_vec2	op_two_vectors(t_vec2 vec1, t_vec2 vec2, uint16_t op)
{
	if (op == ADD)
		return ((t_vec2){vec1.cord.x + vec2.cord.x, vec1.cord.y + vec2.cord.y});
	if (op == SUB)
		return ((t_vec2){vec1.cord.x - vec2.cord.x, vec1.cord.y - vec2.cord.y});
	if (op == MUL)
		return ((t_vec2){vec1.cord.x * vec2.cord.x, vec1.cord.y * vec2.cord.y});
	if (op == DIV)
		return ((t_vec2){vec1.cord.x / vec2.cord.x, vec1.cord.y / vec2.cord.y});
	return ((t_vec2){-1, -1});
}

/*
	rotation matrix
	|cos teta  -sin teta|
	|sin teta  cos teta|
*/
t_vec2	rotate_vec(t_vec2 vec, double angle)
{
	t_vec2	res;
	double	costeta;
	double	sinteta;

	costeta = cos(angle);
	sinteta = sin(angle);
	res.cord.x = (vec.cord.x * costeta) - (vec.cord.y * sinteta);
	res.cord.y = (vec.cord.x * sinteta) + (vec.cord.y * costeta);
	return (res);
}

double	dotproduct(t_vec2 vec1, t_vec2 vec2)
{
	return ((vec1.cord.x * vec2.cord.x) + (vec1.cord.y * vec2.cord.y));
}
