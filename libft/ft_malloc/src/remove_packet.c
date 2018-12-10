/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_packet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 10:45:04 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/08 11:32:11 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libmalloc.h"

static void	remove_packet(t_zone *zone, t_mem *packet, t_mem *prec)
{
	if (prec == NULL)
		zone->used_packet = packet->next;
	else
		prec->next = packet->next;
	packet->next = NULL;
	insert_new_element(&(zone->packet), packet);
}

int			chr_allocation(void *ptr, t_zone *zone)
{
	t_mem *current_packet;
	t_mem *previous;

	current_packet = zone->used_packet;
	previous = NULL;
	if (!current_packet)
		return (0);
	while (current_packet)
	{
		if (current_packet->ptr == ptr)
		{
			remove_packet(zone, current_packet, previous);
			return (1);
		}
		previous = current_packet;
		current_packet = current_packet->next;
	}
	return (0);
}
