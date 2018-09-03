/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_triangle_array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 23:38:18 by twalton           #+#    #+#             */
/*   Updated: 2018/04/14 14:36:54 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_view.h"

#define V(X) (g_parsed_vertices + 3 * (X))
#define VERTEX_ARRAY_END g_vertex_array + 3 * g_vertex_amount
#define INC g_vertex_amount++;
#define ADD_POINT(X) memmove(VERTEX_ARRAY_END, V(X), sizeof(float) * 3); INC

static void	add_triangles(int *faces)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (faces[i] <= 0 || faces[i] >= 100000)
			faces[i] = (i == 3 ? 0 : 1);
		i++;
	}
	ADD_POINT(faces[0] - 1);
	ADD_POINT(faces[1] - 1);
	ADD_POINT(faces[2] - 1);
	if (faces[3] == 0)
		return ;
	ADD_POINT(faces[0] - 1);
	ADD_POINT(faces[2] - 1);
	ADD_POINT(faces[3] - 1);
}

void		fill_triangle_array(int total_faces)
{
	int i;

	i = 0;
	g_vertex_array = malloc(sizeof(float) * total_faces * 18);
	while (i < total_faces * 4)
	{
		add_triangles(g_parsed_faces + i);
		i += 4;
	}
}
