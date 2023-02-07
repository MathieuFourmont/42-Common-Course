# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaxime- <mmaxime-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/26 11:34:51 by mmaxime-          #+#    #+#              #
#    Updated: 2023/01/26 11:34:51 by mmaxime-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#------------------------------------------------------------------------------#
#---------------------------------- VARIABLES ---------------------------------#
#------------------------------------------------------------------------------#

#Output

NAME		=	Interface

#Paths

VPATH		=	src/
INC_PATH	=	includes/
OBJ_PATH	=	obj/

#Files

SRCS		=	AMateria.cpp \
				Character.cpp \
				Cure.cpp \
				Ice.cpp \
				MateriaSource.cpp \
				main.cpp
INCS		=	$(addprefix $(INC_PATH), AMateria.hpp \
				Character.hpp \
				Cure.hpp \
				Ice.hpp \
				ICharacter.hpp \
				IMateriaSource.hpp \
				MateriaSource.hpp)
OBJS		=	$(addprefix $(OBJ_PATH), $(SRCS:.cpp=.o))

#Macros

CPPC		=	c++
CPPFLAGS	=	-std=c++98 -Wall -Wextra -Werror #-fsanitize=address
INCLUDE		=	-I$(INC_PATH)
RM			=	rm -rf

#------------------------------------------------------------------------------#
#----------------------------------- TARGETS ----------------------------------#
#------------------------------------------------------------------------------#

#Main Rules

all :				$(NAME)

$(NAME) :			$(OBJS) $(INCS)
						$(CPPC) $(CPPFLAGS) $(OBJS) -o $@

re :				fclean all

#Compilation Rules

$(OBJ_PATH)%.o :	%.cpp $(INCS)
						@mkdir -p $(OBJ_PATH)
						$(CPPC) $(CPPFLAGS) -c $< -o $@

#Checking Rules

debug :		
						$(CC) -g $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

#Cleaning Rules

clean :
						$(RM) $(OBJ_PATH)

fclean :			clean
						$(RM) $(NAME)
						$(RM) -R Interface.dSYM

.PHONY:				all clean fclean re