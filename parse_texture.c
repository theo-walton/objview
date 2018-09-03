/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 13:18:41 by twalton           #+#    #+#             */
/*   Updated: 2018/04/14 14:43:50 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_view.h"

static void	bmp_parse(const char *filepath)
{
	int				fd;
	unsigned char	buffer[1000];
	int				offset;

	fd = open(filepath, O_RDONLY);
	read(fd, buffer, 54);
	memmove(&g_texture_width, buffer + 18, sizeof(int));
	memmove(&g_texture_height, buffer + 22, sizeof(int));
	memmove(&offset, buffer + 10, sizeof(int));
	read(fd, buffer, offset - 54);
	read(fd, g_texture_data, g_texture_width * g_texture_height * 3);
	close(fd);
}

void		parse_texture(int index)
{
	const char *filepath;

	filepath = g_texture_paths[index];
	bmp_parse(filepath);
}
