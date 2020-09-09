/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scop.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grolash <nhaquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/13 23:35:58 by grolash           #+#    #+#             */
/*   Updated: 2020/09/09 15:24:26 by grolash          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCOP_H
# define SCOP_H
# include <glad/glad.h>
# include <GLFW/glfw3.h>
# include <math.h>
# include <stdlib.h>
# include <libft/libft.h>
# include <string.h>
# include <errno.h>

# ifdef MACOS
#  define OSX 1
# else
#  define OSX 0
# endif

typedef struct	s_obj
{
	GLfloat	*vert;
	size_t	vert_size;
	GLuint	*ind;
	size_t	ind_size;
	GLfloat	min[3];
	GLfloat	max[3];
	GLfloat	rescale[4];
	GLfloat	center[4];
}				t_obj;

typedef struct	s_mat4
{
	GLfloat	ptr[16];
	GLfloat	*mat[4];
	GLfloat	*x;
	GLfloat	*y;
	GLfloat	*z;
	GLfloat	*w;
}				t_mat4;

enum			e_axis
{
	x = 0,
	y = 1,
	z = 2,
	w = 3
};

void			error_callback(int error, const char *description);
void			key_callback(GLFWwindow *window, int key, int scancode,\
				int action, int mods);
void			framebuffer_size_callback(GLFWwindow *window, int width,\
				int height);
int				init(GLFWwindow **window);
int				shader_link(GLuint *shader_program);
const char		*load_source(char *filename);
void			mat4_init(t_mat4 *mat4, GLfloat source);
void			mat_mult(t_mat4 *mat4, t_mat4 *mult);
void			print_mat4(t_mat4 *mat);
void			mat4_trans(t_mat4 *mat4, GLfloat *vec);
void			mat4_rotat(t_mat4 *mat4, GLfloat rad, enum e_axis axis);
void			mat4_scale(t_mat4 *mat4, GLfloat *vec);
int				parser(int argc, char **argv, t_obj *obj);
size_t			get_data_size(char **stab, const char delim);
int				get_data(char **stab, t_obj *obj);
int				normalize(t_obj *obj);
#endif
