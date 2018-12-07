/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:38:51 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/07 09:59:08 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	ft_nm(void* ptr)
{
	uint32_t	magic_nbr;

	magic_nbr = *(uint32_t*)ptr;
	if (magic_nbr == MH_MAGIC_64)
	{
		handle_64(ptr);
	}
	else if (magic_nbr == MH_MAGIC)
	{
		handle_32(ptr);
	}
}
