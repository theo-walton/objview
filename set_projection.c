/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_projection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 13:33:03 by twalton           #+#    #+#             */
/*   Updated: 2018/04/14 14:49:30 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_view.h"

void	set_projection(void)
{
	const float projection[16] = {
				2.39012, 0, 0, 0,
				0, 1.79259, 0, 0,
				0, 0, -1.002, -1,
				0, 0, -0.2002, 0};

	glUniformMatrix4fv(g_projection_location, 1, GL_FALSE, projection);
}
