# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaxime- <mmaxime-@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/05 10:44:28 by mmaxime-          #+#    #+#              #
#    Updated: 2024/01/05 11:06:43 by mmaxime-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OUTPUT

NAME					=	gnl
NAME_BONUS				=	gnl_bonus

# COMMANDS

CC						=	gcc
CFLAGS					=	-Wall -Werror -Wextra
INCLUDE					=	-I$(INC_PATH)
RM 						=	rm -rf

# PATHS

VPATH					=	src/
INC_PATH				=	includes/
OBJ_PATH				=	obj/
OBJ_PATH_BONUS			=	obj/bonus/

# FILES

SRCS					=	get_next_line.c \
							get_next_line_utils.c \
							main.c

SRCS_BONUS				=	get_next_line_bonus.c \
							get_next_line_utils_bonus.c \
							main.c

INCS_FILES				=	get_next_line.h

INCS_FILES_BONUS		=	get_next_line_bonus.h

INCS					=	$(addprefix $(INC_PATH), $(INCS_FILES))

INCS_BONUS				=	$(addprefix $(INC_PATH), $(INCS_FILES_BONUS))

OBJS					=	$(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

OBJS_BONUS				=	$(addprefix $(OBJ_PATH_BONUS), $(SRCS_BONUS:.c=.o))

#Rules

.PHONY:	all
all:					$(NAME)

$(NAME):				$(OBJS)
						$(CC) $(CFLAGS) $^ -o $@ $(INCLUDE)

$(OBJ_PATH)%.o:			%.c Makefile $(INCS)
						@mkdir -p $(dir $@)
						$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

.PHONY:	clean
clean:
						$(RM) $(OBJ_PATH) $(OBJ_PATH_BONUS)

.PHONY:	fclean
fclean:					clean
						$(RM) $(NAME) $(NAME_BONUS)

.PHONY:	re
re:						fclean
						$(MAKE) all

.PHONY:	bonus
bonus:					$(NAME_BONUS)

$(OBJ_PATH_BONUS)%.o:	%.c Makefile $(INCS_BONUS)
						@mkdir -p $(dir $@)
						@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

$(NAME_BONUS):			$(OBJS_BONUS)
						$(CC) $(CFLAGS) $^ -o $@ $(INCLUDE)