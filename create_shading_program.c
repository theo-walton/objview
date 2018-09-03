/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_shading_program.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 00:02:42 by twalton           #+#    #+#             */
/*   Updated: 2017/11/13 00:02:42 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_view.h"

void	create_shading_program(void)
{
	compile_vertex_shader();
	compile_fragment_shader();
	g_program_id = glCreateProgram();
	glAttachShader(g_program_id, g_vertex_shader_id);
	glAttachShader(g_program_id, g_fragment_shader_id);
	glLinkProgram(g_program_id);
}
