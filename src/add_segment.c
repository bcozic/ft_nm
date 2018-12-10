/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_segment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:12:26 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/10 14:29:29 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	add_segment_little_64(struct segment_command_64 *segment,
		t_data_64 *data)
{
	t_section_64	*section;
	t_section_64	*current;
	void			*cur_offset;
	uint32_t		i;

	cur_offset = (void*)((size_t)segment + sizeof(struct segment_command_64));
	i = 0;
	current = data->section;
	while (current && current->next)
		current = current->next;
	while (i++ < segment->nsects)
	{
		section = ft_malloc(sizeof(t_section_64));
		section->section = (struct section_64*)cur_offset;
		section->next = NULL;
		if (!current)
		{
			data->section = section;
			current = data->section;
			continue ;
		}
		current->next = section;
		current = section;
		cur_offset = (void*)((size_t)cur_offset + sizeof(struct section_64));
	}
}

void	add_segment_little_32(struct segment_command *segment,
		t_data_32 *data)
{
	t_section_32	*section;
	t_section_32	*current;
	void			*cur_offset;
	uint32_t		i;

	cur_offset = (void*)((size_t)segment + sizeof(struct segment_command));
	i = 0;
	current = data->section;
	while (current && current->next)
		current = current->next;
	while (i++ < segment->nsects)
	{
		section = ft_malloc(sizeof(t_section_32));
		section->section = (struct section*)cur_offset;
		section->next = NULL;
		if (!current)
		{
			data->section = section;
			current = data->section;
			continue ;
		}
		current->next = section;
		current = section;
		cur_offset = (void*)((size_t)cur_offset + sizeof(struct section));
	}
}

void	add_segment_big_64(struct segment_command_64 *segment, t_data_64 *data)
{
	t_section_64	*section;
	t_section_64	*current;
	void			*cur_offset;
	uint32_t		nsects;

	cur_offset = (void*)((size_t)segment + sizeof(struct segment_command_64));
	nsects = lte_32(segment->nsects);
	current = data->section;
	while (current && current->next)
		current = current->next;
	while (nsects--)
	{
		section = ft_malloc(sizeof(t_section_64));
		section->section = (struct section_64*)cur_offset;
		section->next = NULL;
		if (!current)
		{
			data->section = section;
			current = data->section;
			continue ;
		}
		current->next = section;
		current = section;
		cur_offset = (void*)((size_t)cur_offset + sizeof(struct section_64));
	}
}

void	add_segment_big_32(struct segment_command *segment, t_data_32 *data)
{
	t_section_32	*section;
	t_section_32	*current;
	void			*cur_offset;
	uint32_t		nsects;

	cur_offset = (void*)((size_t)segment + sizeof(struct segment_command));
	nsects = lte_32(segment->nsects);
	current = data->section;
	while (current && current->next)
		current = current->next;
	while (nsects--)
	{
		section = ft_malloc(sizeof(t_section_32));
		section->section = (struct section*)cur_offset;
		section->next = NULL;
		if (!current)
		{
			data->section = section;
			current = data->section;
			continue ;
		}
		current->next = section;
		current = section;
		cur_offset = (void*)((size_t)cur_offset + sizeof(struct section));
	}
}
