NAME		=	philo
CC			=	gcc
INCLUDES	=	includes/includes.h includes/functions.h includes/defines.h includes/struct.h
CFLAGS		=	-Wall -Werror -Wextra -pthread -I./includes
#-g3\
#-fsanitize=address
MAIN		=	main.c
UTIL		=	utils.c utils_thread.c
PARSE		=	parsing.c
SRC			=	routine.c check.c check_local.c
LIST		=	list.c
LISTS		=	$(addprefix list/, $(LIST))
SRCS		=	$(addprefix srcs/, $(SRC))
UTILS		=	$(addprefix utils/, $(UTIL))
PARSES		=	$(addprefix parsing/, $(PARSE))
OBJS		=	$(MAIN:.c=.o) $(UTIL:.c=.o) $(PARSE:.c=.o) $(LIST:.c=.o) $(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

$(OBJS):	$(INCLUDES) $(MAIN) $(UTILS) $(PARSES) $(LISTS) $(SRCS)
		$(CC) $(CFLAGS) -c $(MAIN) $(UTILS) $(PARSES) $(LISTS) $(SRCS)

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
