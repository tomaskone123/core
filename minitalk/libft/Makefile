NAME = libft.a
SOURCES = *.c



MAKE = \
	Makefile \
	libft.h \


OBJECTS = $(SOURCES:.c=.o)

CFLAGS = -Wall -Wextra -Werror
CC = cc
AR = ar rcs
all: $(NAME)

$(NAME): $(OBJECTS)
	@$(AR) $(NAME) $?
%.o: %.c
	@$(CC) -c $(CFLAGS) $?
clean:
	@rm -f $(OBJECTS)
	@rm -f *.so
fclean: clean
	@rm -f $(NAME)
re: fclean all
.PHONY: all bonus clean fclean re

