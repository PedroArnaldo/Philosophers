NAME = philo
MAKEFLGS += --silent
CC = cc -g
CFLAGS = -Wextra -Wall -Werror -pthread
RM = rm -fr

SRC = src/philo.c \
	  src/utils/get_time.c \
      src/utils/ft_atoi.c \
	  src/utils/ft_isdigit.c \
	  src/utils/ft_check.c \
	  src/utils/smart_sleep.c \
	  src/init_info.c \
	  src/print_routines.c \
	  src/routines.c \
	  src/monitoring.c

OBJS = $(SRC:.c=.o)

%.o: %.c
		@ ${CC} ${CFLAGS} -c $< -o $@

$(NAME): $(OBJS)
		@echo "Compilation of $(NAME)..."
		@ $(CC) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	@ $(RM) $(OBJS)
	@ echo "Deleting $(NAME) objs ✔️"
fclean: clean
	@ $(RM) $(NAME)
	@ echo "Deleting binary ✔️"

re:	fclean all

.PHONY: all clean fclean re
