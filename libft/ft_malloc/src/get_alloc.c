/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_alloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 04:11:20 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/08 11:32:11 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libmalloc.h"

void	*get_alloc(size_t size, t_zone *zone, size_t nb_page)
{
	t_mem	*previous_packet;
	t_mem	*current_packet;

	size = ((size / zone->size_packet_zone)
			+ (size % zone->size_packet_zone ? 1 : 0))
			* zone->size_packet_zone;
	if (!nb_page)
		nb_page = size / g_data->pages_size;
	if (zone->page == NULL)
		if (!get_new_page(zone, nb_page))
			return (0);
	current_packet = zone->packet;
	previous_packet = NULL;
	while (!current_packet || current_packet->size < size)
	{
		previous_packet = current_packet;
		if (current_packet == NULL)
		{
			if (!(current_packet = get_new_page(zone, nb_page)))
				return (0);
		}
		else
			current_packet = current_packet->next;
	}
	return (get_memory(zone, previous_packet, current_packet, size));
}
