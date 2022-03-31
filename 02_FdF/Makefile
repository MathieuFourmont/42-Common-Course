# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 10:25:00 by mmaxime-          #+#    #+#              #
#    Updated: 2022/03/30 19:16:26 by mmaxime-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME		=	fdf
NAME_BONUS	=	fdf_bonus
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Wextra -Werror -fsanitize=address

#Sources

SRCS		=	$(wildcard src/*.c)
SRCS_BONUS	=	$(wildcard bonus/*.c)
INCLUDES	=	includes/fdf.h
INCS_BONUS	=	bonus/fdf_bonus.h
LIBFT		=	libft/libft.a
LIBFT_DIR	=	libft
PRINTF		=	ft_printf/libftprintf.a
PRINTF_DIR	=	ft_printf

#Binaries


OBJS		=	$(SRCS:.c=.o)
BONUS_OBJS	=	$(SRCS_BONUS:.c=.o)

#Rules

all:		$(NAME)

$(LIBFT):
				make -C $(LIBFT_DIR) --silent

$(PRINTF):
				make -C $(PRINTF_DIR) --silent
$(NAME):	$(SRCS) $(OBJS) $(LIBFT) $(PRINTF)
				$(CC) $(CFLAGS) -I$(INCLUDES) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF)

obj/%.o:	%.c
				$(CC) $(CFLAGS) -Imlx -c $< -o $@

bonus:		$(SRCS_BONUS) $(BONUS_OBJS) $(LIBFT) $(PRINTF)
				$(CC) $(CFLAGS) -I$(INCS_BONUS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME_BONUS) $(BONUS_OBJS) $(LIBFT) $(PRINTF)

debug:		$(LIBFT) $(PRINTF)
				$(CC) -g $(CFLAGS) -I$(INCLUDES) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) $(LIBFT) $(PRINTF)

valgrind:
				valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)
				make -C $(LIBFT_DIR) clean
				make -C $(PRINTF_DIR) clean

fclean:		clean
				$(RM) $(NAME) $(NAME_BONUS)
				$(RM) -R fdf.dSYM fdf_bonus.dSYM
				make -C $(LIBFT_DIR) fclean
				make -C $(PRINTF_DIR) fclean

re:			fclean all

.PHONY:		all clean fclean re debug
