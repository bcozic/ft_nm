/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnc_packets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:43:54 by bcozic            #+#    #+#             */
/*   Updated: 2018/11/21 10:54:05 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libc.h"

static int	join_ptr(t_mem *mem1, t_mem *mem2)
{
	if ((char*)mem1->ptr + mem1->size == (char*)mem2->ptr)
	{
		mem1->next = mem2->next;
		mem1->size += mem2->size;
		remove_struct(mem2);
		return (1);
	}
	return (0);
}

t_mem		*insert_new_element(t_mem **list_ptr, t_mem *new_ptr)
{
	t_mem	*current_ptr;

	current_ptr = *list_ptr;
	if (!current_ptr || new_ptr->ptr < current_ptr->ptr)
	{
		new_ptr->next = current_ptr;
		if (current_ptr)
			join_ptr(new_ptr, current_ptr);
		*list_ptr = new_ptr;
		return (new_ptr);
	}
	while (current_ptr->next && new_ptr->ptr > current_ptr->next->ptr)
		current_ptr = current_ptr->next;
	new_ptr->next = current_ptr->next;
	current_ptr->next = new_ptr;
	if (join_ptr(current_ptr, new_ptr))
		new_ptr = current_ptr;
	if (current_ptr->next)
		join_ptr(new_ptr, current_ptr->next);
	return (new_ptr);
}
