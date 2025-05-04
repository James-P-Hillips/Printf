SRCS =	ft_printf.c ft_intdec.c ft_numhex.c ft_putptr.c ft_unsignedint.c


OBJS = ${SRCS:.c=.o}

NAME = libftprintf.a
LIBC = ar -rcs
CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}

all: ${NAME}

%.o: %.c ft_printf.h Makefile
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
