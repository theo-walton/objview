/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_view.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twalton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:15:39 by twalton           #+#    #+#             */
/*   Updated: 2018/04/14 16:32:38 by twalton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_VIEW_H
# define OBJ_VIEW_H

# define GLFW_INCLUDE_GLCOREARB

# include <GLFW/glfw3.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include <ctype.h>
# include <math.h>

# define TEXTURES "other.bmp", "thing.bmp", "checkerboard.bmp", "pony.bmp"
# define TOTAL_TEXTURES 4

typedef struct		s_mat4
{
	float array[16];
}					t_mat4;

# define IDEN 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1
# define IDENTITY_MAT4 (t_mat4){{IDEN}}

# ifdef MAIN_C

float				*g_parsed_vertices;
int					*g_parsed_faces;

int					g_vertex_amount;
float				*g_vertex_array;

GLFWwindow			*g_window;
int					g_window_keys[512];
int					g_window_pressed_keys[512];

GLuint				g_program_id;
GLuint				g_vertex_shader_id;
GLuint				g_fragment_shader_id;

GLuint				g_projection_location;
GLuint				g_transform_location;
GLuint				g_texture_location;

GLuint				g_vertex_array_id;

GLuint				g_texture_id[TOTAL_TEXTURES];
int					g_texture_width;
int					g_texture_height;
char				*g_texture_data;
int					g_texture_index;
const char			*g_texture_paths[TOTAL_TEXTURES] = {TEXTURES};

t_mat4				g_transform;

# else

extern float		*g_parsed_vertices;
extern int			*g_parsed_faces;

extern int			g_vertex_amount;
extern float		*g_vertex_array;

extern GLFWwindow	*g_window;
extern int			g_window_keys[512];
extern int			g_window_pressed_keys[512];

extern GLuint		g_program_id;
extern GLuint		g_vertex_shader_id;
extern GLuint		g_fragment_shader_id;

extern GLuint		g_projection_location;
extern GLuint		g_transform_location;
extern GLuint		g_texture_location;

extern GLuint		g_vertex_array_id;

extern GLuint		g_texture_id[TOTAL_TEXTURES];
extern int			g_texture_width;
extern int			g_texture_height;
extern char			*g_texture_data;
extern int			g_texture_index;
extern const char	*g_texture_paths[TOTAL_TEXTURES];

extern t_mat4		g_transform;

# endif

void				create_shading_program(void);
void				compile_fragment_shader(void);
void				compile_vertex_shader(void);
void				check_compilation(GLuint shader);
char				*ft_dirty_read(int fd, int size);
void				construct_window(void);
void				draw_object(void);
void				load_object(void);
void				load_textures(void);
void				manage_input(void);
void				parse_obj_file(char *filepath);
void				parse_texture(int index);
void				set_projection(void);
void				set_uniform_locations(void);
t_mat4				mat4_mult(t_mat4 a, t_mat4 b);
t_mat4				mat4_rotation(float x, float y, float z, float degrees);
t_mat4				mat4_transpose(t_mat4 m);
void				normalize_points(float *v, int size);
void				parse_file_lines(char *str, int *total_faces);
void				fill_triangle_array(int total_faces);
t_mat4				mat4_translate(float x, float y, float z);

#endif
