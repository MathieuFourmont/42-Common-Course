# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/28 12:23:50 by mmaxime-          #+#    #+#              #
#    Updated: 2022/03/29 11:00:24 by mmaxime-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME			=	libft.a
CC				=	gcc
RM 				=	rm -f
CFLAGS			=	-Wall -Werror -Wextra -fsanitize=address

#Sources

SRCS		=	$(wildcard *.c)

#Binaries

OBJS			=	$(SRCS:.c=.o)

#Rules

%.o:			%.c
					$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
					ar -rcs $(NAME) $(OBJS)

clean:
					$(RM) $(OBJS)

fclean:			clean
					$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus
