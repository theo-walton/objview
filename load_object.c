/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 12:54:26 by twalton           #+#    #+#             */
/*   Updated: 2018/04/14 14:36:21 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_view.h"

#define DATA_SIZE g_vertex_amount * 3 * sizeof(GLfloat)

void	load_object(void)
{
	glGenBuffers(1, &g_vertex_array_id);
	glBindBuffer(GL_ARRAY_BUFFER, g_vertex_array_id);
	glBufferData(GL_ARRAY_BUFFER, DATA_SIZE,
		g_vertex_array, GL_STATIC_DRAW);
}
