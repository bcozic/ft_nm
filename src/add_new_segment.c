/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_segment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:04:03 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/09 15:01:07 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static void	*add_first_segment_64(t_data_64 *data, void *current_offset)
{
	t_section_64	*section;

	section = ft_malloc(sizeof(t_section_64));
	section->section = (struct section_64*)current_offset;
	section->next = NULL;
	data->section = section;
	return ((void *)((size_t)current_offset + sizeof(struct section_64)));
}

void	add_new_segment_64(struct segment_command_64 *segment, t_data_64 *data)
{
	t_section_64	*section;
	t_section_64	*current;
	void		*current_offset;
	uint32_t	i;

	if (segment->nsects == 0)
		return ;
	current_offset = (void*)((size_t)segment + sizeof(struct segment_command_64));
	i = 0;
	if (segment->nsects && !data->section)
	{
		current_offset = add_first_segment_64(data, current_offset);
		i++;
	}
	current = data->section;
	while (current->next)
		current = current->next;
	while (i++ < segment->nsects)
	{
		section = ft_malloc(sizeof(t_section_64));
		section->section = (struct section_64*)current_offset;
		section->next = NULL;
		current->next = section;
		current = section;
		current_offset = (void*)((size_t)current_offset + sizeof(struct section_64));
	}
}

static void	*add_first_segment_32(t_data_32 *data, void *current_offset)
{
	t_section_32	*section;

	section = ft_malloc(sizeof(t_section_32));
	section->section = (struct section*)current_offset;
	section->next = NULL;
	data->section = section;
	return ((void *)((size_t)current_offset + sizeof(struct section)));
}

void	add_new_segment_32(struct segment_command *segment, t_data_32 *data)
{
	t_section_32	*section;
	t_section_32	*current;
	void			*current_offset;
	uint32_t		i;

	current_offset = (void*)((size_t)segment + sizeof(struct segment_command));
	i = 0;
	if (segment->nsects && !data->section)
	{
		current_offset = add_first_segment_32(data, current_offset);
		i++;
	}
	current = data->section;
	while (current->next)
		current = current->next;
	while (i++ < segment->nsects)
	{
		section = ft_malloc(sizeof(t_section_32));
		section->section = (struct section*)current_offset;
		section->next = NULL;
		current->next = section;
		current = section;
		current_offset = (void*)((size_t)current_offset + sizeof(struct section));
	}
}
