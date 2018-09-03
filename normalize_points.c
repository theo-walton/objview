/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_points.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 19:25:29 by twalton           #+#    #+#             */
/*   Updated: 2018/04/14 14:48:30 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_view.h"

static float	max_dist_tracker(float x, float y, float z, int reset)
{
	static float	max_dist = 0;
	float			current_dist;

	if (reset)
	{
		max_dist = 0;
		return (0);
	}
	current_dist = sqrt(x * x + y * y + z * z);
	if (max_dist < current_dist)
		max_dist = current_dist;
	return (max_dist);
}

static void		translate_points(float *v, int size, float xyz[])
{
	int i;

	i = 0;
	while (i < size * 3)
	{
		v[i] -= xyz[0];
		v[i + 1] -= xyz[1];
		v[i + 2] -= xyz[2];
		i += 3;
	}
}

static void		center_points_origin(float *v, int size)
{
	float	xyz[3];
	int		i;

	i = 0;
	xyz[0] = 0;
	xyz[1] = 0;
	xyz[2] = 0;
	while (i < size * 3)
	{
		xyz[0] += v[i];
		xyz[1] += v[i + 1];
		xyz[2] += v[i + 2];
		i += 3;
	}
	xyz[0] /= size;
	xyz[1] /= size;
	xyz[2] /= size;
	translate_points(v, size, xyz);
}

void			normalize_points(float *v, int size)
{
	float	scale;
	int		i;

	center_points_origin(v, size);
	max_dist_tracker(0, 0, 0, 1);
	i = 0;
	while (i < size * 3)
	{
		max_dist_tracker(v[i], v[i + 1], v[i + 2], 0);
		i += 3;
	}
	scale = 1 / max_dist_tracker(0, 0, 0, 0);
	i = 0;
	while (i < size * 3)
		v[i++] *= scale;
}
