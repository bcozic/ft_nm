/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_end_packet.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 10:48:27 by bcozic            #+#    #+#             */
/*   Updated: 2018/11/21 10:48:37 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libc.h"

int			cut_end_packet(t_mem *packet, size_t size)
{
	t_mem	*new_packet;

	if (!(new_packet = (t_mem*)get_new_struct(sizeof(t_mem))))
		return (0);
	new_packet->next = packet->next;
	packet->next = new_packet;
	new_packet->ptr = (char*)packet->ptr + size;
	new_packet->size = packet->size - size;
	packet->size = size;
	return (1);
}
