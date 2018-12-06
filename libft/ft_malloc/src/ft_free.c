/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 22:01:04 by bcozic            #+#    #+#             */
/*   Updated: 2018/11/21 10:56:49 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libc.h"

void		ft_free(void *ptr)
{
	if (!ptr)
		return ;
	pthread_mutex_lock(&g_mutex);
	if (!g_data)
	{
		pthread_mutex_unlock(&g_mutex);
		return ;
	}
	if (chr_allocation(ptr, &g_data->tiny))
	{
		pthread_mutex_unlock(&g_mutex);
		return ;
	}
	if (chr_allocation(ptr, &g_data->small))
	{
		pthread_mutex_unlock(&g_mutex);
		return ;
	}
	if (chr_allocation(ptr, &g_data->large))
	{
		pthread_mutex_unlock(&g_mutex);
		return ;
	}
	pthread_mutex_unlock(&g_mutex);
}
