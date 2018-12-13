/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:56:30 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/13 17:38:46 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

char	get_type_64(uint8_t type, uint8_t n_sect, uint64_t value, t_arch_64 *arch)
{
	char				char_type;
	struct section_64	*section;

	section = get_section_64(n_sect, arch->section);
	char_type = '?';
	if ((type & N_TYPE) == N_ABS)
		char_type = 'a';
	else if (section)
	{
		// ft_printf("%x %d %s %s\n", type, n_sect, section->segname, section->sectname);
		if (!ft_strncmp("__DATA", section->segname, 16) && !ft_strncmp("__bss", section->sectname, 16))
			char_type = 'b';
		// else if (!ft_strncmp("__DATA", section->segname, 16) && !ft_strncmp("__common", section->sectname, 16))
		// 	char_type = 'c';
		else if (!ft_strncmp("__TEXT", section->segname, 16) && !ft_strncmp("__text", section->sectname, 16))
			char_type = 't';
		else if (!ft_strncmp("__DATA", section->segname, 16) && !ft_strncmp("__data", section->sectname, 16))
			char_type = 'd';
		else
			char_type = 's';
	}
	else if ((type & N_TYPE) == N_UNDF && value && (type & N_EXT))
		char_type = 'C';
	else if ((type & N_TYPE) == N_UNDF)
		char_type = 'U';
	else if ((type & N_INDR))
		char_type = 'I';
	if (type & N_EXT)
		char_type = (char)ft_toupper((int)char_type);
	return (char_type);
}

char	get_type_32(uint8_t type, uint8_t n_sect, uint64_t value, t_arch_32 *arch)
{
	char				char_type;
	struct section		*section;

	section = get_section_32(n_sect, arch->section);
	char_type = '?';
	if ((type & N_TYPE) == N_ABS)
		char_type = 'A';
	else if (section)
	{
		// ft_printf("%s %s\n", section->segname, section->sectname);
		if (!ft_strncmp("__DATA", section->segname, 16) && !ft_strncmp("__bss", section->sectname, 16))
			char_type = 'b';
		// else if (!ft_strncmp("__DATA", section->segname, 16) && !ft_strncmp("__common", section->sectname, 16))
		// 	char_type = 'c';
		else if (!ft_strncmp("__TEXT", section->segname, 16) && !ft_strncmp("__text", section->sectname, 16))
			char_type = 't';
		else if (!ft_strncmp("__DATA", section->segname, 16) && !ft_strncmp("__data", section->sectname, 16))
			char_type = 'd';
		else
			char_type = 's';
	}
	else if ((type & N_TYPE) == N_UNDF && value && (type & N_EXT) && n_sect == NO_SECT)
		char_type = 'C';
	else if ((type & N_TYPE) == N_UNDF && n_sect == NO_SECT)
		char_type = 'U';
	if (type & N_EXT)
		char_type = (char)ft_toupper((int)char_type);
	return (char_type);
}
