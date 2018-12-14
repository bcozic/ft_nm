/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 09:56:17 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/14 20:21:53 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int	check_lc(struct load_command *lc, t_data *data)
{
	if ((size_t)lc + sizeof(struct load_command) > data->end_file)
	{
		free_all_64(&data->arch_64);
		free_all_32(&data->arch_32);
		return (0);
	}
	return (1);
}

void		handle_little_64(void *ptr, t_data *data)
{
	struct load_command	*lc;
	uint32_t			i;

	data->arch_64.ptr = ptr;
	data->arch_64.end_file = data->end_file;
	data->arch_64.header = (struct mach_header_64*)ptr;
	if ((size_t)ptr + data->arch_64.header->sizeofcmds > data->end_file)
		return ;
	lc = (void*)((size_t)data->arch_64.ptr + sizeof(struct mach_header_64));
	i = 0;
	while (i++ < data->arch_64.header->ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
			data->arch_64.symtab = (struct symtab_command*)lc;
		else if (lc->cmd == LC_SEGMENT_64)
			add_segment_little_64((struct segment_command_64*)((void*)lc),
					&data->arch_64);
		lc = (void*)((size_t)lc + lc->cmdsize);
		if (!check_lc(lc, data))
			return ;
	}
	if (data->arch_64.symtab)
		get_symbols_little_64(&data->arch_64);
	free_all_64(&data->arch_64);
}

void		handle_little_32(void *ptr, t_data *data)
{
	struct load_command	*lc;
	uint32_t			i;

	data->arch_32.ptr = ptr;
	data->arch_32.end_file = data->end_file;
	data->arch_32.header = (struct mach_header*)data->arch_32.ptr;
	if ((size_t)ptr + data->arch_32.header->sizeofcmds > data->end_file)
		return ;
	lc = (void*)((size_t)data->arch_32.ptr + sizeof(struct mach_header));
	i = 0;
	while (i++ < data->arch_32.header->ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
			data->arch_32.symtab = (struct symtab_command*)lc;
		else if (lc->cmd == LC_SEGMENT)
			add_segment_little_32((struct segment_command*)((void*)lc),
					&data->arch_32);
		lc = (void*)((size_t)lc + lc->cmdsize);
		if (!check_lc(lc, data))
			return ;
	}
	if (data->arch_32.symtab)
		get_symbols_little_32(&data->arch_32);
	free_all_32(&data->arch_32);
}

void		handle_big_64(void *ptr, t_data *data)
{
	struct load_command	*lc;
	uint32_t			ncmds;

	data->arch_64.ptr = ptr;
	data->arch_64.end_file = data->end_file;
	data->arch_64.header = (struct mach_header_64*)data->arch_64.ptr;
	if ((size_t)ptr + lte_32(data->arch_64.header->sizeofcmds) > data->end_file)
		return ;
	lc = (void*)((size_t)data->arch_64.ptr + sizeof(struct mach_header_64));
	ncmds = lte_32(data->arch_64.header->ncmds);
	while (ncmds--)
	{
		if (lte_32(lc->cmd) == LC_SYMTAB)
			data->arch_64.symtab = (struct symtab_command*)lc;
		else if (lte_32(lc->cmd) == LC_SEGMENT_64)
			add_segment_big_64((struct segment_command_64*)((void*)lc),
					&data->arch_64);
		lc = (void*)((size_t)lc + lte_32(lc->cmdsize));
		if (!check_lc(lc, data))
			return ;
	}
	if (data->arch_64.symtab)
		get_symbols_big_64(&data->arch_64);
	free_all_64(&data->arch_64);
}

void		handle_big_32(void *ptr, t_data *data)
{
	struct load_command	*lc;
	uint32_t			ncmds;

	data->arch_32.ptr = ptr;
	data->arch_32.end_file = data->end_file;
	data->arch_32.header = (struct mach_header*)data->arch_32.ptr;
	if ((size_t)ptr + lte_32(data->arch_32.header->sizeofcmds) > data->end_file)
		return ;
	lc = (void*)((size_t)data->arch_32.ptr + sizeof(struct mach_header));
	ncmds = lte_32(data->arch_32.header->ncmds);
	while (ncmds--)
	{
		if (lte_32(lc->cmd) == LC_SYMTAB)
			data->arch_32.symtab = (struct symtab_command*)lc;
		else if (lte_32(lc->cmd) == LC_SEGMENT)
			add_segment_big_32((struct segment_command*)((void*)lc),
					&data->arch_32);
		lc = (void*)((size_t)lc + lte_32(lc->cmdsize));
		if (!check_lc(lc, data))
			return ;
	}
	if (data->arch_32.symtab)
		get_symbols_big_32(&data->arch_32);
	free_all_32(&data->arch_32);
}
