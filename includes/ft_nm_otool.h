/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm_otool.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:06:01 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/10 15:57:20 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_OTOOL_H
# define FT_NM_OTOOL_H

# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <sys/types.h>
# include "libft.h"

typedef struct	s_list_sym_64
{
	struct nlist_64			*symbol;
	struct s_list_sym_64	*next;
}				t_list_sym_64;

typedef struct	s_list_sym_32
{
	struct nlist			*symbol;
	struct s_list_sym_32	*next;
}				t_list_sym_32;

typedef struct	s_section_64
{
	struct section_64	*section;
	struct s_section_64	*next;
}				t_section_64;

typedef struct	s_section_32
{
	struct section		*section;
	struct s_section_32	*next;
}				t_section_32;

typedef struct	s_data_64
{
	void					*ptr;
	struct mach_header_64	*header;
	struct symtab_command	*symtab;
	t_list_sym_64			*list_sym;
	char					*stringtable;
	t_section_64			*section;
	int						endianness;
	int		wait;
}				t_data_64;

typedef struct	s_data_32
{
	void					*ptr;
	struct mach_header		*header;
	struct symtab_command	*symtab;
	t_list_sym_32			*list_sym;
	char					*stringtable;
	t_section_32			*section;
	int						endianness;
	int		wait;
}				t_data_32;

void				get_stat(int fd);
void				ft_nm(void *ptr);
void				handle_little_64(void *ptr);
void				handle_little_32(void *ptr);
void				handle_big_64(void *ptr);
void				handle_big_32(void *ptr);
void				get_symbols_little_64(t_data_64 *data);
void				get_symbols_little_32(t_data_32 *data);
void				get_symbols_big_64(t_data_64 *data);
void				get_symbols_big_32(t_data_32 *data);
int					insert_sym_list_little_64(struct nlist_64 *symbol, t_data_64 *data);
int					insert_sym_list_little_32(struct nlist *symbol, t_data_32 *data);
int					insert_sym_list_big_64(struct nlist_64 *symbol, t_data_64 *data);
int					insert_sym_list_big_32(struct nlist *symbol, t_data_32 *data);
void				insert_by_name_little_64(t_list_sym_64 *new_elem, t_data_64 *data);
void				insert_by_name_little_32(t_list_sym_32 *new_elem, t_data_32 *data);
void				insert_by_name_big_64(t_list_sym_64 *new_elem, t_data_64 *data);
void				insert_by_name_big_32(t_list_sym_32 *new_elem, t_data_32 *data);
void				add_segment_little_64(struct segment_command_64 *segment, t_data_64 *data);
void				add_segment_little_32(struct segment_command *segment, t_data_32 *data_32);
void				add_segment_big_64(struct segment_command_64 *segment, t_data_64 *data);
void				add_segment_big_32(struct segment_command *segment, t_data_32 *data_32);
char				get_type_64(uint8_t type, uint8_t n_sect, uint64_t value, t_data_64 *data);
char				get_type_32(uint8_t type, uint8_t n_sect, uint64_t value, t_data_32 *data);
struct section_64	*get_section_64(uint8_t n_sect, t_section_64 *current);
struct section		*get_section_32(uint8_t n_sect, t_section_32 *current);
void				free_all_64(t_data_64 *data);
void				free_all_32(t_data_32 *data);
void				free_list_sym_64(t_list_sym_64 *list_sym);
void				free_list_sym_32(t_list_sym_32 *list_sym);
void				free_section_64(t_section_64 *section);
void				free_section_32(t_section_32 *section);
int					get_endianness(uint32_t magic_nbr);
uint64_t			lte_64(uint64_t nbr);
uint32_t			lte_32(uint32_t nbr);
uint16_t			lte_16(uint16_t nbr);
void				fat_header_little_64(void *ptr);
void				fat_header_little_32(void *ptr);
void				fat_header_big_64(void *ptr);
void				fat_header_big_32(void *ptr);
#endif
