# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/19 12:22:35 by barbara           #+#    #+#              #
#    Updated: 2018/12/14 19:24:21 by bcozic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_nm

NO_COLOR=\x1b[0m

GREEN=\x1b[32;01m

RED=\x1b[31;01m

CFLAGS = -Wall -Wextra -Werror -Weverything -g

SRC = main.c add_segment.c free_all.c print_symbol.c\
	  free_list_sym.c free_section.c ft_nm.c get_section.c\
	  get_stat.c get_symbols.c get_type.c handle.c\
	  insert_by_name_little_32.c insert_by_name_little_64.c\
	  insert_by_name_big_32.c insert_by_name_big_64.c\
	  insert_sym_list.c little_endian.c handle_ar.c get_header.c\
	  print_architecture.c aff_error.c fat_header_little_64.c\
	  fat_header_little_32.c fat_header_big_64.c fat_header_big_32.c

OBJ = $(addprefix obj/, $(SRC:.c=.o))

LIBFT = libft/libft.a

INC_LIB = libft/includes

INC_NM = includes

INCLUDE_NM = $(INC_NM)/ft_nm_otool.h

all : lib obj $(NAME)

$(LIBFT) : lib

lib :
	@make -C libft

obj :
	@mkdir obj

obj/%.o: src/ft_nm/%.c $(INCLUDE_NM)
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