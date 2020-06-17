/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 23:38:45 by grolash           #+#    #+#             */
/*   Updated: 2020/06/17 15:48:45 by grolash          ###   ########.fr       */
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
	/*uncoment on macos*/
	/*glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);*/
	*window = glfwCreateWindow(800, 600,"scop", NULL, NULL);
	if(*window == NULL)
		return (-1);
	glfwMakeContextCurrent(*window);
	if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		ft_putstr_fd(2, "Error: Failed to initialize GLAD\n");
		return(-1);
	}
	glViewport(0, 0, 800, 600);
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
	glfwSetFramebufferSizeCallback(*window, framebuffer_size_callback);
	glfwSetInputMode(*window, GLFW_STICKY_KEYS, GLFW_TRUE);
	return (0);
}

int		draw(GLFWwindow **window)
{
	/*temporary renove when parser is ready*/
	static const GLfloat vertices[9] =
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
		glEnableVertexAttribArray(0);
		/*glBindBuffer(GL_ARRAY_BUFFER, *vertices);*/
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
