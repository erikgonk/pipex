# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 18:54:49 by erigonza          #+#    #+#              #
#    Updated: 2024/05/15 18:54:55 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLEAR_SCREEN = \x1b[1J \x1b[H

SRCS = pipex.c
DIR_SRC = ./src
DIR_OBJ = $(DIR_SRC)/obj
OBJS = $(addprefix $(DIR_OBJ)/, $(SRCS:.c=.o))
DEPS = $(addprefix $(DIR_OBJ)/, $(SRCS:.c=.d))
NAME	= pipex

# SRCS_B = push_swap_bonus.c utils_push_swap_bonus.c \
# 			errors_bonus.c lst_utils1_bonus.c lst_utils2_bonus.c \
# 			utils_1_bonus.c utils_2_bonus.c \
# 			swap_bonus.c push_bonus.c rotate_bonus.c reverse_rotate_bonus.c
# DIR_OBJ_B = $(DIR_SRC)/obj
# OBJS_B = $(addprefix $(DIR_OBJ_B)/, $(SRCS_B:.c=.o))
# DEPS_B = $(addprefix $(DIR_OBJ_B)/, $(SRCS_B:.c=.d))

LIB		= src/libft/libft.a

AR		= ar rcs

RM		 = rm -fr

CFLAGS	= -Wall -Wextra -Werror -g #-fsanitize=address

CC = gcc

all:		libft ${NAME}

libft: 
				make -C src/libft
				mkdir -p $(DIR_OBJ)

$(DIR_OBJ)/%.o:		$(DIR_SRC)/%.c Makefile
				$(CC) -MMD $(FLAGS)  -c $< -o $@ $(INCLUDES)

${NAME}:	${OBJS} ./inc/pipex.h
				${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}
				echo -n "$(CLEAR_SCREEN)"

# bonus: libft ${NAME}

# ${NAME_B}:	${OBJS_B} ./inc/push_swap_bonus.h
# 				${CC} ${CFLAGS} ${OBJS_B} ${LIB} -o ${NAME}
# 				echo -n "$(CLEAR_SCREEN)"

clean:
				make clean -C src/libft
				${RM} ${OBJS} ${DEPS} ${OBJS_B} ${DEPS_B}
				echo -n "$(CLEAR_SCREEN)"

fclean:		clean
				make fclean -C src/libft 
				${RM} ${NAME} ${NAME_B} ${DIR_OBJ} ${DIR_OBJ_B}
				echo -n "$(CLEAR_SCREEN)"

re:			fclean all

-include ${DEPS} ${DEPS_B}

.PHONY:		clean fclean re all libft bonus
#.SILENT: