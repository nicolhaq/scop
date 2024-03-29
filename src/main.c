/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 23:38:45 by grolash           #+#    #+#             */
/*   Updated: 2020/09/25 14:47:09 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <scop.h>
#include <stdio.h>

static void	populate_vao(GLuint *vao, t_obj *obj)
{
	GLuint	vbo;
	GLuint	ebo;

	glGenVertexArrays(1, vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);
	glBindVertexArray(*vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * obj->vert_size,\
			obj->vert, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * obj->ind_size,\
			obj->ind, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),\
			(void *)0);
	glEnableVertexAttribArray(0);
}

static void	mat4_object(t_mat4 *mat, t_obj *obj)
{
	GLfloat	vec[3];

	vec_init(vec, 0.0f, 1.0f, 0.0f);
	mat4_init(mat, 1.0f);
	mat4_trans(mat, obj->center);
	mat4_rotat(mat, (GLfloat)glfwGetTime(), vec);
	mat4_trans(mat, obj->center);
	mat4_scale(mat, obj->rescale);
}

static void	mat4_manip(t_mat4 *mat ,t_obj *obj, t_cam *cam)
{

	mat4_object(mat, obj);
	mat4_view(mat, cam);
	mat4_perspective(mat, 600.0f, 600.0f, 45.0f);
}

static void	draw(GLFWwindow **window, GLuint *shader_program, t_obj *obj)
{
	GLuint	vao;
	t_mat4	mat;
	t_cam	cam;
	GLuint	transform;
	int		size;

	populate_vao(&vao, obj);
	cam_init(&cam);
	glGetBufferParameteriv(GL_ELEMENT_ARRAY_BUFFER, GL_BUFFER_SIZE, &size);
	glEnable(GL_DEPTH_TEST);
	while (!glfwWindowShouldClose(*window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(*shader_program);
		cam_key(window, &cam);
		mat4_manip(&mat, obj, &cam);
		transform = glGetUniformLocation(*shader_program, "transform");
		glUniformMatrix4fv(transform, 1, GL_FALSE, mat.ptr);
		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, size / sizeof(GLuint), GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(*window);
		glfwPollEvents();
	}
}

int			main(int argc, char **argv)
{
	GLFWwindow	*window;
	GLuint		shader_program;
	int			error;
	t_obj		obj;

	error = 0;
	window = NULL;
	error = parser(argc, argv, &obj);
	if (error)
		return (error);
	if (!(error = init(&window)))
	{
		if (!(error = shader_link(&shader_program)))
			draw(&window, &shader_program, &obj);
	}
	free(obj.vert);
	free(obj.ind);
	glfwTerminate();
	return (error);
}
