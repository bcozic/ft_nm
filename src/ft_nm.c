/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:38:51 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/07 08:30:00 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static void	print_output(uint32_t nsym, uint32_t symoff, uint32_t stroff, void* ptr)
{
	char			*stringtable;
	struct nlist_64	*array;
	uint32_t			i;

	array = (void*)((size_t)ptr + symoff);
	stringtable = (void*)((size_t)ptr + stroff);
	i = 0;
	while (i++ < nsym)
	{
		// ;
		ft_printf("%s\n", stringtable + array[i].n_un.n_strx);
	}
}

static void	handle_64(void *ptr)
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
			ft_printf("nb sym %d cmd size %d symoff %d stroff %d\n", sym->nsyms, lc->cmdsize, sym->symoff, sym->stroff);
			print_output(sym->nsyms, sym->symoff, sym->stroff, ptr);
			break;
		}
		lc = (void*)((size_t)lc + lc->cmdsize);
	}
}

void	ft_nm(void* ptr)
{
	uint32_t	magic_nbr;

	magic_nbr = *(uint32_t*)ptr;
	if (magic_nbr == MH_MAGIC_64)
	{
		handle_64(ptr);
	}
}
