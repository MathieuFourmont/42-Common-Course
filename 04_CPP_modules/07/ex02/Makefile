# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/10 15:50:30 by mmaxime-          #+#    #+#              #
#    Updated: 2023/02/15 15:03:17 by mmaxime-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#---------------------------------- VARIABLES ---------------------------------#
#------------------------------------------------------------------------------#

#Output

NAME		=	Array

#Paths

VPATH		=	src/
INC_PATH	=	includes/
OBJ_PATH	=	obj/

#Files

SRCS		=	main.cpp
INCS		=	$(addprefix $(INC_PATH), Array.hpp)
OBJS		=	$(addprefix $(OBJ_PATH), $(SRCS:.cpp=.o))

#Macros

CPPC		=	c++
CPPFLAGS	=	-std=c++98 -Wall -Wextra -Werror
INCLUDE		=	-I$(INC_PATH)
RM			=	rm -rf

#------------------------------------------------------------------------------#
#----------------------------------- TARGETS ----------------------------------#
#------------------------------------------------------------------------------#

#Main Rules

all :				$(NAME)

$(NAME) :			$(OBJS) $(INCS)
						$(CPPC) $(CPPFLAGS) $(OBJS) -o $@ $(INCLUDE)

re :				fclean all

#Compilation Rules

$(OBJ_PATH)%.o :	%.cpp Makefile $(INCS)
						@mkdir -p $(OBJ_PATH)
						$(CPPC) $(CPPFLAGS) -c $< -o $@ $(INCLUDE)

#Checking Rules

debug :		
						$(CC) -g $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

#Cleaning Rules

clean :
						$(RM) $(OBJ_PATH)

fclean :			clean
						$(RM) $(NAME)
						$(RM) -R Array.dSYM

.PHONY:				all clean fclean re debug