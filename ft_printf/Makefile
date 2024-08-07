SOURCES	= \
	ft_printf.c \
	character_count.c \
	spec_functions_1.c \
	spec_functions_2.c \
	helper_functions.c \

OBJECTS		=		$(SOURCES:.c=.o)
LIBFT		=		libft
FLAGS		=		-Wall -Wextra -Werror -g
NAME		=		libftprintf.a
RM			=		rm -f
CC			=		cc
AR			=		ar rcs

all:	${NAME}

allc: all clean

${NAME}: ${OBJECTS}
	make -C $(LIBFT)
	cp libft/libft.a ./
	mv libft.a $(NAME)
	${AR} ${NAME} ${OBJECTS}
	echo ${OBJECTS}

.c.o:
	${CC} ${FLAGS} -c $< -o $@

clean:
	make clean -C $(LIBFT)
	${RM} ${OBJECTS}

fclean: clean
	make fclean -C $(LIBFT)
	${RM} ${NAME}

re: fclean all clean
	make clean -C $(LIBFT)

lib:
	make -C $(LIBFT)
	cp libft/libft.a ./
	mv libft.a $(NAME)

.PHONY: all clean fclean re
