# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 10:25:00 by mmaxime-          #+#    #+#              #
#    Updated: 2022/03/29 11:00:03 by mmaxime-         ###   ########.fr        #
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
PRINTF		=	ft_printf/libftprintf.a
PRINTF_DIR	=	ft_printf

#Binaries

OBJS		=	$(SRCS:.c=.o)

#Rules

all:		$(NAME)

$(LIBFT):
				make -C $(LIBFT_DIR) --silent

$(PRINTF):
				make -C $(PRINTF_DIR) --silent
$(NAME):	$(OBJS) $(LIBFT) $(PRINTF)
				$(CC) $(CFLAGS) -I$(INCLUDES) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF)

%.o:			%.c
					$(CC) $(CFLAGS) -Imlx -c $< -o $@

debug:		$(LIBFT) $(PRINTF)
				$(CC) -g $(CFLAGS) -I$(INCLUDES) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF)

valgrind:
				valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

clean:
				$(RM) $(OBJS)
				make -C $(LIBFT_DIR) clean
				make -C $(PRINTF_DIR) clean

fclean:		clean
				$(RM) $(NAME)
				$(RM) -R fdf.dSYM
				make -C $(LIBFT_DIR) fclean
				make -C $(PRINTF_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re debug
