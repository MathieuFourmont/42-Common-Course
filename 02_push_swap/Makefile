# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 10:25:00 by mmaxime-          #+#    #+#              #
#    Updated: 2022/02/23 11:31:50 by mmaxime-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		=	push_swap
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address

#Sources

SRCS		=	$(wildcard *.c)
INCLUDES	=	push_swap.h
LIBFT		=	libft/libft.a
LIBFT_DIR	=	libft

#Binaries

OBJS		=	$(SRCS:.c=.o)

#Rules

all:		$(NAME)

$(LIBFT):
				make -C $(LIBFT_DIR) --silent

$(NAME):	$(OBJS) $(LIBFT)
				$(CC) $(CFLAGS) -I$(INCLUDES) -o $(NAME) $(OBJS) $(LIBFT)

%.o:			%.c
					$(CC) $(CFLAGS) -c $< -o $@

debug:		$(LIBFT)
				$(CC) -g $(CFLAGS) -I$(INCLUDES) $(LIBFT) $(SRCS) -o $(NAME)

valgrind:
				valgrind --leak-check=full --show-leak-kinds=all --trackorigins=yes ./$(NAME) 45 848 26 987 -542 5 99 0 6978 -4238

clean:
				$(RM) $(OBJS)
				make -C $(LIBFT_DIR) clean

fclean:		clean
				$(RM) $(NAME)
				$(RM) -R push_swap.dSYM
				make -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re debug
