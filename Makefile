############################## BIN #############################################

NAME = scop

SRC =	init.c\
	shader.c\
	callback.c\
	main.c\
	glad.c

CC = clang

UNAME := $(shell uname -s)

SRCDIR = src

OBJDIR = obj

LIBDIR = lib

OBJ = $(addprefix ${OBJDIR}/, $(SRC:.c=.o))

CFLAGS = -Wall -Wextra -Werror

LDFLAGS = -Iinclude -Ilib 

ifeq ($UNAME,Darwin)
	CFLAGS += -DMACOS
	LDFLAGS += -I/Users/nhaquet/homebrew/Cellar/glfw/3.3.2/include
	LIB = -L/Users/nhaquet/homebrew/Cellar/glfw/3.3.2/lib
endif

LIB += -lglfw -lm -ldl -Llib/libft -lft\
	#-fsanitize=address,undefined
############################## COLORS ##########################################

BY = "\033[33;1m"
BR = "\033[31;1m"
BG = "\033[32;1m"
BB = "\033[34;1m"
BM = "\033[35;1m"
BC = "\033[36;1m"
BW = "\033[37;1m"
Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
M = "\033[35m"
C = "\033[36m"
W = "\033[0m""\033[32;1m"
WR = "\033[0m""\033[31;5m"
WY = "\033[0m""\033[33;5m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

############################## RULES ###########################################

all: build_dep ${NAME}

${NAME}: ${OBJ}
	@echo ${B}Compiling [${NAME}]...${X}
	@${CC} ${LDFLAGS} -o $@ ${OBJ} ${LIB}
	@echo ${G}Success"   "[${NAME}]${X}

${OBJDIR}/%.o: ${SRCDIR}/%.c
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR} ${OBJDIR}
	@${CC} ${CFLAGS} ${LDFLAGS} -c -o $@ $<
	@printf ${UP}${CUT}

############################## GENERAL #########################################
libftfclean:
	make -C lib/libft fclean

clean:
	@echo ${R}Cleaning"  "[objs]...${X}
	@/bin/rm -Rf ${OBJDIR}

fclean: clean_dep clean
	@echo ${R}Cleaning"  "[${NAME}]...${X}
	@/bin/rm -f ${NAME}
	@/bin/rm -Rf ${NAME}.dSYM

re: fclean all

############################# DEPENDENCY ######################################

build_dep:
	@echo ${B}Building dependency
	make -C lib/libft

clean_dep:
	@echo ${B}cleaning dependency
	make -C lib/libft fclean

.PHONY: all clean fclean re build_dep clean_dep
