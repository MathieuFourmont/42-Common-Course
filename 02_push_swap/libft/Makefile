# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/28 12:23:50 by mmaxime-          #+#    #+#              #
#    Updated: 2022/02/22 14:05:19 by mmaxime-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME			=	libft.a
CC				=	gcc
RM 				=	rm -f
CFLAGS			=	-Wall -Werror -Wextra -fsanitize=address

#Sources

SRC_FILES		=	$(wildcard *.c)
INCLUDES		=	libft.h

#Binaries

OBJS			=	$(SRC_FILES:.c=.o)

#Rules

%.o:			%.c
					$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
					ar -rcs $(NAME) $(OBJS)

clean:
					$(RM) $(OBJS)

fclean:			clean
					$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
