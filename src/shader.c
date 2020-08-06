/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 16:29:36 by grolash           #+#    #+#             */
/*   Updated: 2020/08/04 11:29:26 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <scop.h>

static int	program_link_error(GLuint shader_program)
{
	int		success;
	char	info_log[512];

	glGetProgramiv(shader_program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(shader_program, 512, NULL, info_log);
		ft_putstr_fd(2, "ERROR::SHADER::PROGRAM::LINKING_FAILED:\n");
		ft_putstr_fd(2, info_log);
		ft_putchar_fd(2, '\n');
		return (-1);
	}
	return (0);
}

static int	shader_compile_error(GLuint shader)
{
	int		success;
	char	info_log[512];

	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(shader, 512, NULL, info_log);
		ft_putstr_fd(2, "ERROR::SHADER::COMPILATION_FAILED:\n");
		ft_putstr_fd(2, info_log);
		ft_putchar_fd(2, '\n');
		return (-1);
	}
	return (0);
}

static int	shader_compil(GLuint *vertex_shader)
{
	const char *vertex_shader_source;

	vertex_shader_source = load_source("src/shader/vertex_shader.vert");
	*vertex_shader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(*vertex_shader, 1, &vertex_shader_source, NULL);
	glCompileShader(*vertex_shader);
	free((void*)vertex_shader_source);
	if (shader_compile_error(*vertex_shader))
		return (-21);
	return (0);
}

static int	frag_shader_compil(GLuint *fragment_shader)
{
	const char *fragment_shader_source;

	fragment_shader_source = load_source("src/shader/fragment_shader.frag");
	*fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(*fragment_shader, 1, &fragment_shader_source, NULL);
	glCompileShader(*fragment_shader);
	free((void*)fragment_shader_source);
	if (shader_compile_error(*fragment_shader))
		return (-22);
	return (0);
}

int			shader_link(GLuint *shader_program)
{
	int		error;
	GLuint	vertex_shader;
	GLuint	fragment_shader;

	error = 0;
	if ((error = shader_compil(&vertex_shader)) ||\
		(error = frag_shader_compil(&fragment_shader)))
		return (error);
	*shader_program = glCreateProgram();
	glAttachShader(*shader_program, vertex_shader);
	glAttachShader(*shader_program, fragment_shader);
	glLinkProgram(*shader_program);
	if (program_link_error(*shader_program))
		return (-23);
	glDeleteShader(vertex_shader);
	glDeleteShader(fragment_shader);
	return (0);
}
