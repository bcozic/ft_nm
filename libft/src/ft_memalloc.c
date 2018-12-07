/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:38:24 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/07 08:46:19 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*tab;
	size_t	i;

	if (!(tab = ft_malloc(size)))
		return (0);
	i = 0;
	while (i < size)
	{
		*((char *)tab + i) = 0;
		i++;
	}
	return (tab);
}
