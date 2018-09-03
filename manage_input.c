/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:58:50 by twalton           #+#    #+#             */
/*   Updated: 2018/04/10 11:58:50 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_view.h"

static void	manage_rotations(void)
{
	if (g_window_keys['W'])
		g_transform = mat4_mult(g_transform, mat4_rotation(1, 0, 0, -1));
	if (g_window_keys['S'])
		g_transform = mat4_mult(g_transform, mat4_rotation(1, 0, 0, 1));
	if (g_window_keys['D'])
		g_transform = mat4_mult(g_transform, mat4_rotation(0, 1, 0, 1));
	if (g_window_keys['A'])
		g_transform = mat4_mult(g_transform, mat4_rotation(0, 1, 0, -1));
	if (g_window_keys['Q'])
		g_transform = mat4_mult(g_transform, mat4_rotation(0, 0, 1, 1));
	if (g_window_keys['E'])
		g_transform = mat4_mult(g_transform, mat4_rotation(0, 0, 1, -1));
}

void		manage_input(void)
{
	manage_rotations();
	if (g_window_pressed_keys['T'])
	{
		g_texture_index = (g_texture_index + 1) % TOTAL_TEXTURES;
		g_window_pressed_keys['T'] = 0;
	}
	if (g_window_keys[GLFW_KEY_UP])
		g_transform = mat4_mult(mat4_translate(0, 0.05, 0), g_transform);
	if (g_window_keys[GLFW_KEY_DOWN])
		g_transform = mat4_mult(mat4_translate(0, -0.05, 0), g_transform);
	if (g_window_keys[GLFW_KEY_RIGHT])
		g_transform = mat4_mult(mat4_translate(0.05, 0, 0), g_transform);
	if (g_window_keys[GLFW_KEY_LEFT])
		g_transform = mat4_mult(mat4_translate(-0.05, 0, 0), g_transform);
	if (g_window_keys['='])
		g_transform = mat4_mult(mat4_translate(0, 0, 0.05), g_transform);
	if (g_window_keys['-'])
		g_transform = mat4_mult(mat4_translate(0, 0, -0.05), g_transform);
}
