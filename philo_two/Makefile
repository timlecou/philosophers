SRCS = srcs/philo_two.c srcs/utils/utils.c srcs/utils/init.c srcs/parsing/parsing.c\
        srcs/error/error.c srcs/utils/ft_itoa_philo.c\
		srcs/exec/actions.c srcs/exec/launch.c srcs/exec/routines.c\
		srcs/utils/free.c srcs/utils/ft_itoa_name.c

NAME = philo_two
OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
INCLUDE			= -I ./includes/
CFLAGS			= -Wall -Werror -Wextra -pthread

all: $(NAME)

%.o: %.c
				${CC} -c ${CFLAGS} ${INCLUDE} ${LIBS} $< -o $@

$(NAME):		$(OBJS)
				${CC} $(OBJS) ${INCLUDE} ${CFLAGS} -o $(NAME)

clean:
				$(RM) ${OBJS}

fclean:			clean
				$(RM) $(NAME)


re:				fclean all

.PHONY:			all clean fclean re


