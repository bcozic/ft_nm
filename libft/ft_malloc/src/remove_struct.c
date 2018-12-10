/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 10:42:44 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/08 11:32:11 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libmalloc.h"

void			remove_struct(t_mem *packet)
{
	packet->next = g_data->data_page.packet;
	packet->size = sizeof(t_mem);
	packet->ptr = packet;
	g_data->data_page.packet = packet;
}
