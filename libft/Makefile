# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scuger <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/11 15:07:31 by scuger            #+#    #+#              #
#    Updated: 2020/01/28 00:28:08 by kostya           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	libft.a

OBJ_DIR :=  ./obj/

SRC_DIR :=  ./src/

SRC_DIR_PR	:=	./src_pr/

OBJ_DIR_PR :=  ./obj_pr/

INC_DIR	:=	./includes

SRC		:=	get_next_line.c \
			ft_atoi.c \
			ft_bzero.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memalloc.c \
			ft_memccpy.c \
			ft_memchr.c \
			ft_memdel.c \
			ft_memmove.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putchar_fd.c \
			ft_putendl.c \
			ft_putendl_fd.c \
			ft_putnbr.c \
			ft_putnbr_fd.c \
			ft_putstr.c \
			ft_putstr_fd.c \
			ft_strcat.c \
			ft_strcmp.c \
			ft_strcpy.c \
			ft_strdel.c \
			ft_strdup.c \
			ft_strequ.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlen.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strncpy.c \
			ft_strnequ.c \
			ft_strnew.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strsplit.c \
			ft_strstr.c \
			ft_strsub.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_memcmp.c \
			ft_memcpy.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_strncat.c \
			ft_strncmp.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			btree_create_node.c \
			btree_level_count.c \
			btree_search_item.c \
			ft_islower.c \
			ft_isupper.c \

SRC_PR	:=	additionalf.c \
            checks.c \
            csp.c \
   			dioux.c \
            flag.c \
           	ft_atoi_pr.c \
            ft_itoa_base.c \
            ft_printf.c \
            ft_putchar_pr.c \
            ft_putstr_pr.c \
            parseflags.c \
            df.c \
            hhll.c \
            parseint.c \
            parsecolor.c

OBJ_PR	:=	$(addprefix $(OBJ_DIR_PR), $(SRC_PR:.c=.o))

OBJ     :=  $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

FLAGS   :=  -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: objdir objdirpr $(NAME)

$(NAME): $(OBJ) $(OBJ_PR)
	ar rc $(NAME) $(OBJ) $(OBJ_PR)
	ranlib $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc $(FLAGS) -I$(INC_DIR) -o $@ -c $<

$(OBJ_DIR_PR)%.o: $(SRC_DIR_PR)%.c
	gcc $(FLAGS) -I$(INC_DIR) -o $@ -c $<

clean:
	/bin/rm -rf $(OBJ_DIR)
	/bin/rm -rf $(OBJ_DIR_PR)

fclean: clean
	/bin/rm -f $(NAME)

objdir:
	mkdir -p $(OBJ_DIR)

objdirpr:
	mkdir -p $(OBJ_DIR_PR)

re: fclean all
