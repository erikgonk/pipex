# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/15 18:54:49 by erigonza          #+#    #+#              #
#    Updated: 2024/05/24 18:53:51 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = pipex.c childs.c
DIR_SRC = ./src
DIR_OBJ = $(DIR_SRC)/obj
OBJS = $(addprefix $(DIR_OBJ)/, $(SRCS:.c=.o))
NAME	= pipex

LIB		= src/libft/libft.a

AR		= ar rcs

RM		 = rm -fr

INC = -I ./inc/

CFLAGS	= -Wall -Wextra -Werror -g #-fsanitize=address

CC = gcc

all:		libft ${NAME}

libft: 
				make -C src/libft
				mkdir -p $(DIR_OBJ)

$(DIR_OBJ)/%.o:		$(DIR_SRC)/%.c Makefile ./inc/pipex.h
				$(CC) $(FLAGS) $(INC)  -c $< -o $@
				clear

${NAME}:	${OBJS}
				${CC} ${CFLAGS} ${OBJS} ${LIB} -o ${NAME} $(INC)
				clear

clean:
				make clean -C src/libft
				${RM} ${OBJS}
				clear

fclean:		clean
				make fclean -C src/libft 
				${RM} ${NAME} ${DIR_OBJ}
				clear

re:			fclean all

.PHONY:		clean fclean re all libft
.SILENT:
