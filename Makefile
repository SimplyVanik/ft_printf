# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdzhanaz <vdzhanaz@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/21 07:33:21 by vdzhanaz          #+#    #+#              #
#    Updated: 2018/10/26 01:56:58 by vdzhanaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re mclean mfclean mre test

NAME		:=	libftprintf.a

SRC_PATH	:=	src/
INC_PATH	:=	includes/
LIB_PATH	:=	libft/
LIB			:=	$(LIB_PATH)libft.a
OBJ_PATH	:=	.obj/

CC			:=	clang
CFLAGS		:=	-Wall -Werror -Wextra
IFLAGS		:=	-I $(INC_PATH) -I $(LIB_PATH)

HFILES		:=	ft_printf
FILES		:=	ft_printf ft_printf1 ft_printf2 ft_printf3
LIB			:=	$(LIB_PATH)libft.a

HDRS := $(addprefix $(INC_PATH), $(addsuffix .h, $(HFILES)))
SRCS := $(addprefix $(SRC_PATH), $(addsuffix .c, $(FILES)))
OBJS := $(addprefix $(OBJ_PATH), $(SRCS:%.c=%.o))


all: $(NAME)

$(NAME): $(LIB) $(OBJ_PATH) $(OBJS)
	cp $(LIB) $(NAME)
	ar -r $(NAME) $(OBJS)
	ranlib $(NAME)
$(LIB):
	make -C $(LIB_PATH)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)$(SRC_PATH)
$(OBJ_PATH)%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

clean: mclean
	make clean -C $(LIB_PATH)
fclean: mfclean
	make fclean -C $(LIB_PATH)
re: fclean all

mclean:
	rm -f $(OBJS) $(DEPS)
mfclean:
	rm -f $(NAME)
	rm -rf $(OBJ_PATH)
mre: mfclean all

#test: all
	#$(CC) -g -o unittest.out $(IFLAGS) $(NAME) unittest.c
	#./unittest.out
	# rm -f unittest.out
