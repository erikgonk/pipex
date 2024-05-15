# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erigonza <erigonza@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 11:21:29 by erigonza          #+#    #+#              #
#    Updated: 2024/04/17 12:09:14 by erigonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------------------VARIABLES----------------------------------#

NAME = libft.a

RM = rm -fr

INCL = libft.h
SRCS = ft_atoi.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putchar_fd.c\
	   ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_isalpha.c ft_isdigit.c\
	   ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memset.c\
	   ft_bzero.c ft_memcmp.c ft_memmove.c ft_memchr.c ft_memcpy.c ft_calloc.c\
	   ft_strlen.c ft_strdup.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
	   ft_strnstr.c ft_strncmp.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c\
	   ft_strmapi.c ft_striteri.c\
	   ft_printf.c ft_putchar_error.c\
	   get_next_line.c get_next_line_utils.c\

OBJS = $(SRCS:%.c=%.o)
DEPS = $(SRCS:%.c=%.d)

CFLAGS = -Wall -Wextra -Werror -MMD -g

#------------------------------------EXECUTE-----------------------------------#

.SILENT:

%.o: %.c Makefile
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

#-------------------------------------CLEAN------------------------------------#

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
.SILENT:
