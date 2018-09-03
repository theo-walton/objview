/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 13:39:05 by twalton           #+#    #+#             */
/*   Updated: 2018/04/14 14:46:50 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_view.h"

void	parse_obj_file(char *filepath)
{
	int		fd;
	char	*filestr;
	int		total_faces;

	total_faces = 0;
	fd = open(filepath, O_RDONLY);
	if (fd < 0)
	{
		printf("bad filepath\n");
		exit(1);
	}
	g_parsed_vertices = malloc(sizeof(float) * 300000);
	g_parsed_faces = malloc(sizeof(int) * 400000);
	filestr = ft_dirty_read(fd, 1000000);
	close(fd);
	parse_file_lines(filestr, &total_faces);
	fill_triangle_array(total_faces);
	free(g_parsed_vertices);
	free(g_parsed_faces);
	free(filestr);
}
