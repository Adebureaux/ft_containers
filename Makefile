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
	${RM} test/ft_utility.out test/std_utility.out test/ft_utility_err.log test/std_utility_err.log
	${RM} ${OBJS_DIR}

fclean: clean
	${RM} test/ft_vector test/std_vector
	${RM} test/ft_map test/std_map
	${RM} test/ft_utility test/std_utility
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

utility:
	@echo "Compiling test with ft::utility"
	${COMPILER} ${CFLAGS} test/utility.cpp -o test/utility
	@echo "Compiling test with std::utility"
	${COMPILER} -DLOC=std ${CFLAGS} test/utility.cpp -o test/utility
	@bash test/utility_test.sh

test: vector map utility

.PHONY: all clean fclean re vector map utilty test
