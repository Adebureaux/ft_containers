NAME        = program

SRCS        = main.cpp

OBJS        = ${SRCS:.cpp=.o}

RM          = rm -f

CFLAGS      = -std=c++98 #-Wall -Wextra -Werror 

COMPILER    = c++

${NAME}: ${OBJS}
	${COMPILER} ${CFLAGS} ${OBJS} -o ${NAME}

%.o: %.cpp
	$(COMPILER) $(CFLAGS) -c $< -o $@

all: ${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
