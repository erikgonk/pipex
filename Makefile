# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 11:21:29 by erigonza          #+#    #+#              #
#    Updated: 2024/11/06 16:46:08 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = pipex.c utils.c 

DIR_SRC = ./src
DIR_OBJ = $(DIR_SRC)/obj
OBJS = $(addprefix $(DIR_OBJ)/, $(SRCS:.c=.o))
DEPS = $(addprefix $(DIR_OBJ)/, $(SRCS:.c=.d))
NAME	= pipex

SRCS_B = pipex_bonus.c utils_bonus.c
DIR_OBJ_B = $(DIR_SRC)/obj
OBJS_B = $(addprefix $(DIR_OBJ_B)/, $(SRCS_B:.c=.o))
DEPS_B = $(addprefix $(DIR_OBJ_B)/, $(SRCS_B:.c=.d))
NAME_B = pipex_bonus

LIB		= src/libft/libft.a

AR		= ar rcs

RM		 = rm -fr

CFLAGS	= -Wall -Wextra -Werror -g #-fsanitize=address

CC = cc

all:		libft ${NAME}

libft: 
				@make -C src/libft
				@mkdir -p $(DIR_OBJ)

$(DIR_OBJ)/%.o:		$(DIR_SRC)/%.c Makefile
				@printf "\033[0;33m\r🔨 $< ✅ \033[0m"
				@$(CC) -MMD $(FLAGS)  -c $< -o $@ $(INCLUDES)

${NAME}:	${OBJS} ./inc/pipex.h
				@${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME}
				clear

b bonus: libft ${NAME_B}

${NAME_B}:	${OBJS_B} ./inc/pipex_bonus.h
				@printf "\033[0;33m\r🔨 BONUS $< ✅ \033[0m"
				@${CC} ${CFLAGS} ${OBJS_B} ${LIB} -o ${NAME_B}
				clear

c clean:
				@make clean -C src/libft
				@${RM} ${OBJS} ${DEPS} ${OBJS_B} ${DEPS_B}
				clear

f fclean:		clean
				@make fclean -C src/libft 
				@${RM} ${NAME} ${NAME_B} ${DIR_OBJ} ${DIR_OBJ_B}
				clear

r re:			fclean all

-include ${DEPS} ${DEPS_B}

.PHONY:		clean fclean re all libft bonus b c f r
.SILENT:
