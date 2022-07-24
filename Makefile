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
	${RM} test/ft_map.out test/std_map.out test/ft_map_err.log test/std_map_err.log
	${RM} test/ft_tools.out test/std_tools.out test/ft_tools_err.log test/std_tools_err.log
	${RM} ${OBJS_DIR}

fclean: clean
	${RM} test/ft_vector test/std_vector
	${RM} test/ft_map test/std_map
	${RM} test/ft_tools test/std_tools
	${RM} ${NAME}

re: fclean all

vector:
	@echo "Compiling test with ft::vector"
	${COMPILER} ${CFLAGS} test/vector.cpp -o test/ft_vector
	@echo "Compiling test with std::vector"
	${COMPILER} -DLOC=std ${CFLAGS} test/vector.cpp -o test/std_vector
	@bash test/vector_test.sh

map:
	@echo "Compiling test with ft::map"
	${COMPILER} ${CFLAGS} test/map.cpp -o test/ft_map
	@echo "Compiling test with std::map"
	${COMPILER} -DLOC=std ${CFLAGS} test/map.cpp -o test/std_map
	@bash test/map_test.sh

tools:
	@echo "Compiling test with ft::tools"
	${COMPILER} ${CFLAGS} test/tools.cpp -o test/ft_tools
	@echo "Compiling test with std::tools"
	${COMPILER} -DLOC=std ${CFLAGS} test/tools.cpp -o test/std_tools
	@bash test/tools_test.sh

test: vector tools

.PHONY: all clean fclean re vector test
