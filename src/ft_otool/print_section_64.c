/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_section_64.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 14:18:33 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/16 14:33:35 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static void	print_one_by_one(uint8_t *ptr, int count, uint64_t addr)
{
	ft_printf("%016zx\t", addr);
	while (count--)
	{
		ft_printf("%02x ", *ptr);
		ptr = ptr + 1;
	}
	ft_printf("\n");
}

void		print_section_little_64(uint8_t *ptr, uint64_t addr, t_data *data,
		uint64_t size)
{
	uint64_t	i;

	if ((uint64_t)ptr + size > data->end_file)
		return ;
	ft_printf("Contents of (__TEXT,__text) section\n");
	if (data->ppc == 1)
	{
		print_ppc_little_64((void*)((char*)data->ptr + addr), addr, data, size);
		return ;
	}
	i = 0;
	while (i < size)
	{
		if (i + 16 > size)
		{
			print_one_by_one(ptr, (int)(size - i), addr + i);
			return ;
		}
		ft_printf("%016zx\t%02x %02x %02x %02x %02x %02x %02x %02x %02x %02x "
				"%02x %02x %02x %02x %02x %02x \n", addr + (uint32_t)i, ptr[0],
				ptr[1], ptr[2], ptr[3], ptr[4], ptr[5], ptr[6], ptr[7], ptr[8],
				ptr[9], ptr[10], ptr[11], ptr[12], ptr[13], ptr[14], ptr[15]);
		i += 16;
		ptr = ptr + 16;
	}
}

void		print_section_big_64(uint8_t *ptr, uint64_t addr, t_data *data,
		uint64_t size)
{
	uint64_t	i;

	if ((uint64_t)ptr + size > data->end_file)
		return ;
	ft_printf("Contents of (__TEXT,__text) section\n");
	if (data->ppc == 1)
	{
		print_ppc_big_64((void*)((char*)data->ptr + addr), addr, data, size);
		return ;
	}
	i = 0;
	while (i < size)
	{
		if (i + 16 > size)
		{
			print_one_by_one(ptr, (int)(size - i), addr + i);
			return ;
		}
		ft_printf("%016zx\t%02x %02x %02x %02x %02x %02x %02x %02x %02x %02x "
				"%02x %02x %02x %02x %02x %02x \n", addr + (uint32_t)i, ptr[0],
				ptr[1], ptr[2], ptr[3], ptr[4], ptr[5], ptr[6], ptr[7], ptr[8],
				ptr[9], ptr[10], ptr[11], ptr[12], ptr[13], ptr[14], ptr[15]);
		i += 16;
		ptr = ptr + 16;
	}
}
