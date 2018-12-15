/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_segment_32.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 14:27:42 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/15 17:31:54 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static t_section_32	*new_segment(void *offset, t_arch_32 *arch,
		t_section_32 *current)
{
	t_section_32	*section;

	section = ft_malloc(sizeof(t_section_32));
	section->section = (struct section*)offset;
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

int					add_segment_little_32(struct segment_command *segment,
		t_arch_32 *arch)
{
	t_section_32	*current;
	void			*cur_offset;
	uint32_t		nsects;

	cur_offset = (void*)((size_t)segment + sizeof(struct segment_command));
	nsects = segment->nsects;
	if ((size_t)cur_offset + (nsects * sizeof(struct section)) > arch->end_file)
		return (0);
	current = arch->section;
	while (current && current->next)
		current = current->next;
	while (nsects--)
	{
		current = new_segment(cur_offset, arch, current);
		cur_offset = (void*)((size_t)cur_offset + sizeof(struct section));
	}
	return (1);
}

int					add_segment_big_32(struct segment_command *segment,
		t_arch_32 *arch)
{
	t_section_32	*current;
	void			*cur_offset;
	uint32_t		nsects;

	cur_offset = (void*)((size_t)segment + sizeof(struct segment_command));
	nsects = lte_32(segment->nsects);
	if ((size_t)cur_offset + (nsects * sizeof(struct section)) > arch->end_file)
		return (0);
	current = arch->section;
	while (current && current->next)
		current = current->next;
	while (nsects--)
	{
		current = new_segment(cur_offset, arch, current);
		cur_offset = (void*)((size_t)cur_offset + sizeof(struct section));
	}
	return (1);
}
