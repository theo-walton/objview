/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 13:03:28 by twalton           #+#    #+#             */
/*   Updated: 2018/04/14 14:37:52 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_view.h"

void	load_textures(void)
{
	int i;

	i = -1;
	while (++i < TOTAL_TEXTURES)
	{
		parse_texture(i);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
		glGenTextures(1, &g_texture_id[i]);
		glBindTexture(GL_TEXTURE_2D, g_texture_id[i]);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, g_texture_width,
		g_texture_height, 0, GL_BGR, GL_UNSIGNED_BYTE, g_texture_data);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
				GL_LINEAR_MIPMAP_LINEAR);
		glGenerateMipmap(GL_TEXTURE_2D);
		glActiveTexture(GL_TEXTURE0);
		glUniform1i(g_texture_location, 0);
	}
}
