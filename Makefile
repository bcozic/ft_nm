# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/19 12:22:35 by barbara           #+#    #+#              #
#    Updated: 2018/12/16 14:25:10 by bcozic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_NM = ft_nm

FT_OTOOL = ft_otool

NO_COLOR=\x1b[0m

GREEN=\x1b[32;01m

RED=\x1b[31;01m

CFLAGS = -Wall -Wextra -Werror -Weverything -g

SRC_NM = main.c free_all.c print_symbol.c free_list_sym.c\
	  free_section.c ft_nm.c get_section.c get_stat.c\
	  get_symbols.c get_type.c handle.c insert_by_name_little_32.c\
	  insert_by_name_little_64.c insert_by_name_big_32.c\
	  insert_by_name_big_64.c insert_sym_list.c little_endian.c\
	  handle_ar.c get_header.c print_architecture.c aff_error.c\
	  fat_header_little_64.c fat_header_little_32.c\
	  fat_header_big_64.c fat_header_big_32.c add_segment_64.c\
	  add_segment_32.c

SRC_OTOOL = main.c aff_error.c fat_header_big_32.c fat_header_big_64.c\
			fat_header_little_32.c fat_header_little_64.c ft_otool.c\
			get_section.c get_stat.c handle_ar.c handle.c little_endian.c\
			print_architecture.c get_header.c print_name.c\
			print_ppc.c print_section_32.c print_section_64.c

OBJ_NM = $(addprefix obj/ft_nm/, $(SRC_NM:.c=.o))

OBJ_OTOOL = $(addprefix obj/ft_otool/, $(SRC_OTOOL:.c=.o))

LIBFT = libft/libft.a

INC_LIB = libft/includes

INC = includes

INCLUDE_NM = $(INC)/ft_nm.h

INCLUDE_OTOOL = $(INC)/ft_otool.h

all : lib obj_create $(FT_NM) $(FT_OTOOL)

$(LIBFT) : lib

lib :
	@make -C libft

obj_create :
	@mkdir -p obj
	@mkdir -p obj/ft_nm
	@mkdir -p obj/ft_otool

obj/ft_nm/%.o: src/ft_nm/%.c $(INCLUDE_NM)
	gcc $(CFLAGS) -c $< -o $@ -I $(INC_LIB) -I $(INC)

obj/ft_otool/%.o: src/ft_otool/%.c $(INCLUDE_OTOOL)
	gcc $(CFLAGS) -c $< -o $@ -I $(INC_LIB) -I $(INC)

$(FT_NM) : $(LIBFT) $(OBJ_NM)
	gcc -o $(FT_NM) $(OBJ_NM) $(LIBFT)
	@echo "$(GREEN)$(FT_NM) OK$(NO_COLOR)"

$(FT_OTOOL) : $(LIBFT) $(OBJ_OTOOL)
	gcc -o $(FT_OTOOL) $(OBJ_OTOOL) $(LIBFT)
	@echo "$(GREEN)$(FT_OTOOL) OK$(NO_COLOR)"

clean : clean_libft
	rm -f $(OBJ_NM) $(OBJ_OTOOL)
	@echo "$(RED)$(FT_NM) obj Deleted$(NO_COLOR)"
	@echo "$(RED)$(FT_OTOOL) obj Deleted$(NO_COLOR)"

clean_libft :
	@make -C libft clean

fclean_libft : clean_libft
	@make -C libft fclean

fclean : clean fclean_libft
	rm -f $(FT_NM)
	@echo "$(RED)$(FT_NM) Deleted$(NO_COLOR)"
	@echo "$(RED)$(FT_OTOOL) Deleted$(NO_COLOR)"

re : fclean all
	
.PHONY : all clean clean_libft fclean_libft fclean re