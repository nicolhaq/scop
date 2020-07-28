/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 23:38:45 by grolash           #+#    #+#             */
/*   Updated: 2020/07/28 16:39:00 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <scop.h>

/*
**todo: renove when parser is ready
*/
static const GLfloat	g_vertices[24] =
{	
	-0.5f,	0.5f,	-0.5f,
	-0.5f,	-0.5f,	-0.5f,
	-0.5f,	0.5f,	0.5f,
	-0.5f,	-0.5f,	0.5f,

	0.5f,	0.5f,	0.5f,
	0.5f,	-0.5f,	0.5f,
	0.5f,	0.5f,	-0.5f,
	0.5f,	-0.5f,	-0.5f,
};
static const GLuint		g_indices[36] = {
	0, 1, 2, 2, 1, 3,
	4, 5, 6, 6, 5, 7,
	3, 1, 5, 5, 1, 7,
	0, 2, 6, 6, 2, 4,
	6, 7, 0, 0, 7, 1,
	2, 3, 4, 4, 3, 5
};

static void	populate_vao(GLuint *vao)
{
	GLuint	vbo;
	GLuint	ebo;

	glGenVertexArrays(1, vao);
	glGenBuffers(1, &vbo);
	glGenBuffers(1, &ebo);
	glBindVertexArray(*vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertices),\
			g_vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(g_indices),\
			g_indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float),\
			(void *)0);
	glEnableVertexAttribArray(0);
}

static void	draw(GLFWwindow **window, GLuint *shader_program)
{
	GLuint	vao;
	t_mat4	trans;
	GLuint	transform;

	populate_vao(&vao);
	glEnable(GL_DEPTH_TEST);
	while (!glfwWindowShouldClose(*window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(*shader_program);
		mat4_init(&trans, 1.0f);
		mat4_rotat(&trans, (GLfloat)glfwGetTime(), y);
		transform = glGetUniformLocation(*shader_program, "transform");
		glUniformMatrix4fv(transform,1,GL_FALSE,trans.ptr);
		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, sizeof(g_indices) / sizeof(GLuint), \
				GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(*window);
		glfwPollEvents();
	}
}

int			main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	GLFWwindow	*window;
	GLuint		shader_program;
	int			error;

	error = 0;
	window = NULL;
	/*parser(argc, argv);*/
	if (!(error = init(&window)))
	{
		if (!(error = shader_link(&shader_program)))
			draw(&window, &shader_program);
	}
	glfwTerminate();
	return (error);
}
