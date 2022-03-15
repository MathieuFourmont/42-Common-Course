#Variables

NAME		=	pipex
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address

#Sources

SRCS		=	pipex.c ft_split.c pipex_utils.c
SRCS_BONUS	=	pipex_bonus.c ft_split.c pipex_utils_bonus.c
INCLUDES	=	pipex.h
PRINTF		=	ft_printf/libftprintf.a
PRINTF_DIR	=	ft_printf

#Binaries

OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

#Rules

all:		$(NAME)

$(PRINTF):
				make -C $(PRINTF_DIR) --silent

$(NAME):	$(OBJS) $(PRINTF)
				$(CC) $(CFLAGS) -I$(INCLUDES) -o $(NAME) $(OBJS) $(PRINTF)

%.o:			%.c
					$(CC) $(CFLAGS) -c $< -o $@
bonus:		$(OBJS_BONUS) $(PRINTF)
				$(CC) $(CFLAGS) -I$(INCLUDES) -o $(NAME) $(OBJS_BONUS) $(PRINTF)
debug:		$(PRINTF)
				$(CC) -g $(CFLAGS) -I$(INCLUDES) $(PRINTF) $(SRCS) -o $(NAME)

valgrind:
				valgrind --leak-check=full --show-leak-kinds=all --trackorigins=yes ./$(NAME) 45 848 26 987 -542 5 99 0 6978 -4238

clean:
				$(RM) $(OBJS) $(OBJS_BONUS)
				make -C $(PRINTF_DIR) clean

fclean:		clean
				$(RM) $(NAME)
				$(RM) -R pipex.dSYM
				make -C $(PRINTF_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re debug bonus