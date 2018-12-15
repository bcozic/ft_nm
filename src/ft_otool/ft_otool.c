/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_otool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:38:51 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/15 19:01:41 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

int	ft_otool(void *ptr, t_data *data)
{
	if ((size_t)ptr + sizeof(uint32_t) > data->end_file)
		return (0);
	else if (*(uint32_t*)ptr == FAT_MAGIC_64)
		fat_header_little_64(ptr, data);
	else if (*(uint32_t*)ptr == FAT_CIGAM_64)
		fat_header_big_64(ptr, data);
	else if (*(uint32_t*)ptr == FAT_MAGIC)
		fat_header_little_32(ptr, data);
	else if (*(uint32_t*)ptr == FAT_CIGAM)
		fat_header_big_32(ptr, data);
	else if (*(uint32_t*)ptr == MH_MAGIC_64)
		handle_little_64(ptr, data);
	else if (*(uint32_t*)ptr == MH_CIGAM_64)
		handle_big_64(ptr, data);
	else if (*(uint32_t*)ptr == MH_MAGIC)
		handle_little_32(ptr, data);
	else if (*(uint32_t*)ptr == MH_CIGAM)
		handle_big_32(ptr, data);
	else if (!ft_memcmp(ARMAG, ptr, SARMAG))
		handle_ar(data, (char*)ptr + SARMAG, ptr);
	else
		return (0);
	return (1);
}
