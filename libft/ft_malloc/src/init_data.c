/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 10:57:12 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/08 11:32:11 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libmalloc.h"

t_data			*g_data = NULL;
pthread_mutex_t	g_mutex = PTHREAD_MUTEX_INITIALIZER;

int		init_data(size_t pages_size)
{
	void		*map;

	if (pages_size <= 0)
		return (0);
	map = mmap(NULL, pages_size * 10, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0);
	g_data = (t_data*)map;
	g_data->pages_size = pages_size;
	g_data->tiny.size_packet_zone = TINY_PK;
	g_data->small.size_packet_zone = SMALL_PK;
	g_data->large.size_packet_zone = pages_size;
	g_data->data_page.page = (t_mem*)(void*)((char*)map + sizeof(t_data));
	g_data->data_page.page->ptr = map;
	g_data->data_page.page->size = pages_size * 3;
	g_data->data_page.page->next = NULL;
	g_data->data_page.packet = (t_mem*)(void*)((char*)map + sizeof(t_data)
			+ sizeof(t_mem));
	g_data->data_page.packet->ptr = (char*)map + sizeof(t_data)
			+ sizeof(t_mem) + sizeof(t_mem);
	g_data->data_page.packet->size = (size_t)((char*)map
			- (char*)g_data->data_page.packet->ptr) + (pages_size * 3);
	g_data->data_page.packet->next = NULL;
	g_data->allocate_size = g_data->pages_size;
	getrlimit(RLIMIT_MEMLOCK, &g_data->rlimit_memlock);
	return (1);
}
