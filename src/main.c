/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 23:38:45 by grolash           #+#    #+#             */
/*   Updated: 2020/06/23 13:47:49 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

/*todo: renove when parser is ready*/
static const GLfloat	vertices[24] =
{
	0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
	0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f,
	-0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f
};
static const GLuint	indices[6] = {0, 1, 3, 1, 2, 3};

static void populate_VAO(GLuint *VAO)
{
	GLuint			VBO;
	GLuint			EBO;

	glGenVertexArrays(1, VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(*VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices,\
			GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,\
			GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),\
			(void *)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),\
			(void *)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

static void	draw(GLFWwindow **window, GLuint *shader_program)
{
	GLuint			VAO;

        populate_VAO(&VAO);
	while(!glfwWindowShouldClose(*window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(*shader_program);
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(*window);
		glfwPollEvents();
	}
}

int		main(int argc,char **argv)
{
	GLFWwindow		*window;
	GLuint			shader_program;
	int			error;

	(void)argc;
	(void)argv;
	error = 0;
	window = NULL;
	if(!(error = init(&window)))
	{
		if(!(error = shader_link(&shader_program)))
			draw(&window, &shader_program);
	}
	glfwTerminate();
	return (error);
}
