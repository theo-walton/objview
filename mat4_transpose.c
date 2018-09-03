/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4_transpose.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:07:20 by twalton           #+#    #+#             */
/*   Updated: 2018/04/14 14:42:45 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_view.h"

t_mat4	mat4_transpose(t_mat4 m)
{
	t_mat4	out;
	int		i;
	int		x;
	int		y;

	i = 0;
	while (i < 16)
	{
		x = i % 4;
		y = i / 4;
		out.array[x + y * 4] = m.array[y + x * 4];
		i++;
	}
	return (out);
}