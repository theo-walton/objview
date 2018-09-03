/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 12:39:20 by twalton           #+#    #+#             */
/*   Updated: 2018/04/10 12:39:20 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_view.h"

void	draw_object(void)
{
	glUniformMatrix4fv(g_transform_location, 1, GL_FALSE, g_transform.array);
	glBindTexture(GL_TEXTURE_2D, g_texture_id[g_texture_index]);
	glActiveTexture(GL_TEXTURE0);
	glUniform1i(g_texture_location, 0);
	glBindBuffer(GL_ARRAY_BUFFER, g_vertex_array_id);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, g_vertex_amount);
	glDisableVertexAttribArray(0);
}
