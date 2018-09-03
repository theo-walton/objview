/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compile_fragment_shader.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 23:43:14 by twalton           #+#    #+#             */
/*   Updated: 2018/04/14 14:33:07 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_view.h"

void	compile_fragment_shader(void)
{
	char	*shader;
	int		fd;

	fd = open("fragment_shader.glsl", O_RDONLY);
	if (!fd)
		exit(1);
	shader = ft_dirty_read(fd, 2000);
	g_fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(g_fragment_shader_id, 1, (const GLchar**)&shader, NULL);
	glCompileShader(g_fragment_shader_id);
	check_compilation(g_fragment_shader_id);
	free(shader);
	close(fd);
}
