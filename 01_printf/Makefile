# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaxime- <mmaxime-@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/30 09:49:09 by mmaxime-          #+#    #+#              #
#    Updated: 2024/01/05 12:44:35 by mmaxime-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OUTPUT

NAME					= libftprintf.a

# COMMANDS

CC 						=	gcc
CFLAGS					=	-Wall -Werror -Wextra
INCLUDE					=	-I$(INC_PATH)
RM						=	rm -rf

# PATHS

VPATH					=	src/
INC_PATH				=	includes/
OBJ_PATH				=	obj/

#Sources

SRCS					=	ft_printf.c \
							ft_printf_utils.c \
							ft_printf_utils2.c

INCS_FILES				=	ft_printf.h

INCS					=	$(addprefix $(INC_PATH), $(INCS_FILES))

OBJS					=	$(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

#Rules

.PHONY:	all
all:					$(NAME)

$(NAME):				$(OBJS)
						ar -rcs $(NAME) $(OBJS)

$(OBJ_PATH)%.o:			%.c Makefile $(INCS)
						@mkdir -p $(dir $@)
						$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

.PHONY:	clean
clean:
						$(RM) $(OBJ_PATH) $(OBJ_PATH_BONUS)

.PHONY:	fclean
fclean:					clean
						$(RM) $(NAME)

.PHONY:	re
re:						fclean
						$(MAKE) all