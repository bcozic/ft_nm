# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 18:10:54 by bcozic            #+#    #+#              #
#    Updated: 2018/11/21 11:05:55 by bcozic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Wextra -Werror -Weverything -g

NO_COLOR=\x1b[0m

GREEN=\x1b[32;01m

RED=\x1b[31;01m

SRC = ft_malloc.c ft_valloc.c ft_calloc.c ft_free.c\
	  ft_realloc.c ft_reallocf.c cut_end_packet.c find_packet.c\
	  get_alloc.c get_memory.c get_new_page.c get_new_struct.c\
	  init_data.c insert_new_element.c remove_packet.c remove_struct.c\
	  unmap_at_exit.c

INCLUDE = ../includes/ft_libc.h\
		  ../includes/libft.h

OBJ = $(addprefix obj/, $(SRC:.c=.o))

all : obj $(OBJ)
	@echo "$(GREEN)ft_malloc OK$(NO_COLOR)"

obj :
	mkdir obj

obj/%.o: src/%.c $(INCLUDE)
	gcc $(CFLAGS) -c $< -o $@ -I includes -I ../includes

clean :
	rm -f $(OBJ)
	@echo "$(RED)$(NAME) ft_malloc obj Deleted$(NO_COLOR)"

re : clean all

.PHONY : re all clean
