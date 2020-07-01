/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 23:38:45 by grolash           #+#    #+#             */
/*   Updated: 2020/07/01 13:45:11 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <scop.h>

/*
**todo: renove when parser is ready
*/
static const GLfloat	g_vertices[24] =
{
	0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
	0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
	-0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f
};
static const GLuint		g_indices[6] = {0, 1, 3, 1, 2, 3};

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
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),\
			(void *)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),\
			(void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

static void	draw(GLFWwindow **window, GLuint *shader_program)
{
	GLuint	vao;

	populate_vao(&vao);
	while (!glfwWindowShouldClose(*window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(*shader_program);
		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
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
	if (!(error = init(&window)))
	{
		if (!(error = shader_link(&shader_program)))
			draw(&window, &shader_program);
	}
	glfwTerminate();
	return (error);
}
