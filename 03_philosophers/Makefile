# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 10:04:14 by mmaxime-          #+#    #+#              #
#    Updated: 2022/08/12 11:35:48 by mmaxime-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#---------------------------------- VARIABLES ---------------------------------#
#------------------------------------------------------------------------------#

#Output

NAME		=		philo

#Paths

VPATH		=		src/
INC_PATH	=		includes/
OBJ_PATH	=		obj/

#Files

SRCS		=		philo.c \
					actions.c \
					checks.c \
					ft_clean.c \
					init.c \
					philo_utils.c
				
INCS		=	$(addprefix $(INC_PATH), philo.h)

OBJS		=	$(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

#Macros

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -pthread #-g -fsanitize=thread -fsanitize=address
INCLUDE		=	-I$(INC_PATH)
RM			=	rm -rf

#------------------------------------------------------------------------------#
#----------------------------------- TARGETS ----------------------------------#
#------------------------------------------------------------------------------#

#Main Rules

all :			$(NAME)

$(NAME) :		$(OBJS)
				$(CC) $(CFLAGS) $^ -o $@ $(INCLUDE)

re :				fclean all

#Compilation Rules

$(OBJ_PATH)%.o :	%.c $(INCS)
					@mkdir -p $(dir $@);
					$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

#Checking Rules

debug :		
				$(CC) -g $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

valgrind :
				valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

#Cleaning Rules

clean :
				$(RM) $(OBJ_PATH)

fclean :		clean
				$(RM) $(NAME)
				$(RM) -R philo.dSYM

.PHONY :		all clean fclean re debug valgrind