# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yeomin <yeomin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/12 15:44:38 by yeomin            #+#    #+#              #
#    Updated: 2023/03/19 18:24:08 by yeomin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c
BNS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
INCS = libft.h
OBJS = $(SRCS:.c=.o)
BNSOBJS = $(BNS:.c=.o)

ifdef CHECK_BONUS
	TOTAL_OBJ = $(OBJS) $(BNSOBJS)
else
	TOTAL_OBJ = $(OBJS)
endif

all : $(NAME)

$(NAME): $(TOTAL_OBJ)
	ar -rcs $(NAME) $(TOTAL_OBJ)

bonus:
#	sleep 1
	@make CHECK_BONUS=1 $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -I $(INCS) -o $@

clean:
	rm -f $(OBJS) $(BNSOBJS)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all re fclean clean bonus