# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaxime- <mmaxime-@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/28 12:23:50 by mmaxime-          #+#    #+#              #
#    Updated: 2024/01/04 17:21:25 by mmaxime-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OUTPUT

NAME					=	libft.a

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

SRCS					=	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
							ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
							ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
							ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
							ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
							ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
							ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCS_BONUS				=	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
							ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
							ft_lstmap.c

INCS_FILES				=	libft.h

INCS					=	$(addprefix $(INC_PATH), $(INCS_FILES))

OBJS					=	$(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

OBJS_BONUS				=	$(addprefix $(OBJ_PATH_BONUS), $(SRCS_BONUS:.c=.o))

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

.PHONY:	bonus
bonus:					$(OBJS_BONUS)
						ar -rcs $(NAME) $(OBJS_BONUS)

$(OBJ_PATH_BONUS)%.o:	%.c Makefile $(INCS)
						@mkdir -p $(dir $@)
						@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)
