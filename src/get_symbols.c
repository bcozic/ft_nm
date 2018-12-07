/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_symbols.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 09:58:45 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/07 10:02:56 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	get_symbols(struct symtab_command *sym, void* ptr)
{
	char			*stringtable;
	struct nlist_64	*array;
	uint32_t			i;

	array = (void*)((size_t)ptr + sym->symoff);
	stringtable = (void*)((size_t)ptr + sym->stroff);
	i = 0;
	while (i++ < sym->nsyms)
	{
		// ;
		// if ((((uint8_t)(stringtable + array[i].n_type) & N_TYPE) == N_INDR || ((uint8_t)(stringtable + array[i].n_type) & N_EXT)) && *(stringtable + array[i].n_un.n_strx))
		// if ((((uint8_t)(stringtable + array[i].n_type) & N_TYPE) == N_INDR || ((uint8_t)(stringtable + array[i].n_type) & N_EXT)) && ((uint8_t)(stringtable + array[i].n_type) & N_EXT) && *(stringtable + array[i].n_un.n_strx))// for external fnct, nm -g
			ft_printf("0x%02x %s\n", (uint8_t)(stringtable + array[i].n_type), stringtable + array[i].n_un.n_strx);
			// get_
	}
}
