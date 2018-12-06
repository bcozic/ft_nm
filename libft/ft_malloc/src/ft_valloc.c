/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 22:02:22 by bcozic            #+#    #+#             */
/*   Updated: 2018/11/21 11:01:22 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libc.h"

static t_mem	*cut_begin_packet(t_mem *packet, void *ptr)
{
	t_mem	*new_packet;

	new_packet = (t_mem*)get_new_struct(sizeof(t_mem));
	new_packet->next = packet->next;
	new_packet->ptr = ptr;
	new_packet->size = ((size_t)packet->ptr + packet->size) - (size_t)ptr;
	packet->next = new_packet;
	packet->size -= new_packet->size;
	return (new_packet);
}

static void		*get_ptr_begin_page(t_mem *packet, size_t size)
{
	void	*ptr;

	ptr = NULL;
	if (packet)
		ptr = (char*)packet->ptr + ((size_t)g_data->pages_size
				- ((size_t)packet->ptr % g_data->pages_size));
	if (!packet || (size_t)packet->ptr + packet->size < (size_t)ptr
			|| (((size_t)packet->ptr + packet->size) - (size_t)ptr) < size)
		ptr = NULL;
	return (ptr);
}

static void		*get_memory_begin_page(t_zone *zone, size_t size,
		size_t nb_page)
{
	t_mem	*previous_packet;
	t_mem	*current_packet;
	void	*ptr;

	current_packet = zone->packet;
	ptr = get_ptr_begin_page(current_packet, size);
	previous_packet = NULL;
	while (!current_packet || !ptr)
	{
		previous_packet = current_packet;
		if (current_packet == NULL)
		{
			if (!(current_packet = get_new_page(zone, nb_page)))
				return (0);
		}
		else
			current_packet = current_packet->next;
		ptr = get_ptr_begin_page(current_packet, size);
	}
	if (current_packet->ptr != ptr)
	{
		previous_packet = current_packet;
		current_packet = cut_begin_packet(current_packet, ptr);
	}
	return (get_memory(zone, previous_packet, current_packet, size));
}

static void		*get_valloc(size_t size, t_zone *zone, size_t nb_page)
{
	size = ((size / zone->size_packet_zone)
			+ (size % zone->size_packet_zone ? 1 : 0))
			* zone->size_packet_zone;
	if (!nb_page)
		nb_page = size / g_data->pages_size;
	if (zone->page == NULL)
		if (!get_new_page(zone, nb_page))
			return (0);
	return (get_memory_begin_page(zone, size, nb_page));
}

void			*ft_valloc(size_t size)
{
	void	*ptr;

	pthread_mutex_lock(&g_mutex);
	if (g_data == NULL)
		if (!init_data((size_t)getpagesize()))
		{
			pthread_mutex_unlock(&g_mutex);
			return (0);
		}
	if (size <= g_data->pages_size)
		ptr = get_valloc(size, &g_data->tiny,
				(g_data->pages_size * 100 / g_data->pages_size));
	else if (size <= g_data->pages_size * 4)
		ptr = get_valloc(size, &g_data->small,
				(g_data->pages_size * 4 * 100 / g_data->pages_size));
	else
		ptr = get_valloc(size, &g_data->large, 0);
	pthread_mutex_unlock(&g_mutex);
	return (ptr);
}
