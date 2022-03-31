# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/28 12:23:50 by mmaxime-          #+#    #+#              #
#    Updated: 2022/03/30 11:32:53 by mmaxime-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME			=	libft.a
CC				=	gcc
RM 				=	rm -f
CFLAGS			=	-Wall -Werror -Wextra -fsanitize=address

#Sources

FILES		=	$(wildcard *.c)

#Binaries

SRCS		=	$(addprefix ., $(FILES))
OBJS		=	$(addprefix obj/, $(FILES:.c=.o))

#Rules

obj/%.o:		%.c
					@mkdir -p obj/
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
