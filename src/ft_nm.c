/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:38:51 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/13 17:59:57 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

int	ft_nm(void *ptr, t_data *data)
{
	uint32_t			magic_nbr;

	if ((size_t)ptr + sizeof(uint32_t) > data->end_file)
	{
		ft_printf("%p %p\n", data->end_file, ptr);
		return (0);
	}
	magic_nbr = *(uint32_t*)ptr;
	if (magic_nbr == FAT_MAGIC_64)
	{
		ft_printf("FAT_MAGIC_64\n");
		// fat_header_little_64(ptr, data);
	}
	else if (magic_nbr == FAT_CIGAM_64)
	{
		ft_printf("FAT_CIGAM_64\n");
		// fat_header_big_64(ptr, data);
	}
	else if (magic_nbr == FAT_MAGIC)
	{
		ft_printf("FAT_MAGIC\n");
		// fat_header_little_32(ptr, data);
	}
	else if (magic_nbr == FAT_CIGAM)
	{
		// ft_printf("FAT_CIGAM\n");
		fat_header_big_32(ptr, data);
	}
	else if (magic_nbr == MH_MAGIC_64)
		handle_little_64(ptr, data);
	else if (magic_nbr == MH_CIGAM_64)
	{
		ft_printf("MH_CIGAM_64\n");
		// handle_big_64(ptr, data);
	}
	else if (magic_nbr == MH_MAGIC)
		handle_little_32(ptr, data);
	else if (magic_nbr == MH_CIGAM)
	{
		// ft_printf("MH_CIGAM\n");
		handle_big_32(ptr, data);
	}
	else if ((size_t)ptr + SARMAG < data->end_file && !ft_memcmp(ARMAG, ptr, SARMAG))
		handle_ar(data, (char*)ptr + SARMAG);
	else
	{
		// for (int i = 0; i < 20; i++)
		// 	ft_printf("%02x ", ((uint8_t*)ptr)[i]);
		// ft_printf("\nELSE\n", *(uint8_t*)ptr, ((uint8_t*)ptr)[1]);
		return (0);
	}
	return (1);
}
