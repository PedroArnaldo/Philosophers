NAME = philo
MAKEFLGS += --silent
CC = cc
CFLAGS = -Wextra -Wall -Werror
RM = rm -fr

SRC = ./srcs/

OBJ = $(SRC:.c=.o)

# LIBFT #
LIBFT = ./libs/libft/libft.a
LIBFT_DIR = ./libs/libft
LIBFT_IN  = ./libs/libft/libft.h

