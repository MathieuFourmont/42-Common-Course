# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 09:49:09 by mmaxime-          #+#    #+#              #
#    Updated: 2021/11/30 09:49:13 by mmaxime-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		= libftprintf.a
CC 		= gcc
RM		= rm -f
CFLAGS		= -Wall -Werror -Wextra

#Sources

SRC_FILES	= ft_printf.c ft_printf_utils.c ft_printf_utils2.c

#Binaries

OBJS		= $(SRC_FILES:.c=.o)

#Rules

%.o:		%.c
			$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			ar -rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
