
#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdzhanaz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 16:21:12 by vdzhanaz          #+#    #+#              #
#    Updated: 2017/11/21 16:21:18 by vdzhanaz         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libft.a

SRC = ft_memcpy.c \
		ft_striteri.c \
		ft_memdel.c \
		ft_strjoin.c \
		ft_atoi.c \
		ft_memmove.c \
		ft_strlcat.c \
		ft_bzero.c \
		ft_memset.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_isalnum.c \
		ft_putchar.c \
		ft_strmapi.c \
		ft_isalpha.c \
		ft_putchar_fd.c \
		ft_strncat.c \
		ft_isascii.c \
		ft_putendl.c \
		ft_strncmp.c \
		ft_isdigit.c \
		ft_putendl_fd.c \
		ft_strncpy.c \
		ft_isprint.c \
		ft_putnbr.c \
		ft_strnequ.c \
		ft_itoa.c \
		ft_putnbr_fd.c \
		ft_strnew.c \
		ft_lstadd.c \
		ft_putstr.c \
		ft_strnstr.c \
		ft_lstdel.c \
		ft_putstr_fd.c \
		ft_strrchr.c \
		ft_lstdelone.c \
		ft_strcat.c \
		ft_lstiter.c \
		ft_strchr.c \
		ft_strsplit.c \
		ft_lstmap.c \
		ft_strclr.c \
		ft_strstr.c \
		ft_lstnew.c \
		ft_strcmp.c \
		ft_strsub.c \
		ft_strcpy.c \
		ft_memalloc.c \
		ft_strdel.c \
		ft_strtrim.c \
		ft_memccpy.c \
		ft_strdup.c \
		ft_tolower.c \
		ft_memchr.c \
		ft_strequ.c \
		ft_toupper.c \
		ft_memcmp.c \
		ft_striter.c \
		ft_delcont.c \
		ft_lstdelelem.c \
		ft_lstrev.c \
		ft_strnequwr.c \
		ft_strtrimu.c \
		ft_masdel.c \

HEADER = libft.h

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f *.o
	/bin/rm -f *~
	/bin/rm -f *.out
	/bin/rm -f *.gch

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

%.o: %.c
	gcc $(FLAGS) -I $(HEADER) -c $< -o $@
