/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_packet.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 10:59:04 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/08 11:32:11 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libmalloc.h"

t_mem			*find_packet(void *ptr, t_zone *zone)
{
	t_mem	*current_packet;

	current_packet = zone->used_packet;
	if (!current_packet)
		return (NULL);
	while (current_packet)
	{
		if (current_packet->ptr == ptr)
		{
			return (current_packet);
		}
		current_packet = current_packet->next;
	}
	return (NULL);
}
