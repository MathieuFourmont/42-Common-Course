#Variables

NAME		=	pipex
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address

#Sources

SRCS		=	$(wildcard *.c)
INCLUDES	=	pipex.h
PRINTF		=	ft_printf/libftprintf.a
PRINTF_DIR	=	ft_printf

#Binaries

OBJS		=	$(SRCS:.c=.o)

#Rules

all:		$(NAME)

$(PRINTF):
				make -C $(PRINTF_DIR) --silent

$(NAME):	$(OBJS) $(PRINTF)
				$(CC) $(CFLAGS) -I$(INCLUDES) -o $(NAME) $(OBJS) $(PRINTF)

%.o:			%.c
					$(CC) $(CFLAGS) -c $< -o $@

debug:		$(PRINTF)
				$(CC) -g $(CFLAGS) -I$(INCLUDES) $(PRINTF) $(SRCS) -o $(NAME)

valgrind:
				valgrind --leak-check=full --show-leak-kinds=all --trackorigins=yes ./$(NAME) 45 848 26 987 -542 5 99 0 6978 -4238

clean:
				$(RM) $(OBJS)
				make -C $(PRINTF_DIR) clean

fclean:		clean
				$(RM) $(NAME)
				$(RM) -R pipex.dSYM
				make -C $(PRINTF_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re debug