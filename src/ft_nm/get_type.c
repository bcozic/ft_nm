/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:56:30 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/14 15:14:10 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static char	chr_in_section_64(struct section_64 *section)
{
	if (!ft_strncmp("__DATA", section->segname, 16)
			&& !ft_strncmp("__bss", section->sectname, 16))
		return ('b');
	else if (!ft_strncmp("__TEXT", section->segname, 16)
			&& !ft_strncmp("__text", section->sectname, 16))
		return ('t');
	else if (!ft_strncmp("__DATA", section->segname, 16)
			&& !ft_strncmp("__data", section->sectname, 16))
		return ('d');
	else
		return ('s');
}

static char	chr_in_section_32(struct section *section)
{
	if (!ft_strncmp("__DATA", section->segname, 16)
			&& !ft_strncmp("__bss", section->sectname, 16))
		return ('b');
	else if (!ft_strncmp("__TEXT", section->segname, 16)
			&& !ft_strncmp("__text", section->sectname, 16))
		return ('t');
	else if (!ft_strncmp("__DATA", section->segname, 16)
			&& !ft_strncmp("__data", section->sectname, 16))
		return ('d');
	else
		return ('s');
}

char		get_type_64(uint8_t type, uint8_t n_sect, uint64_t value,
		t_arch_64 *arch)
{
	char				char_type;
	struct section_64	*section;

	section = get_section_64(n_sect, arch->section);
	char_type = '?';
	if ((type & N_TYPE) == N_ABS)
		char_type = 'a';
	else if (section)
		char_type = chr_in_section_64(section);
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

char		get_type_32(uint8_t type, uint8_t n_sect, uint64_t value,
		t_arch_32 *arch)
{
	char				char_type;
	struct section		*section;

	section = get_section_32(n_sect, arch->section);
	char_type = '?';
	if ((type & N_TYPE) == N_ABS)
		char_type = 'a';
	else if (section)
		char_type = chr_in_section_32(section);
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
