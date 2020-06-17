/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 23:38:45 by grolash           #+#    #+#             */
/*   Updated: 2020/06/17 13:10:04 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

int	init_window(GLFWwindow **window)
{
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	*window = glfwCreateWindow(800, 600,"scop", NULL, NULL);
	if(*window == NULL)
		return (-1);
	glfwMakeContextCurrent(*window);
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		ft_putstr_fd(2, "Error: Failed to initialize GLAD\n");
		return(-1);
	}
	return (0);
}

int		init_glfw()
{
	glfwSetErrorCallback(error_callback);
	if (!glfwInit())
		return (-1);
	return (0);
}

int		init(GLFWwindow **window)
{
	GLuint vertex_array_ID;

	if(init_glfw())
		return (-1);
	if(init_window(&*window))
		return (-1);
	glGenVertexArrays(1, &vertex_array_ID);
	glBindVertexArray(vertex_array_ID);
	glfwSetKeyCallback(*window, key_callback);
	glfwSetInputMode(*window, GLFW_STICKY_KEYS, GLFW_TRUE);
	return (0);
}

int		draw(GLFWwindow **window)
{
	/*temporary renove when parser is ready*/
	static const GLfloat gl_vertex_buffer_data[] =
	{
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
	};
	GLuint vertex_buffer;

	ft_putstr("test\n");
	glGenBuffers(GL_ARRAY_BUFFER, &vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(gl_vertex_buffer_data), \
			gl_vertex_buffer_data, GL_STATIC_DRAW);
	while(!glfwWindowShouldClose(*window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GLFW_FALSE, 0, (void*)0);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glDisableVertexAttribArray(0);
		glfwSwapBuffers(*window);
		glfwPollEvents();
	}
	return (0);
}

int		main(int argc,char **argv)
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
