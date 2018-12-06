# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 18:10:54 by bcozic            #+#    #+#              #
#    Updated: 2018/12/03 07:24:43 by bcozic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -Weverything -g

NO_COLOR=\x1b[0m

GREEN=\x1b[32;01m

RED=\x1b[31;01m

SRC = ft_abs.c ft_nbrlen.c ft_isint.c ft_memset.c\
	  ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c\
	  ft_memchr.c ft_memcmp.c ft_strlen.c ft_tab_strlen.c\
	  ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c\
	  ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c\
	  ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c\
	  ft_atoi.c ft_atoi_unsigned.c ft_isalpha.c ft_isdigit.c\
	  ft_issignnb.c ft_isalnum.c ft_isascii.c ft_isprint.c\
	  ft_isspace.c ft_isnum.c ft_toupper.c ft_tolower.c\
	  ft_isstr_f.c ft_memalloc.c ft_memdel.c ft_strnew.c\
	  ft_strdel.c ft_strmap.c ft_strmapi.c ft_strequ.c\
	  ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strjoinflush.c\
	  ft_strnjoinflush.c ft_strtrim.c ft_strsplit.c ft_itoa.c\
	  ft_putstr.c ft_putnbr.c ft_putstr_fd.c ft_putnbr_fd.c\
	  ft_strup.c get_next_line.c ft_free_and_reset.c

SRC_PRINTF = ft_printf.c chrflags.c add_arg.c apply_flag.c\
			 convert_nb.c flag_cara.c llitoa_base_mod.c ullitoa_base_mod.c\
			 unicode.c\

SRC_MALLOC = ft_malloc.c data_page.c get_alloc.c ft_free.c\
			 data_to_remove.c ft_realloc.c ft_calloc.c show_alloc_mem.c\
			 ft_valloc.c fnc_packets.c

OBJ = $(addprefix obj/, $(SRC:.c=.o))

OBJ_PRINTF = $(addprefix ft_printf/obj/, $(SRC_PRINTF:.c=.o))

OBJ_MALLOC = $(addprefix ft_malloc/obj/, $(SRC_MALLOC:.c=.o))

INC_PATH = includes

INCLUDE = $(INC_PATH)/libft.h

all : obj printf malloc $(NAME)
	@echo "$(GREEN)Libft OK$(NO_COLOR)"

printf :
	make -C ft_printf

malloc :
	make -C ft_malloc

obj :
	mkdir obj

obj/%.o: src/%.c $(INCLUDE)
	gcc $(CFLAGS) -c $< -o $@ -I $(INC_PATH)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ) $(OBJ_PRINTF) $(OBJ_MALLOC)
	ranlib $(NAME)

clean :
	rm -f $(OBJ)
	make -C ft_printf clean
	make -C ft_malloc clean
	@echo "$(RED)Obj libft Deleted$(NO_COLOR)"

fclean : clean
	rm -f $(NAME)
	@echo "$(RED)$(NAME) Deleted$(NO_COLOR)"

re : fclean all

.PHONY : re all clean fclean
