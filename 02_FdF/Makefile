# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 10:25:00 by mmaxime-          #+#    #+#              #
#    Updated: 2022/03/17 11:45:55 by mmaxime-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		=	fdf
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address

#Sources

SRCS		=	$(wildcard *.c)
INCLUDES	=	fdf.h
LIBFT		=	libft/libft.a
LIBFT_DIR	=	libft

#Binaries

OBJS		=	$(SRCS:.c=.o)

#Rules

all:		$(NAME)

$(LIBFT):
				make -C $(LIBFT_DIR) --silent

$(NAME):	$(OBJS) $(LIBFT)
				$(CC) $(CFLAGS) -I$(INCLUDES) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(LIBFT)

%.o:			%.c
					$(CC) $(CFLAGS) -Imlx -c $< -o $@

debug:		$(LIBFT)
				$(CC) -g $(CFLAGS) -I$(INCLUDES) $(LIBFT) $(SRCS) -o $(NAME)

valgrind:
				valgrind --leak-check=full --show-leak-kinds=all --trackorigins=yes ./$(NAME)

clean:
				$(RM) $(OBJS)
				make -C $(LIBFT_DIR) clean

fclean:		clean
				$(RM) $(NAME)
				$(RM) -R fdf.dSYM
				make -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re debug
