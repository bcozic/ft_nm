/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:38:51 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/10 12:12:05 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

// static int		split_fat_header(void *ptr, void *begin_fat_arch, int endianness)
// {
// 	struct fat_arch	*fat_arch;

// 	fat_arch = (struct fat_arch*)begin_fat_arch;
// 	ft_printf("%d\n", fat_arch->offset);
// 	if (*(uint32_t*)(void*)((char*)ptr + fat_arch->offset) == MH_MAGIC_64 || *(uint32_t*)(void*)((char*)ptr + fat_arch->offset) == MH_MAGIC)
// 	{
// 		ft_nm((void*)((char*)ptr + fat_arch->offset));
// 		return (1);
// 	}
// 	return (0);
// }

void	ft_nm(void *ptr)
{
	uint32_t			magic_nbr;
	t_data_64			*data_64;
	t_data_32			*data_32;
	int					endianness;

	magic_nbr = *(uint32_t*)ptr;
	endianness = get_endianness(magic_nbr);
	if (endianness == IS_BIG_ENDIAN)
		magic_nbr = little_endian_32(magic_nbr);
	if (magic_nbr == FAT_MAGIC_64)
		fat_header_64(ptr, endianness);
	else if (magic_nbr == FAT_MAGIC)
		fat_header_32(ptr, endianness);
	else if (magic_nbr == MH_MAGIC_64)
	{
		data_64 = ft_calloc(sizeof(t_data_64), 1);
		data_64->ptr = ptr;
		handle_64(data_64, endianness);
		free_all_64(data_64);
	}
	else if (magic_nbr == MH_MAGIC)
	{
		data_32 = ft_calloc(sizeof(t_data_32), 1);
		data_32->ptr = ptr;
		handle_32(data_32, endianness);
		free_all_32(data_32);
	}
}
