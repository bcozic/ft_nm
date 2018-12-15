/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 09:56:17 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/15 18:43:18 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

void		handle_little_64(void *ptr, t_data *data)
{
	struct load_command		*lc;
	struct mach_header_64	*header;
	uint32_t				i;

	data->ptr = ptr;
	header = (struct mach_header_64*)ptr;
	if ((size_t)ptr + header->sizeofcmds > data->end_file)
		return ;
	lc = (void*)((size_t)ptr + sizeof(struct mach_header_64));
	i = 0;
	while (i++ < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT_64)
			if (!get_section_little_64((struct segment_command_64*)((void*)lc),
					data))
				return ;
		lc = (void*)((size_t)lc + lc->cmdsize);
		if ((size_t)lc + sizeof(struct load_command) > data->end_file)
			return ;
	}
}

void		handle_little_32(void *ptr, t_data *data)
{
	struct load_command	*lc;
	struct mach_header	*header;
	uint32_t			i;

	data->ptr = ptr;
	header = (struct mach_header*) ptr;
	if ((size_t)ptr +  header->sizeofcmds > data->end_file)
		return ;
	lc = (void*)((size_t)ptr + sizeof(struct mach_header));
	i = 0;
	while (i++ < header->ncmds)
	{
		if (lc->cmd == LC_SEGMENT)
			if (!get_section_little_32((struct segment_command*)((void*)lc),
					data))
				return ;
		lc = (void*)((size_t)lc + lc->cmdsize);
		if ((size_t)lc + sizeof(struct load_command) > data->end_file)
			return ;
	}
}

void		handle_big_64(void *ptr, t_data *data)
{
	struct load_command		*lc;
	struct mach_header_64	*header;
	uint32_t				ncmds;

	data->ptr = ptr;
	header = (struct mach_header_64*)ptr;
	if ((size_t)ptr + lte_32(header->sizeofcmds) > data->end_file)
		return ;
	lc = (void*)((size_t)ptr + sizeof(struct mach_header_64));
	ncmds = lte_32(header->ncmds);
	while (ncmds--)
	{
		if (lte_32(lc->cmd) == LC_SEGMENT_64)
			if (!get_section_big_64((struct segment_command_64*)((void*)lc),
					data))
				return ;
		lc = (void*)((size_t)lc + lte_32(lc->cmdsize));
		if ((size_t)lc + sizeof(struct load_command) > data->end_file)
			return ;
	}
}

void		handle_big_32(void *ptr, t_data *data)
{
	struct load_command	*lc;
	struct mach_header	*header;
	uint32_t			ncmds;

	header = (struct mach_header*)ptr;
	if ((size_t)ptr + lte_32(header->sizeofcmds) > data->end_file)
		return ;
	lc = (void*)((size_t)ptr + sizeof(struct mach_header));
	ncmds = lte_32(header->ncmds);
	while (ncmds--)
	{
		if (lte_32(lc->cmd) == LC_SEGMENT)
			if (!get_section_big_32((struct segment_command*)((void*)lc),
					data))
				return ;
		lc = (void*)((size_t)lc + lte_32(lc->cmdsize));
		if ((size_t)lc + sizeof(struct load_command) > data->end_file)
			return ;
	}
}
