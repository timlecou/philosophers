SRCS = srcs/philo_one.c srcs/utils/utils.c srcs/utils/init.c srcs/parsing/parsing.c\
        srcs/error/error.c srcs/utils/ft_itoa_philo.c

CC = gcc

INCLUDES = includes

NAME = philo_one

FLAGS = -Wextra -Werror -Wall -pthread

all:
	$(CC) $(FLAGS) -o $(NAME) $(SRCS) -I $(INCLUDES)
