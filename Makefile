# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/19 12:22:35 by barbara           #+#    #+#              #
#    Updated: 2018/12/06 07:39:47 by bcozic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_nm

NO_COLOR=\x1b[0m

GREEN=\x1b[32;01m

RED=\x1b[31;01m

CFLAGS = -Wall -Wextra -Werror -Weverything -g

SRC = main.c


OBJ = $(addprefix obj/, $(SRC:.c=.o))

LIBFT = libft/libft.a

INC_LIB = libft/includes

INC_NM = includes

INCLUDE_NM = $(INC_NM)/ft_nm.h

all : lib obj $(NAME)

$(LIBFT) : lib

lib :
	@make -C libft

obj :
	@mkdir obj

obj/%.o: src/%.c $(INCLUDE_NM)
	gcc $(CFLAGS) -c $< -o $@ -I $(INC_LIB) -I $(INC_NM)

$(NAME) : $(LIBFT) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LIBFT)
	@echo "$(GREEN)$(NAME) OK$(NO_COLOR)"

clean : clean_libft
	rm -f $(OBJ)
	@echo "$(RED)$(NAME) obj Deleted$(NO_COLOR)"

clean_libft :
	@make -C libft clean

fclean_libft : clean_libft
	@make -C libft fclean

fclean : clean fclean_libft
	rm -f $(NAME)
	@echo "$(RED)$(NAME) Deleted$(NO_COLOR)"

re : fclean all
	
.PHONY : all clean clean_libft fclean_libft fclean re