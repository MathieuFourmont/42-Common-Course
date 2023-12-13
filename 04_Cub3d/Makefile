# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmaxime- <mmaxime-@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/13 08:50:49 by plavergn          #+#    #+#              #
#    Updated: 2023/12/13 16:55:34 by mmaxime-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# OUTPUT

NAME				=	cub3D
NAME_BONUS			=	cub3D_bonus

# COMMANDS

CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror -I$(INC) -Imlx_Linux -O3
INCLUDE				=	-I$(INC_PATH)
INCLUDE_BONUS		=	-I$(INC_PATH_BONUS)
RM					=	rm -rf

# PATHS

VPATH				=	src/
INC_PATH			=	includes/
OBJ_PATH			=	obj/

VPATH_BONUS			=	bonus/src/
INC_PATH_BONUS		=	bonus/includes/
OBJ_PATH_BONUS		=	bonus/obj/

INC					=	/usr/include

# FILES

MOVEMENT			=	movement/ft_select_hook.c \
						movement/movement.c \
						movement/movement_utils.c

GET_NEXT_LINE		=	get_next_line/get_next_line.c \
						get_next_line/get_next_line_utils.c

INIT				=	init/init_struct.c \
						init/ft_init_textures.c

PARSING				=	parsing/parsing_map.c \
						parsing/ft_check_filename.c \
						parsing/ft_check_map.c \
						parsing/parsing.c \
						parsing/ft_check_textures_utils.c \
						parsing/ft_check_textures.c \
						parsing/ft_check_color.c \
						parsing/init_textures.c \
						parsing/check_space.c

RAYCASTING			=	raycasting/raycasting.c \
						raycasting/textures.c


UTILS				=	utils/random_utils.c \
						utils/string_utils.c \
						utils/closing.c \
						utils/utils.c

SRCS				=	main.c \
						$(MOVEMENT) \
						$(GET_NEXT_LINE) \
						$(INIT) \
						$(PARSING) \
						$(RAYCASTING) \
						$(UTILS)

INCS_FILES			=	cub3d_define.h \
						cub3d.h \
						cub3d_functions.h \
						cub3d_structures.h \
						get_next_line.h

INCS				=	$(addprefix $(INC_PATH), $(INCS_FILES))

OBJS				=	$(addprefix $(OBJ_PATH), $(SRCS:.c=.o))

# BONUS

MOVEMENT_BONUS		=	movement/ft_select_hook.c \
						movement/movement.c \
						movement/movement_utils.c

GET_NEXT_LINE_BONUS	=	get_next_line/get_next_line.c \
						get_next_line/get_next_line_utils.c

INIT_BONUS			=	init/init_struct.c \
						init/ft_init_textures.c

PARSING_BONUS		=	parsing/parsing_map.c \
						parsing/ft_check_filename.c \
						parsing/ft_check_map.c \
						parsing/parsing.c \
						parsing/ft_check_textures_utils.c \
						parsing/ft_check_textures.c \
						parsing/ft_check_color.c \
						parsing/init_textures.c \
						parsing/check_space.c

RAYCASTING_BONUS	=	raycasting/raycasting.c \
						raycasting/textures.c

UTILS_BONUS			=	utils/random_utils.c \
						utils/string_utils.c \
						utils/closing.c \
						utils/utils.c

SRCS_BONUS			=	main.c \
						$(MOVEMENT_BONUS) \
						$(GET_NEXT_LINE_BONUS) \
						$(INIT_BONUS) \
						$(PARSING_BONUS) \
						$(RAYCASTING_BONUS) \
						$(UTILS_BONUS)

INCS_FILES_BONUS	=	cub3d_define.h \
						cub3d.h \
						cub3d_functions.h \
						cub3d_structures.h \
						get_next_line.h

INCS_BONUS			=	$(addprefix $(INC_PATH_BONUS), $(INCS_FILES_BONUS))

OBJS_BONUS			=	$(addprefix $(OBJ_PATH_BONUS), $(SRCS_BONUS:.c=.o))

# Get OS name
UNAME				:= $(shell uname)

# MACOS
ifeq ($(UNAME), Darwin)
OS					=	MACOS
MLX_DIR				=	mlx
MLX_LIB				=	-Lmlx -lmlx
GRAPH_LIB			=	-framework OpenGL -framework AppKit

# LINUX
else
OS					=	LINUX
MLX_DIR				=	mlx_Linux
MLX_LIB				=	-Lmlx_Linux -lmlx_Linux -L/usr/lib
GRAPH_LIB			=	-lXext -lX11 -lm -lz

endif


.PHONY:	all
all: 				$(NAME)

$(NAME):			$(OBJS)
					$(CC) $(CFLAGS) $^ -o $@ $(INCLUDE) $(MLX_LIB) $(GRAPH_LIB)

$(OBJ_PATH)%.o:		%.c Makefile $(INCS)
					@mkdir -p $(dir $@)
					@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

.PHONY:	clean
clean:
					$(RM) $(OBJ_PATH) $(OBJ_PATH_DIR)

.PHONY:	fclean
fclean:				clean
					$(RM) $(NAME) $(NAME_BONUS)

.PHONY:	re
re:					fclean
					$(MAKE) all

.PHONY:	bonus
bonus:				$(NAME_BONUS)

$(OBJ_PATH_BONUS)%.o:	%.c Makefile $(INCS_BONUS)
						@mkdir -p $(dir $@)
						@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE_BONUS)

$(NAME_BONUS):		$(OBJS_BONUS)
					$(CC) $(CFLAGS) $^ -o $@ $(INCLUDE_BONUS) $(MLX_LIB) $(GRAPH_LIB)
