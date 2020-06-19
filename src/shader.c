/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 16:29:36 by grolash           #+#    #+#             */
/*   Updated: 2020/06/19 14:21:22 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

static int	program_link_error(GLuint shader_program)
{
	int		success;
	char		infoLog[512];

	glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shader_program, 512, NULL, infoLog);
		ft_putstr_fd(2, "ERROR::SHADER::PROGRAM::LINKING_FAILED:\n");
		ft_putstr_fd(2, infoLog);
		ft_putchar_fd(2, '\n');
		return (-1);	
	}
	return (0);
}

static int	shader_compile_error(GLuint shader)
{
	int		success;
	char		infoLog[512];

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		ft_putstr_fd(2, "ERROR::SHADER::COMPILATION_PAILED:\n");
		ft_putstr_fd(2, infoLog);
		ft_putchar_fd(2, '\n');
		return (-1);	
	}
	return (0);
}

static int	shader_compil(GLuint *vertex_shader)
{
	const char	*vertex_shader_source =
		"#version 410 core\n"
		"layout (location = 0) in vec3 aPos;\n"
		"void main()\n"
		"{\n"
		"	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
		"}\0";

	*vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(*vertex_shader, 1, &vertex_shader_source, NULL);
	glCompileShader(*vertex_shader);
	if(shader_compile_error(*vertex_shader))
		return (-21);
	return (0);
}

static int	frag_shader_compil(GLuint *fragment_shader)
{
	const char *fragment_shader_source =
		"#version 410 core\n"
		"out vec4 frag_color;\n"
		"void main()\n"
		"{\n"
		"	frag_color = vec4(1.0f, 0.4f, 0.2f, 1.0f);\n"
		"}\0";

	*fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(*fragment_shader, 1, &fragment_shader_source, NULL);
	glCompileShader(*fragment_shader);
	if(shader_compile_error(*fragment_shader))
		return (-22);
	return (0);
}

int		shader_link(GLuint *shader_program)
{
	int	error;
	GLuint	vertex_shader;
	GLuint	fragment_shader;

	error = 0;
	if((error = shader_compil(&vertex_shader)) ||\
		(error = frag_shader_compil(&fragment_shader)))
		return (error);
	*shader_program = glCreateProgram();
	glAttachShader(*shader_program, vertex_shader);
	glAttachShader(*shader_program, fragment_shader);
	glLinkProgram(*shader_program);
	if(program_link_error(*shader_program))
		return (-23);
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
	return (0);
}
