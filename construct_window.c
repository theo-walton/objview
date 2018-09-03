/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:30:54 by twalton           #+#    #+#             */
/*   Updated: 2018/04/14 14:46:19 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_view.h"

#define NORM GLFWwindow *w, int key, int s, int action, int

static void	key_callback(NORM f)
{
	(void)w;
	(void)s;
	(void)f;
	if (action == GLFW_PRESS)
	{
		if (key == GLFW_KEY_ESCAPE)
			glfwSetWindowShouldClose(g_window, 1);
		g_window_keys[key] = 1;
		g_window_pressed_keys[key] = 1;
	}
	else if (action == GLFW_RELEASE)
		g_window_keys[key] = 0;
}

static void	window_hints(void)
{
	glfwDefaultWindowHints();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_DEPTH_BITS, 32);
	glfwWindowHint(GLFW_SAMPLES, 4);
}

void		construct_window(void)
{
	GLuint vertex_array;

	glfwInit();
	window_hints();
	g_window = glfwCreateWindow(1000, 1000, "obj", NULL, NULL);
	glfwSetKeyCallback(g_window, key_callback);
	glfwMakeContextCurrent(g_window);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glGenVertexArrays(1, &vertex_array);
	glBindVertexArray(vertex_array);
}
