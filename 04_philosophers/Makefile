# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miam <miam@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 10:04:14 by mmaxime-          #+#    #+#              #
#    Updated: 2022/07/11 16:09:21 by miam             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		=	philo
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -g -fsanitize=thread

#Sources

SRCS		=	$(wildcard src/*.c)
INCLUDES	=	includes/philo.h

#Binaries

OBJS		=	$(SRCS:.c=.o)

#Rules

all:		$(NAME)

$(NAME):	$(SRCS) $(OBJS)
				$(CC) $(CFLAGS) -I$(INCLUDES) -o $(NAME) $(OBJS)

obj/%.o:	%.c
				$(CC) $(CFLAGS) -c $< -o $@

debug:		
				$(CC) $(CFLAGS) -I$(INCLUDES) $(NAME) $(OBJS)

valgrind:
				valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)
				$(RM) -R philo.dSYM

re:			fclean all

.PHONY:		all clean fclean re debug