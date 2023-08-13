NAME	=	rush01
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra $(HEADERS)
HEADERS =	-I includes/
SRCS	=	$(wildcard src/*.c)
OBJS	=	$(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all $(NAME) clean fclean re