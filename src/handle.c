/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 09:56:17 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/07 09:59:34 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	handle_64(void *ptr)
{
	uint32_t				nb_cmds;
	struct mach_header_64	*header;
	struct load_command		*lc;
	struct symtab_command	*sym;
	uint32_t				i;

	header = (struct mach_header_64*)ptr;
	nb_cmds = header->ncmds;
	lc = (void*)((size_t)ptr + sizeof(struct mach_header_64));
	i = 0;
	while (i++ < nb_cmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command*)lc;
			get_symbols(sym, ptr);
			break;
		}
		lc = (void*)((size_t)lc + lc->cmdsize);
	}
}

void	handle_32(void *ptr)
{
	uint32_t				nb_cmds;
	struct mach_header	*header;
	struct load_command		*lc;
	struct symtab_command	*sym;
	uint32_t				i;

	header = (struct mach_header*)ptr;
	nb_cmds = header->ncmds;
	lc = (void*)((size_t)ptr + sizeof(struct mach_header));
	i = 0;
	while (i++ < nb_cmds)
	{
		if (lc->cmd == LC_SYMTAB)
		{
			sym = (struct symtab_command*)lc;
			get_symbols(sym, ptr);
			break;
		}
		lc = (void*)((size_t)lc + lc->cmdsize);
	}
}
