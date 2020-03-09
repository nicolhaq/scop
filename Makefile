############################## BIN #############################################

NAME = scop

SRC =	main.c\

CC = clang

SRCDIR = srcs

OBJDIR = objs

OBJ = $(addprefix ${OBJDIR}/, $(SRC:.c=.o))

CFLAGS += -Wall -Wextra -Werror\

LDFLAGS = -Iincludes/
	# -fsanitize=address,undefined
LIB = -lglwf
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

all: ${NAME}

${NAME}: ${OBJ}
	@echo ${B}Compiling [${NAME}]...${X}
	@${CC} ${LDFLAGS} ${LIB} -o $@ ${OBJ}
	@echo ${G}Success"   "[${NAME}]${X}

${OBJDIR}/%.o: ${SRCDIR}/%.c
	@echo ${Y}Compiling [$@]...${X}
	@/bin/mkdir -p ${OBJDIR} ${OBJDIR}/virus
	@${CC} ${CFLAGS} ${LDFLAGS} -c -o $@ $<
	@printf ${UP}${CUT}

############################## GENERAL #########################################

clean:
	@echo ${R}Cleaning"  "[objs]...${X}
	@/bin/rm -Rf ${OBJDIR}

fclean: clean
	@echo ${R}Cleaning"  "[${NAME}]...${X}
	@/bin/rm -f ${NAME}
	@/bin/rm -Rf ${NAME}.dSYM

re: fclean all

############################# DEPENDENCY ######################################

build_dep:
	@echo ${B}Building dependency
	git submodule init
	git submodule update
	cmake -B "includes/glfw" -Hincludes/glfw/.
	make -C includes/glfw/.
	
.PHONY: all clean fclean re
