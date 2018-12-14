# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 18:10:54 by bcozic            #+#    #+#              #
#    Updated: 2018/12/13 20:50:15 by bcozic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NO_COLOR = \x1b[0m

GREEN = \x1b[32;01m

RED = \x1b[31;01m

CFLAGS = -Wall -Wextra -Werror -Weverything

SRC = ft_printf.c chrflags.c add_arg.c apply_flag.c\
	  convert_nb.c flag_cara.c llitoa_base_mod.c ullitoa_base_mod.c\
	  unicode.c\

OBJ = $(addprefix obj/, $(SRC:.c=.o))

INC_PATH = ../includes/

INCLUDES_PRINTF = $(INC_PATH)ft_printf_data.h\
				  $(INC_PATH)ft_printf.h

INCLUDE_LIBFT = $(INC_PATH)libft.h

all : obj $(OBJ)
	@echo "$(GREEN)ft_printf OK$(NO_COLOR)"

obj :
	mkdir obj

obj/%.o: src/%.c $(INCLUDE_LIBFT) $(INCLUDES_PRINTF)
	gcc $(CFLAGS) -c $< -o $@ -I ../includes

clean :
	rm -f $(OBJ)
	@echo "$(RED)Obj ft_printf Deleted$(NO_COLOR)"

re : clean all

.PHONY : re all clean
