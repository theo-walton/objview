/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_compilation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 20:03:04 by twalton           #+#    #+#             */
/*   Updated: 2018/04/14 14:32:21 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_view.h"

void	check_compilation(GLuint shader)
{
	GLint	success;
	GLint	logsize;
	char	*log;

	success = 0;
	logsize = 0;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (success == GL_FALSE)
	{
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &logsize);
		log = malloc(sizeof(char) * logsize);
		glGetShaderInfoLog(shader, logsize, NULL, log);
		printf("%s\n", log);
		free(log);
	}
}
