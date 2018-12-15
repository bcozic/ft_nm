/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 17:42:56 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/15 20:46:22 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OTOOL_H
# define FT_OTOOL_H

# include <mach-o/loader.h>
# include <mach-o/fat.h>
# include <mach-o/nlist.h>
# include <mach-o/ranlib.h>
# include <ar.h>
# include <sys/types.h>
# include "libft.h"

typedef struct		s_data
{
	void		*ptr;
	size_t		end_file;
	char		*file_name;
	size_t		ppc;
}					t_data;

int					ft_otool(void *ptr, t_data *data);
int					get_stat(int fd, char *file_name, char *exec_name);
int					aff_error(char *exec, char *file, char *str_error);
int					ft_otool(void *ptr, t_data *data);
void				handle_little_64(void *ptr, t_data *data);
void				handle_little_32(void *ptr, t_data *data);
void				handle_big_64(void *ptr, t_data *data);
void				handle_big_32(void *ptr, t_data *data);
int					get_section_little_64(struct segment_command_64 *segment, t_data *data);
int					get_section_little_32(struct segment_command *segment, t_data *data);
int					get_section_big_64(struct segment_command_64 *segment, t_data *data);
int					get_section_big_32(struct segment_command *segment, t_data *data);
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
void				print_section_little_32(uint8_t *ptr, uint32_t addr, t_data *data, uint32_t size);
void				print_section_little_64(uint8_t *ptr, uint64_t addr, t_data *data, uint64_t size);
void				print_section_big_32(uint8_t *ptr, uint32_t addr, t_data *data, uint32_t size);
void				print_section_big_64(uint8_t *ptr, uint64_t addr, t_data *data, uint64_t size);
void				get_header_64(t_data *data, void *offset, void *ptr);
void				get_header_32(t_data *data, void *offset, void *ptr);
int					print_name(void *ptr, t_data *data);
void				print_ppc_little_32(uint32_t *ptr, uint32_t addr, t_data *data, uint32_t size);
void				print_ppc_little_64(uint32_t *ptr, uint64_t addr, t_data *data, uint64_t size);
void				print_ppc_big_32(uint32_t *ptr, uint32_t addr, t_data *data, uint32_t size);
void				print_ppc_big_64(uint32_t *ptr, uint64_t addr, t_data *data, uint64_t size);
#endif
