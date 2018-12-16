/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_section.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 18:20:25 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/16 14:45:25 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

int	get_section_little_64(struct segment_command_64 *segment, t_data *data)
{
	void				*cur_offset;
	struct section_64	*section;
	uint32_t			nsects;

	cur_offset = (void*)((size_t)segment + sizeof(struct segment_command_64));
	nsects = segment->nsects;
	if ((size_t)cur_offset + (nsects * sizeof(struct section)) > data->end_file)
		return (0);
	while (nsects--)
	{
		section = (struct section_64*)cur_offset;
		if (!ft_strncmp("__TEXT", section->segname, 16)
				&& !ft_strncmp("__text", section->sectname, 16))
			print_section_little_64(section->offset + (uint8_t*)data->ptr,
					section->addr, data, section->size);
		cur_offset = (void*)((size_t)cur_offset + sizeof(struct section_64));
	}
	return (1);
}

int	get_section_little_32(struct segment_command *segment, t_data *data)
{
	void			*cur_offset;
	struct section	*section;
	uint32_t		nsects;

	cur_offset = (void*)((size_t)segment + sizeof(struct segment_command));
	nsects = segment->nsects;
	if ((size_t)cur_offset + (nsects * sizeof(struct section)) > data->end_file)
		return (0);
	while (nsects--)
	{
		section = (struct section*)cur_offset;
		if (!ft_strncmp("__TEXT", section->segname, 16)
				&& !ft_strncmp("__text", section->sectname, 16))
			print_section_little_32(section->offset + (uint8_t*)data->ptr,
					section->addr, data, section->size);
		cur_offset = (void*)((size_t)cur_offset + sizeof(struct section));
	}
	return (1);
}

int	get_section_big_64(struct segment_command_64 *segment, t_data *data)
{
	void				*cur_offset;
	struct section_64	*section;
	uint32_t			nsects;

	cur_offset = (void*)((size_t)segment + sizeof(struct segment_command_64));
	nsects = lte_32(segment->nsects);
	if ((size_t)cur_offset + (nsects * sizeof(struct section)) > data->end_file)
		return (0);
	while (nsects--)
	{
		section = (struct section_64*)cur_offset;
		if (!ft_strncmp("__TEXT", section->segname, 16)
				&& !ft_strncmp("__text", section->sectname, 16))
			print_section_big_64(lte_32(section->offset) + (uint8_t*)data->ptr,
					lte_64(section->addr), data, lte_64(section->size));
		cur_offset = (void*)((size_t)cur_offset + sizeof(struct section_64));
	}
	return (1);
}

int	get_section_big_32(struct segment_command *segment, t_data *data)
{
	void			*cur_offset;
	struct section	*section;
	uint32_t		nsects;

	cur_offset = (void*)((size_t)segment + sizeof(struct segment_command));
	nsects = lte_32(segment->nsects);
	if ((size_t)cur_offset + (nsects * sizeof(struct section)) > data->end_file)
		return (0);
	while (nsects--)
	{
		section = (struct section*)cur_offset;
		if (!ft_strncmp("__TEXT", section->segname, 16)
				&& !ft_strncmp("__text", section->sectname, 16))
			print_section_big_32(lte_32(section->offset) + (uint8_t*)data->ptr,
					lte_32(section->addr), data, lte_32(section->size));
		cur_offset = (void*)((size_t)cur_offset + sizeof(struct section));
	}
	return (1);
}
