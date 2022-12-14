# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 16:01:13 by mmaxime-          #+#    #+#              #
#    Updated: 2022/10/03 16:01:13 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#---------------------------------- VARIABLES ---------------------------------#
#------------------------------------------------------------------------------#

#Output

NAME		=	Phonebook

#Paths

VPATH		=	src/
INC_PATH	=	includes/
OBJ_PATH	=	obj/

#Files

SRCS		=	Phonebook.cpp \
				Contact.cpp \
				main.cpp
INCS	=	$(addprefix $(INC_PATH), Phonebook.hpp Contact.hpp)
OBJS		=	$(addprefix $(OBJ_PATH), $(SRCS:.cpp=.o))

#Macros

CPPC		=	g++
CPPFLAGS	=	-std=c++98 -Wall -Wextra -Werror
INCLUDE		=	-I$(INC_PATH)
RM			=	rm -rf

#------------------------------------------------------------------------------#
#----------------------------------- TARGETS ----------------------------------#
#------------------------------------------------------------------------------#

#Main Rules

all :				$(NAME)

$(NAME) :			$(OBJS)
						$(CPPC) $(CPPFLAGS) $(OBJS) -o $@ $(INCLUDE)

re :				fclean all

#Compilation Rules

$(OBJ_PATH)%.o :	%.cpp Makefile
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
						$(RM) -R Phonebook.dSYM