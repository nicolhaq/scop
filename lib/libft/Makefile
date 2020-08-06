# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhaquet <nhaquet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 16:52:52 by nhaquet           #+#    #+#              #
#    Updated: 2020/08/03 14:32:41 by grolash          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_memset.c ft_putchar.c ft_putnbr.c ft_strlen.c ft_putstr.c ft_bzero.c \
	ft_strcpy.c ft_strncpy.c ft_strdup.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	ft_strrchr.c ft_strstr.c ft_strcmp.c ft_strncmp.c ft_strnstr.c ft_atoi.c \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_tolower.c ft_toupper.c ft_memalloc.c ft_memdel.c ft_strjoin.c \
	ft_strnew.c ft_strsub.c ft_strsplit.c ft_sqrt.c ft_realloc.c ft_strdup2.c \
	get_next_line.c ft_intlen.c ft_free_tab.c ft_itoa.c ft_itoa_base.c\
	ft_putstr_fd.c ft_putnbr_fd.c ft_putchar_fd.c
CC = clang

AS = nasm

SRCDIR = srcs

OBJDIR = objs

OBJC = $(addprefix ${OBJDIR}/, $(SRC:.c=.o))

OBJ = $(OBJC:.s=.o)

CFLAGS = -Wall -Wextra -Werror #-g -MMD -fsanitize=address,undefined

ASFLAGS = -f macho64 -g

LDFLAGS = -I.

all: $(NAME)

$(NAME): ${OBJ}
	@echo ${B}Compiling [${NAME}]...${X}
	@ar rcs ${NAME} ${OBJ}
	@ranlib libft.a
	@echo "libft ok"

${OBJDIR}/%.o: ${SRCDIR}/%.c
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR}
	@${CC} ${CFLAGS} ${LDFLAGS} -c -o $@ $<

clean:
	@/bin/rm -rf $(OBJDIR)
	@echo "delete obj"

fclean: clean
	@/bin/rm -f ${NAME}
	@echo "delete libft.a"

re: fclean all

.PHONY: all clean fclean re
