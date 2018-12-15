/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_segment_64.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:19:48 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/15 14:31:30 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static t_section_64	*new_segment(void *offset, t_arch_64 *arch,
		t_section_64 *current)
{
	t_section_64	*section;

	section = ft_malloc(sizeof(t_section_64));
	section->section = (struct section_64*)offset;
	section->next = NULL;
	if (!current)
	{
		arch->section = section;
		current = arch->section;
		return (current);
	}
	current->next = section;
	return (current->next);
}

int					add_segment_little_64(
		struct segment_command_64 *segment, t_arch_64 *arch)
{
	t_section_64	*current;
	void			*cur_offset;
	uint32_t		nsects;

	cur_offset = (void*)((size_t)segment + sizeof(struct segment_command_64));
	nsects = segment->nsects;
	if ((size_t)cur_offset + (nsects * sizeof(struct section)) > arch->end_file)
		return (0);
	current = arch->section;
	while (current && current->next)
		current = current->next;
	while (nsects--)
	{
		current = new_segment(cur_offset, arch, current);
		cur_offset = (void*)((size_t)cur_offset + sizeof(struct section_64));
	}
	return (1);
}

int					add_segment_big_64(
		struct segment_command_64 *segment, t_arch_64 *arch)
{
	t_section_64	*current;
	void			*cur_offset;
	uint32_t		nsects;

	cur_offset = (void*)((size_t)segment + sizeof(struct segment_command_64));
	nsects = lte_32(segment->nsects);
	if ((size_t)cur_offset + (nsects * sizeof(struct section)) > arch->end_file)
		return (0);
	current = arch->section;
	while (current && current->next)
		current = current->next;
	while (nsects--)
	{
		current = new_segment(cur_offset, arch, current);
		cur_offset = (void*)((size_t)cur_offset + sizeof(struct section_64));
	}
	return (1);
}
