/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_symbols.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 09:58:45 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/15 13:40:26 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	get_symbols_little_64(t_arch_64 *arch)
{
	t_list_sym_64	*current;
	struct nlist_64	*array;
	uint32_t		nsyms;
	char			type;

	array = (void*)((size_t)arch->ptr + arch->symtab->symoff);
	arch->stringtable = (void*)((size_t)arch->ptr + arch->symtab->stroff);
	nsyms = arch->symtab->nsyms;
	if ((size_t)&array[nsyms] > arch->end_file)
		return ;
	while (nsyms--)
		if ((insert_sym_list_little_64(&array[nsyms], arch)) == 0)
			return ;
	current = arch->list_sym;
	while (current)
	{
		type = get_type_64(current->symbol->n_type, current->symbol->n_sect,
				current->symbol->n_value, arch);
		print_symbol_little_64(type, arch, current->symbol);
		current = current->next;
	}
}

void	get_symbols_little_32(t_arch_32 *arch)
{
	t_list_sym_32	*current;
	struct nlist	*array;
	uint32_t		nsyms;
	char			type;

	array = (void*)((size_t)arch->ptr + arch->symtab->symoff);
	arch->stringtable = (void*)((size_t)arch->ptr + arch->symtab->stroff);
	nsyms = arch->symtab->nsyms;
	if ((size_t)&array[nsyms] > arch->end_file)
		return ;
	while (nsyms--)
		if ((insert_sym_list_little_32(&array[nsyms], arch)) == 0)
			return ;
	current = arch->list_sym;
	while (current)
	{
		type = get_type_32(current->symbol->n_type, current->symbol->n_sect,
				current->symbol->n_value, arch);
		print_symbol_little_32(type, arch, current->symbol);
		current = current->next;
	}
}

void	get_symbols_big_64(t_arch_64 *arch)
{
	t_list_sym_64	*current;
	struct nlist_64	*array;
	uint32_t		nsyms;
	char			type;

	array = (void*)((size_t)arch->ptr + lte_32(arch->symtab->symoff));
	arch->stringtable = (void*)((size_t)arch->ptr
			+ lte_32(arch->symtab->stroff));
	nsyms = lte_32(arch->symtab->nsyms);
	if ((size_t)&array[nsyms] > arch->end_file)
		return ;
	while (nsyms--)
		if ((insert_sym_list_big_64(&array[nsyms], arch)) == 0)
			return ;
	current = arch->list_sym;
	while (current)
	{
		type = get_type_64(current->symbol->n_type, current->symbol->n_sect,
				lte_64(current->symbol->n_value), arch);
		print_symbol_big_64(type, arch, current->symbol);
		current = current->next;
	}
}

void	get_symbols_big_32(t_arch_32 *arch)
{
	t_list_sym_32	*current;
	struct nlist	*array;
	uint32_t		nsyms;
	char			type;

	array = (void*)((size_t)arch->ptr + lte_32(arch->symtab->symoff));
	arch->stringtable = (void*)((size_t)arch->ptr
			+ lte_32(arch->symtab->stroff));
	nsyms = lte_32(arch->symtab->nsyms);
	if ((size_t)&array[nsyms] > arch->end_file)
		return ;
	while (nsyms--)
		if ((insert_sym_list_big_32(&array[nsyms], arch)) == 0)
			return ;
	current = arch->list_sym;
	while (current)
	{
		type = get_type_32(current->symbol->n_type, current->symbol->n_sect,
				lte_32(current->symbol->n_value), arch);
		print_symbol_big_32(type, arch, current->symbol);
		current = current->next;
	}
}
