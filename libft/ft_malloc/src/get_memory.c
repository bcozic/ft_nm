/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_memory.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:02:40 by bcozic            #+#    #+#             */
/*   Updated: 2018/11/21 11:02:50 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libc.h"

static void		add_used_packet(t_zone *zone, t_mem *packet)
{
	packet->next = zone->used_packet;
	zone->used_packet = packet;
}

void			*get_memory(t_zone *zone, t_mem *previous, t_mem *packet,
		size_t size)
{
	if (packet->size > size)
		if (!(cut_end_packet(packet, size)))
			return (0);
	if (previous == NULL)
		zone->packet = packet->next;
	else
		previous->next = packet->next;
	add_used_packet(zone, packet);
	return (packet->ptr);
}
