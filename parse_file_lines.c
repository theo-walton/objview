/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 15:55:54 by twalton           #+#    #+#             */
/*   Updated: 2018/04/14 14:44:53 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_view.h"

static int	go_to_next_line(char **str)
{
	while (**str != '\n' && **str != '\0')
		(*str)++;
	if (**str == '\n')
	{
		(*str)++;
		return (1);
	}
	return (0);
}

static void	parse_vertex(char *str, float *array)
{
	char *temp;

	str += 2;
	array[0] = strtof(str, &temp);
	str = temp;
	array[1] = strtof(str, &temp);
	str = temp;
	array[2] = strtof(str, NULL);
}

static void	parse_face(char *str, int *array)
{
	char *temp;
	char *newline_pos;

	newline_pos = strchr(str, '\n');
	str += 2;
	array[0] = strtol(str, &temp, 10);
	str = temp;
	array[1] = strtol(str, &temp, 10);
	str = temp;
	array[2] = strtol(str, &temp, 10);
	str = temp;
	array[3] = strtol(str, &temp, 10);
	if (temp > newline_pos)
		array[3] = 0;
}

void		parse_file_lines(char *str, int *total_faces)
{
	int another_line;
	int total_vert;

	total_vert = 0;
	another_line = 1;
	while (another_line)
	{
		if (!strncmp(str, "v ", 2))
		{
			parse_vertex(str, g_parsed_vertices + total_vert * 3);
			total_vert++;
		}
		if (!strncmp(str, "f ", 2))
		{
			parse_face(str, g_parsed_faces + *total_faces * 4);
			(*total_faces)++;
		}
		another_line = go_to_next_line(&str);
	}
}
