/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_uniform_locations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 13:22:58 by twalton           #+#    #+#             */
/*   Updated: 2018/04/14 14:49:56 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_view.h"

void	set_uniform_locations(void)
{
	g_projection_location = glGetUniformLocation(g_program_id, "projection");
	g_transform_location = glGetUniformLocation(g_program_id, "transform");
	g_texture_location = glGetUniformLocation(g_program_id, "tex");
}
