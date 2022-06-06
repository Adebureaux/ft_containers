NAME		= containers

SRCS		= main.cpp

OBJS_DIR	= objs/

OBJS		= ${OBJS_DIR}${SRCS:.cpp=.o}

DEPS		= ${OBJS:.o=.d}

HDIR		= vector.hpp

RM			= rm -rf

CFLAGS		= -std=c++98 -Wall -Wextra -Werror -g

COMPILER	= c++

${NAME}: ${OBJS}
	${COMPILER} ${CFLAGS} ${OBJS} -o ${NAME}

${OBJS_DIR}%.o: %.cpp
	@mkdir -p ${OBJS_DIR}
	${COMPILER} ${CFLAGS} -MMD -MP -c $< -o $@

-include ${DEPS}

all: ${NAME}

clean:
	${RM} ${OBJS_DIR}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
