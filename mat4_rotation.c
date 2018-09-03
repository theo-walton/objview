/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_rotation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:44:28 by twalton           #+#    #+#             */
/*   Updated: 2018/04/14 14:41:40 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_view.h"

#define X x
#define Y y
#define Z z
#define DEG_TO_RAD 0.0174533

t_mat4	mat4_rotation(float x, float y, float z, float degrees)
{
	float	c0;
	float	s0;
	float	c1;
	float	s1;
	t_mat4	rotation;

	c0 = cosf(degrees * DEG_TO_RAD);
	s0 = sinf(degrees * DEG_TO_RAD);
	c1 = 1 - c0;
	s1 = 1 - s0;
	rotation = (t_mat4)
	{{
			c0 + X * X * c1, X * Y * c1 - Z * s0,
			X * Z * c1 + Y * s0, 0,
			Y * X * c1 + Z * s0, c0 + Y * Y * c1,
			Y * Z * c1 - X * s0, 0,
			Z * X * c1 - Y * s0, Z * Y * c1 + X * s0,
			c0 + Z * Z * c1, 0, 0, 0, 0, 1
	}};
	return (mat4_transpose(rotation));
}
