/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 22:01:16 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/08 11:32:11 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libmalloc.h"

void	*ft_malloc(size_t size)
{
	void	*ptr;

	if (size == 0)
		return (0);
	pthread_mutex_lock(&g_mutex);
	if (g_data == NULL)
		if (!init_data((size_t)getpagesize()))
		{
			pthread_mutex_unlock(&g_mutex);
			return (0);
		}
	if (size <= g_data->pages_size)
		ptr = get_alloc(size, &g_data->tiny, 100);
	else if (size <= g_data->pages_size * 4)
		ptr = get_alloc(size, &g_data->small, 400);
	else
		ptr = get_alloc(size, &g_data->large, 0);
	pthread_mutex_unlock(&g_mutex);
	return (ptr);
}
