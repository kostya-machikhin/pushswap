# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scuger <scuger@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/26 19:27:31 by scuger            #+#    #+#              #
#    Updated: 2020/02/05 17:59:36 by scuger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	push_swap

NAME2   :=  checker


OBJ_DIR	:=	./obj/

SRC_DIR	:=	./src/

INC_LIB	:=	./libft/includes

INC_DIR	:=	./includes


SRC_PS	:=	commands.c \
            commands_2.c \
            distribution.c \
            fill_stack.c \
            index.c \
            push_a.c \
            push_b.c \
            push_swap.c \
            num_command.c \
            num_command_2.c \
            return_command.c \
            scrolling.c \
            stack.c \
            swap_needed.c \
            ft_atoi_ps.c \

SRC_CK  :=  fill_stack.c \
            checker.c \
            stack.c \
            commands.c \
            commands_2.c \
            distribution.c \
            index.c \
            push_b.c \
            swap_needed.c \
            ft_atoi_ps.c \
            do_command.c \

OBJ_PS	:=	$(addprefix $(OBJ_DIR), $(SRC_PS:.c=.o))

OBJ_CK	:=	$(addprefix $(OBJ_DIR), $(SRC_CK:.c=.o))


FLAGS	:=	-Wall -Wextra -Werror

LIBFT	:=	-L libft -lft

.PHONY: all clean fclean re

all: objdir makelibft $(NAME) $(NAME2)

$(NAME): $(OBJ_PS)
	gcc $(FLAGS) -I$(INC_LIB) -I$(INC_DIR) -o $(NAME) $(LIBFT) $(OBJ_PS)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc $(FLAGS) -I$(INC_LIB) -I$(INC_DIR) -o $@ -c $<

$(NAME2): $(OBJ_CK)
	gcc $(FLAGS) -I$(INC_LIB) -I$(INC_DIR) -o $(NAME2) $(LIBFT) $(OBJ_CK)

clean:
	make -C ./libft clean
	/bin/rm -rf $(OBJ_DIR)

fclean: clean
	make -C ./libft fclean
	/bin/rm -f $(NAME)
	/bin/rm -f $(NAME2)

makelibft:
	make -C ./libft

objdir:
	mkdir -p $(OBJ_DIR)

relib:
	make -C ./libft re

re: fclean relib all
