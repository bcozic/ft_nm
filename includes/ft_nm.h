/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 19:30:31 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/14 19:30:37 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NM_H
# define FT_NM_H

# include <mach-o/loader.h>
# include <mach-o/nlist.h>
# include <mach-o/fat.h>
# include <mach-o/ranlib.h>
# include <ar.h>
# include <sys/types.h>
# include "libft.h"

typedef struct		s_list_sym_64
{
	struct nlist_64			*symbol;
	struct s_list_sym_64	*next;
}					t_list_sym_64;

typedef struct		s_list_sym_32
{
	struct nlist			*symbol;
	struct s_list_sym_32	*next;
}					t_list_sym_32;

typedef struct		s_section_64
{
	struct section_64	*section;
	struct s_section_64	*next;
}					t_section_64;

typedef struct		s_section_32
{
	struct section		*section;
	struct s_section_32	*next;
}					t_section_32;

typedef struct		s_arch_64
{
	void					*ptr;
	size_t					end_file;
	struct mach_header_64	*header;
	struct symtab_command	*symtab;
	t_list_sym_64			*list_sym;
	char					*stringtable;
	t_section_64			*section;
}					t_arch_64;

typedef struct		s_arch_32
{
	void					*ptr;
	size_t					end_file;
	struct mach_header		*header;
	struct symtab_command	*symtab;
	t_list_sym_32			*list_sym;
	char					*stringtable;
	t_section_32			*section;
}					t_arch_32;

typedef struct		s_data
{
	void		*ptr;
	size_t		end_file;
	char		*file_name;
	t_arch_32	arch_32;
	t_arch_64	arch_64;
}					t_data;

int					get_stat(int fd, char *file_name, char *exec_name);
int					aff_error(char *exec, char *file, char *str_error);
int					ft_nm(void *ptr, t_data *data);
void				handle_little_64(void *ptr, t_data *data);
void				handle_little_32(void *ptr, t_data *data);
void				handle_big_64(void *ptr, t_data *data);
void				handle_big_32(void *ptr, t_data *data);
void				get_symbols_little_64(t_arch_64 *arch);
void				get_symbols_little_32(t_arch_32 *arch);
void				get_symbols_big_64(t_arch_64 *arch);
void				get_symbols_big_32(t_arch_32 *arch);
int					insert_sym_list_little_64(struct nlist_64 *symbol,
		t_arch_64 *arch);
int					insert_sym_list_little_32(struct nlist *symbol,
		t_arch_32 *arch);
int					insert_sym_list_big_64(struct nlist_64 *symbol,
		t_arch_64 *arch);
int					insert_sym_list_big_32(struct nlist *symbol,
		t_arch_32 *arch);
void				insert_by_name_little_64(t_list_sym_64 *new,
		t_arch_64 *arch);
void				insert_by_name_little_32(t_list_sym_32 *new,
		t_arch_32 *arch);
void				insert_by_name_big_64(t_list_sym_64 *new, t_arch_64 *arch);
void				insert_by_name_big_32(t_list_sym_32 *new, t_arch_32 *arch);
void				add_segment_little_64(struct segment_command_64 *segment,
		t_arch_64 *arch);
void				add_segment_little_32(struct segment_command *segment,
		t_arch_32 *arch_32);
void				add_segment_big_64(struct segment_command_64 *segment,
		t_arch_64 *arch);
void				add_segment_big_32(struct segment_command *segment,
		t_arch_32 *arch_32);
char				get_type_64(uint8_t type, uint8_t n_sect, uint64_t value,
		t_arch_64 *arch);
char				get_type_32(uint8_t type, uint8_t n_sect, uint64_t value,
		t_arch_32 *arch);
struct section_64	*get_section_64(uint8_t n_sect, t_section_64 *current);
struct section		*get_section_32(uint8_t n_sect, t_section_32 *current);
void				free_all_64(t_arch_64 *arch);
void				free_all_32(t_arch_32 *arch);
void				free_list_sym_64(t_list_sym_64 *list_sym);
void				free_list_sym_32(t_list_sym_32 *list_sym);
void				free_section_64(t_section_64 *section);
void				free_section_32(t_section_32 *section);
int					get_endianness(uint32_t magic_nbr);
uint64_t			lte_64(uint64_t nbr);
uint32_t			lte_32(uint32_t nbr);
uint16_t			lte_16(uint16_t nbr);
void				fat_header_little_64(void *ptr, t_data *data);
void				fat_header_little_32(void *ptr, t_data *data);
void				fat_header_big_64(void *ptr, t_data *data);
void				fat_header_big_32(void *ptr, t_data *data);
void				handle_ar(t_data *data, void *offset, void *ptr);
void				get_header_64(t_data *data, void *offset, void *ptr);
void				get_header_32(t_data *data, void *offset, void *ptr);
void				print_architecture(uint32_t arch, t_data *data);
void				print_symbol_little_64(char type, t_arch_64 *arch,
		struct nlist_64 *symbol);
void				print_symbol_little_32(char type, t_arch_32 *arch,
		struct nlist *symbol);
void				print_symbol_big_64(char type, t_arch_64 *arch,
		struct nlist_64 *symbol);
void				print_symbol_big_32(char type, t_arch_32 *arch,
		struct nlist *symbol);
#endif
