/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:38:51 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/14 19:33:01 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

int	ft_nm(void *ptr, t_data *data)
{
	uint32_t			magic_nbr;

	magic_nbr = *(uint32_t*)ptr;
	if (magic_nbr == FAT_MAGIC_64)
		fat_header_little_64(ptr, data);
	else if (magic_nbr == FAT_CIGAM_64)
		fat_header_big_64(ptr, data);
	else if (magic_nbr == FAT_MAGIC)
		fat_header_little_32(ptr, data);
	else if (magic_nbr == FAT_CIGAM)
		fat_header_big_32(ptr, data);
	else if (magic_nbr == MH_MAGIC_64)
		handle_little_64(ptr, data);
	else if (magic_nbr == MH_CIGAM_64)
		handle_big_64(ptr, data);
	else if (magic_nbr == MH_MAGIC)
		handle_little_32(ptr, data);
	else if (magic_nbr == MH_CIGAM)
		handle_big_32(ptr, data);
	else if (!ft_memcmp(ARMAG, ptr, SARMAG))
		handle_ar(data, (char*)ptr + SARMAG, ptr);
	else
		return (0);
	return (1);
}
