/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_segment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:12:26 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/13 14:03:49 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	add_segment_little_64(struct segment_command_64 *segment,
		t_arch_64 *arch)
{
	t_section_64	*section;
	t_section_64	*current;
	void			*cur_offset;
	uint32_t		i;

	cur_offset = (void*)((size_t)segment + sizeof(struct segment_command_64));
	i = 0;
	current = arch->section;
	while (current && current->next)
		current = current->next;
	while (i++ < segment->nsects)
	{
		section = ft_malloc(sizeof(t_section_64));
		section->section = (struct section_64*)cur_offset;
		section->next = NULL;
		cur_offset = (void*)((size_t)cur_offset + sizeof(struct section_64));
		if (!current)
		{
			arch->section = section;
			current = arch->section;
			continue ;
		}
		current->next = section;
		current = current->next;
	}
}

void	add_segment_little_32(struct segment_command *segment,
		t_arch_32 *arch)
{
	t_section_32	*section;
	t_section_32	*current;
	void			*cur_offset;
	uint32_t		i;

	cur_offset = (void*)((size_t)segment + sizeof(struct segment_command));
	i = 0;
	current = arch->section;
	while (current && current->next)
		current = current->next;
	while (i++ < segment->nsects)
	{
		section = ft_malloc(sizeof(t_section_32));
		section->section = (struct section*)cur_offset;
		section->next = NULL;
		cur_offset = (void*)((size_t)cur_offset + sizeof(struct section));
		if (!current)
		{
			arch->section = section;
			current = arch->section;
			continue ;
		}
		current->next = section;
		current = current->next;
	}
}

void	add_segment_big_64(struct segment_command_64 *segment, t_arch_64 *arch)
{
	t_section_64	*section;
	t_section_64	*current;
	void			*cur_offset;
	uint32_t		nsects;

	cur_offset = (void*)((size_t)segment + sizeof(struct segment_command_64));
	nsects = lte_32(segment->nsects);
	current = arch->section;
	while (current && current->next)
		current = current->next;
	while (nsects--)
	{
		section = ft_malloc(sizeof(t_section_64));
		section->section = (struct section_64*)cur_offset;
		section->next = NULL;
		cur_offset = (void*)((size_t)cur_offset + sizeof(struct section_64));
		if (!current)
		{
			arch->section = section;
			current = arch->section;
			continue ;
		}
		current->next = section;
		current = current->next;
	}
}

void	add_segment_big_32(struct segment_command *segment, t_arch_32 *arch)
{
	t_section_32	*section;
	t_section_32	*current;
	void			*cur_offset;
	uint32_t		nsects;

	cur_offset = (void*)((size_t)segment + sizeof(struct segment_command));
	nsects = lte_32(segment->nsects);
	current = arch->section;
	while (current && current->next)
		current = current->next;
	while (nsects--)
	{
		section = ft_malloc(sizeof(t_section_32));
		section->section = (struct section*)cur_offset;
		section->next = NULL;
		cur_offset = (void*)((size_t)cur_offset + sizeof(struct section));
		if (!current)
		{
			arch->section = section;
			current = arch->section;
			continue ;
		}
		current->next = section;
		current = current->next;
	}
}
