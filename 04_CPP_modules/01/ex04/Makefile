# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/28 10:16:14 by mmaxime-          #+#    #+#              #
#    Updated: 2022/10/28 10:16:14 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#---------------------------------- VARIABLES ---------------------------------#
#------------------------------------------------------------------------------#

#Output

NAME		=	TheBigReplacement

#Paths

VPATH		=	src/
OBJ_PATH	=	obj/

#Files

SRCS		=	main.cpp
OBJS		=	$(addprefix $(OBJ_PATH), $(SRCS:.cpp=.o))

#Macros

CPPC		=	g++
CPPFLAGS	=	-std=c++98 -Wall -Wextra -Werror
RM			=	rm -rf

#------------------------------------------------------------------------------#
#----------------------------------- TARGETS ----------------------------------#
#------------------------------------------------------------------------------#

#Main Rules

all :				$(NAME)

$(NAME) :			$(OBJS)
						$(CPPC) $(CPPFLAGS) $(OBJS) -o $@

re :				fclean all

#Compilation Rules

$(OBJ_PATH)%.o :	%.cpp Makefile
						@mkdir -p $(OBJ_PATH)
						$(CPPC) $(CPPFLAGS) -c $< -o $@

#Checking Rules

debug :		
						$(CC) -g $(CFLAGS) $(OBJS) -o $(NAME)

#Cleaning Rules

clean :
						$(RM) $(OBJ_PATH)

fclean :			clean
						$(RM) $(NAME)
						$(RM) -R TheBigReplacement.dSYM