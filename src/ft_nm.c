/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:38:51 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/10 16:17:33 by bcozic           ###   ########.fr       */
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

	magic_nbr = *(uint32_t*)ptr;
	if (magic_nbr == FAT_MAGIC_64)
		fat_header_little_64(ptr);
	else if (magic_nbr == FAT_CIGAM_64)
		fat_header_big_64(ptr);
	else if (magic_nbr == FAT_MAGIC)
		fat_header_little_32(ptr);
	else if (magic_nbr == FAT_CIGAM)
		fat_header_big_32(ptr);
	else if (magic_nbr == MH_MAGIC_64)
		handle_little_64(ptr);
	else if (magic_nbr == MH_CIGAM_64)
		handle_big_64(ptr);
	else if (magic_nbr == MH_MAGIC)
		handle_little_32(ptr);
	else if (magic_nbr == MH_CIGAM)
		handle_big_32(ptr);
}
