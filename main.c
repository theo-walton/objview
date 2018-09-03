/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 11:16:39 by twalton           #+#    #+#             */
/*   Updated: 2018/04/14 14:39:48 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAIN_C

#include "obj_view.h"

static void	show_usage(void)
{
	printf("enter a single .obj file to view it\n");
	exit(1);
}

static void	init_globals(void)
{
	memset(g_window_keys, 0, 512 * sizeof(int));
	memset(g_window_pressed_keys, 0, 512 * sizeof(int));
	g_texture_data = malloc(sizeof(char) * 2000 * 2000 * 3);
	g_transform = IDENTITY_MAT4;
	g_vertex_amount = 0;
}

static void	clean_globals(void)
{
	free(g_texture_data);
	free(g_vertex_array);
}

int			main(int ac, char **av)
{
	if (ac != 2)
		show_usage();
	init_globals();
	parse_obj_file(av[1]);
	normalize_points(g_vertex_array, g_vertex_amount);
	construct_window();
	create_shading_program();
	glUseProgram(g_program_id);
	set_uniform_locations();
	load_object();
	load_textures();
	set_projection();
	glClearColor(0.20, 0.25, 0.29, 1);
	while (!glfwWindowShouldClose(g_window))
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		manage_input();
		draw_object();
		glfwSwapBuffers(g_window);
		glfwPollEvents();
	}
	clean_globals();
	glfwDestroyWindow(g_window);
	glfwTerminate();
}
