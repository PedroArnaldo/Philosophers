NAME = philo
MAKEFLGS += --silent
CC = cc -g
CFLAGS = -Wextra -Wall -Werror -pthread
RM = rm -fr

SRC = src/philo.c \
      src/utils/ft_atoi.c \

OBJS = $(SRC:.c=.o)

%.o: %.c
		${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS)
		$(CC) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
