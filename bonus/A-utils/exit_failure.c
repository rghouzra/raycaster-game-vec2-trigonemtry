/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_failure.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yrhiba <yrhiba@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 00:10:38 by yrhiba            #+#    #+#             */
/*   Updated: 2024/01/11 00:11:00 by yrhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	exit_failure(const char *errmsg)
{
	printf("Error\n");
	printf("%s\n", errmsg);
	exit(EXIT_FAILURE);
}
