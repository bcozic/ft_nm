/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 22:00:48 by bcozic            #+#    #+#             */
/*   Updated: 2018/11/16 22:00:55 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_libc.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = ft_malloc(count * size);
	ft_bzero(ret, count * size);
	return (ret);
}
