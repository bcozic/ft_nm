/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 09:56:17 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/10 12:28:16 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	handle_64(t_data_64 *data, int endianness)
{
	struct load_command	*lc;
	uint32_t			i;

	data->header = (struct mach_header_64*)data->ptr;
	data->endianness = endianness;
	lc = (void*)((size_t)data->ptr + sizeof(struct mach_header_64));
	i = 0;
	while (i++ < data->header->ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
			data->symtab = (struct symtab_command*)lc;
		else if (lc->cmd == LC_SEGMENT_64)
			add_new_segment_64((struct segment_command_64*)((void*)lc), data);
		lc = (void*)((size_t)lc + lc->cmdsize);
	}
	get_symbols_64(data);
}

void	handle_32(t_data_32 *data, int endianness)
{
	struct load_command	*lc;
	uint32_t			i;

	data->header = (struct mach_header*)data->ptr;
	data->endianness = endianness;
	lc = (void*)((size_t)data->ptr + sizeof(struct mach_header));
	i = 0;
	while (i++ < data->header->ncmds)
	{
		if (lc->cmd == LC_SYMTAB)
			data->symtab = (struct symtab_command*)lc;
		else if (lc->cmd == LC_SEGMENT)
			add_new_segment_32((struct segment_command*)((void*)lc), data);
		lc = (void*)((size_t)lc + lc->cmdsize);
	}
	get_symbols_32(data);
}
