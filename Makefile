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
	${RM} adeburea_tester/ft_vector.out adeburea_tester/std_vector.out adeburea_tester/ft_vector_err.log adeburea_tester/std_vector_err.log
	${RM} adeburea_tester/ft_map.out adeburea_tester/std_map.out adeburea_tester/ft_map_err.log adeburea_tester/std_map_err.log
	${RM} adeburea_tester/ft_utility.out adeburea_tester/std_utility.out adeburea_tester/ft_utility_err.log adeburea_tester/std_utility_err.log
	${RM} ${OBJS_DIR}

fclean: clean
	${RM} adeburea_tester/ft_vector adeburea_tester/std_vector
	${RM} adeburea_tester/ft_map adeburea_tester/std_map
	${RM} adeburea_tester/ft_utility adeburea_tester/std_utility
	${RM} ${NAME}

re: fclean all

vector:
	@echo "Compiling adeburea_tester with ft::vector"
	${COMPILER} ${CFLAGS} adeburea_tester/vector.cpp -o adeburea_tester/ft_vector
	@echo "Compiling test with std::vector"
	${COMPILER} -DLOC=std ${CFLAGS} adeburea_tester/vector.cpp -o adeburea_tester/std_vector
	@bash adeburea_tester/vector_test.sh

map:
	@echo "Compiling test with ft::map"
	${COMPILER} ${CFLAGS} adeburea_tester/map.cpp -o adeburea_tester/ft_map
	@echo "Compiling test with std::map"
	${COMPILER} -DLOC=std ${CFLAGS} adeburea_tester/map.cpp -o adeburea_tester/std_map
	@bash adeburea_tester/map_test.sh

utility:
	@echo "Compiling test with ft::utility"
	${COMPILER} ${CFLAGS} adeburea_tester/utility.cpp -o adeburea_tester/utility
	@echo "Compiling test with std::utility"
	${COMPILER} -DLOC=std ${CFLAGS} adeburea_tester/utility.cpp -o adeburea_tester/utility
	@bash adeburea_tester/utility_test.sh

test: vector map utility

.PHONY: all clean fclean re vector map utilty test
