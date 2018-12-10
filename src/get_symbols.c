/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_symbols.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 09:58:45 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/10 16:30:01 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	get_symbols_little_64(t_data_64 *data)
{
	t_list_sym_64	*current;
	struct nlist_64	*array;
	uint32_t		nsyms;
	char			type;

	array = (void*)((size_t)data->ptr + data->symtab->symoff);
	data->stringtable = (void*)((size_t)data->ptr + data->symtab->stroff);
	nsyms = data->symtab->nsyms;
	while (nsyms--)
		if ((insert_sym_list_little_64(&array[nsyms], data)) == 0)
			return ;
	current = data->list_sym;
	while (current)
	{
		type = get_type_64(current->symbol->n_type, current->symbol->n_sect,
				current->symbol->n_value, data);
		if (current->symbol->n_value)
			ft_printf("%016zx %c %s\n", current->symbol->n_value, type,
					data->stringtable + current->symbol->n_un.n_strx);
		else
			ft_printf("                 %c %s\n", type, data->stringtable
					+ current->symbol->n_un.n_strx);
		current = current->next;
	}
}

void	get_symbols_little_32(t_data_32 *data)
{
	t_list_sym_32	*current;
	struct nlist	*array;
	uint32_t		nsyms;
	char			type;

	array = (void*)((size_t)data->ptr + data->symtab->symoff);
	data->stringtable = (void*)((size_t)data->ptr + data->symtab->stroff);
	nsyms = data->symtab->nsyms;
	while (nsyms--)
		if ((insert_sym_list_little_32(&array[nsyms], data)) == 0)
			return ;
	current = data->list_sym;
	while (current)
	{
		type = get_type_32(current->symbol->n_type, current->symbol->n_sect,
				current->symbol->n_value, data);
		if (current->symbol->n_value)
			ft_printf("%016zx %c %s\n", current->symbol->n_value, type,
					data->stringtable + current->symbol->n_un.n_strx);
		else
			ft_printf("                 %c %s\n", type, data->stringtable
					+ current->symbol->n_un.n_strx);
		current = current->next;
	}
}

void	get_symbols_big_64(t_data_64 *data)
{
	t_list_sym_64	*current;
	struct nlist_64	*array;
	uint32_t		nsyms;
	char			type;

	array = (void*)((size_t)data->ptr + lte_32(data->symtab->symoff));
	data->stringtable = (void*)((size_t)data->ptr
			+ lte_32(data->symtab->stroff));
	nsyms = lte_32(data->symtab->nsyms);
	while (nsyms--)
		if ((insert_sym_list_big_64(&array[nsyms], data)) == 0)
			return ;
	current = data->list_sym;
	while (current)
	{
		type = get_type_64(current->symbol->n_type, current->symbol->n_sect,
				lte_64(current->symbol->n_value), data);
		if (lte_64(current->symbol->n_value))
			ft_printf("%016zx %c %s\n", lte_64(current->symbol->n_value), type,
					data->stringtable + lte_32(current->symbol->n_un.n_strx));
		else
			ft_printf("                 %c %s\n", type, data->stringtable
					+ lte_32(current->symbol->n_un.n_strx));
		current = current->next;
	}
}

void	get_symbols_big_32(t_data_32 *data)
{
	t_list_sym_32	*current;
	struct nlist	*array;
	uint32_t		nsyms;
	char			type;

	array = (void*)((size_t)data->ptr + lte_32(data->symtab->symoff));
	data->stringtable = (void*)((size_t)data->ptr
			+ lte_32(data->symtab->stroff));
	nsyms = lte_32(data->symtab->nsyms);
	while (nsyms--)
		if ((insert_sym_list_big_32(&array[nsyms], data)) == 0)
			return ;
	current = data->list_sym;
	while (current)
	{
		type = get_type_32(current->symbol->n_type, current->symbol->n_sect,
				lte_32(current->symbol->n_value), data);
		if (lte_32(current->symbol->n_value))
			ft_printf("%016zx %c %s\n", lte_32(current->symbol->n_value), type,
					data->stringtable + lte_32(current->symbol->n_un.n_strx));
		else
			ft_printf("                 %c %s\n", type, data->stringtable
					+ lte_32(current->symbol->n_un.n_strx));
		current = current->next;
	}
}
