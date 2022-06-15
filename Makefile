NAME		= containers

SRCS		= main.cpp

OBJS_DIR	= objs/

OBJS		= ${OBJS_DIR}${SRCS:.cpp=.o}

DEPS		= ${OBJS:.o=.d}

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
	${RM} test/ft_vector.out test/std_vector.out test/ft_vector_err.log test/std_vector_err.log
	${RM} ${OBJS_DIR}

fclean: clean
	${RM} test/ft_vector test/std_vector
	${RM} ${NAME}

re: fclean all

vector:
	@echo "Compiling test with ft::vector"
	${COMPILER} ${CFLAGS} test/vector.cpp -o test/ft_vector
	@echo "Compiling test with std::vector"
	${COMPILER} -DLOC=std ${CFLAGS} test/vector.cpp -o test/std_vector
	@bash test/vector_test.sh

test: vector

.PHONY: all clean fclean re vector test
