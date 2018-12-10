/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 09:56:17 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/10 14:36:46 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	handle_little_64(void *ptr)
{
	t_data_64			*data;
	struct load_command	*lc;
	uint32_t			i;

	data = ft_calloc(sizeof(t_data_64), 1);
	data->ptr = ptr;
	data->header = (struct mach_header_64*)data->ptr;
	lc = (void*)((size_t)data->ptr + sizeof(struct mach_header_64));
	i = 0;
	while (i++ < data->header->ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
			data->symtab = (struct symtab_command*)lc;
		else if (lc->cmd == LC_SEGMENT_64)
			add_segment_little_64((struct segment_command_64*)((void*)lc),
					data);
		lc = (void*)((size_t)lc + lc->cmdsize);
	}
	get_symbols_little_64(data);
	free_all_64(data);
}

void	handle_little_32(void *ptr)
{
	t_data_32			*data;
	struct load_command	*lc;
	uint32_t			i;

	data = ft_calloc(sizeof(t_data_32), 1);
	data->ptr = ptr;
	data->header = (struct mach_header*)data->ptr;
	lc = (void*)((size_t)data->ptr + sizeof(struct mach_header));
	i = 0;
	while (i++ < data->header->ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
			data->symtab = (struct symtab_command*)lc;
		else if (lc->cmd == LC_SEGMENT)
			add_segment_little_32((struct segment_command*)((void*)lc),
					data);
		lc = (void*)((size_t)lc + lc->cmdsize);
	}
	get_symbols_little_32(data);
	free_all_32(data);
}

void	handle_big_64(void *ptr)
{
	t_data_64			*data;
	struct load_command	*lc;
	uint32_t			ncmds;
	uint32_t			lc_cmd;
	uint32_t			lc_cmdsize;

	data = ft_calloc(sizeof(t_data_64), 1);
	data->ptr = ptr;
	data->header = (struct mach_header_64*)data->ptr;
	lc = (void*)((size_t)data->ptr + sizeof(struct mach_header_64));
	ncmds = lte_32(data->header->ncmds);
	while (ncmds--)
	{
		lc_cmd = lte_32(lc->cmd);
		if (lc_cmd == LC_SYMTAB)
			data->symtab = (struct symtab_command*)lc;
		else if (lc_cmd == LC_SEGMENT_64)
			add_segment_big_64((struct segment_command_64*)((void*)lc),
					data);
		lc_cmdsize = lte_32(lc->cmdsize);
		lc = (void*)((size_t)lc + lc_cmdsize);
	}
	get_symbols_big_64(data);
	free_all_64(data);
}

void	handle_big_32(void *ptr)
{
	t_data_32			*data;
	struct load_command	*lc;
	uint32_t			ncmds;
	uint32_t			lc_cmd;
	uint32_t			lc_cmdsize;

	data = ft_calloc(sizeof(t_data_32), 1);
	data->ptr = ptr;
	data->header = (struct mach_header*)data->ptr;
	lc = (void*)((size_t)data->ptr + sizeof(struct mach_header));
	ncmds = lte_32(data->header->ncmds);
	while (ncmds--)
	{
		lc_cmd = lte_32(lc->cmd);
		if (lc_cmd == LC_SYMTAB)
			data->symtab = (struct symtab_command*)lc;
		else if (lc_cmd == LC_SEGMENT)
			add_segment_big_32((struct segment_command*)((void*)lc), data);
		lc_cmdsize = lte_32(lc->cmdsize);
		lc = (void*)((size_t)lc + lc_cmdsize);
	}
	get_symbols_big_32(data);
	free_all_32(data);
}
