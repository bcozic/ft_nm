/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_new_page.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:00:00 by bcozic            #+#    #+#             */
/*   Updated: 2018/11/21 11:00:22 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libc.h"

t_mem	*get_new_page(t_zone *zone, size_t nb_pages)
{
	t_mem	*new_page;
	t_mem	*new_packet;

	if (!(new_page = (t_mem*)get_new_struct(sizeof(t_mem))))
		return (0);
	if (g_data->allocate_size + (g_data->pages_size * nb_pages)
			> g_data->rlimit_memlock.rlim_cur)
		return (0);
	new_page->ptr = mmap(NULL, g_data->pages_size * nb_pages,
			PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	g_data->allocate_size += g_data->pages_size * nb_pages;
	new_page->size = g_data->pages_size * nb_pages;
	new_page->next = NULL;
	if (!(new_packet = (t_mem*)get_new_struct(sizeof(t_mem))))
		return (0);
	new_packet->ptr = new_page->ptr;
	new_page = insert_new_element(&zone->page, new_page);
	new_packet->size = g_data->pages_size * nb_pages;
	new_packet->next = NULL;
	new_packet = insert_new_element(&zone->packet, new_packet);
	return (new_packet);
}
