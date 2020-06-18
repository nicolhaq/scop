/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 23:38:45 by grolash           #+#    #+#             */
/*   Updated: 2020/06/18 14:13:24 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>


int	draw(GLFWwindow **window)
{
	/*temporary renove when parser is ready*/
	static const	GLfloat vertices[9] =
	{
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f, 0.5f, 0.0f,
	};
	GLuint VBO;
	
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	while(!glfwWindowShouldClose(*window))
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(*window);
		glfwPollEvents();
	}
	return (0);
}

int	main(int argc,char **argv)
{
	GLFWwindow	*window;

	(void)argc;
	(void)argv;
	window = NULL;
	if(!init(&window))
		draw(&window);
	glfwTerminate();
	return (0);
}
