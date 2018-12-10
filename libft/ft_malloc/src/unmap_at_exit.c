/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unmap_at_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 10:56:32 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/08 11:32:11 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libmalloc.h"

static void	remove_all_page(t_mem *page)
{
	if (!page)
		return ;
	remove_all_page(page->next);
	munmap(page->ptr, page->size);
}

static void	check_fogotten_free(void)
{
	t_mem	*current;
	size_t	size;

	size = 0;
	current = g_data->tiny.used_packet;
	while (current)
	{
		size += current->size;
		current = current->next;
	}
	current = g_data->small.used_packet;
	while (current)
	{
		size += current->size;
		current = current->next;
	}
	current = g_data->large.used_packet;
	while (current)
	{
		size += current->size;
		current = current->next;
	}
}

void		unmap_at_exit(void)
{
	if (!g_data || !g_data->pages_size)
		return ;
	check_fogotten_free();
	remove_all_page(g_data->tiny.page);
	remove_all_page(g_data->small.page);
	remove_all_page(g_data->large.page);
	remove_all_page(g_data->data_page.page);
}
