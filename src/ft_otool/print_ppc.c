/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ppc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 20:28:30 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/16 14:33:10 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static void	print_one_by_one(uint32_t *ptr, int count, int endianness)
{
	while (count)
	{
		if (endianness)
			ft_printf("%08x ", *ptr);
		else
			ft_printf("%08x ", lte_32(*ptr));
		ptr = ptr + 1;
		count -= 4;
	}
	ft_printf("\n");
}

void		print_ppc_little_32(uint32_t *ptr, uint32_t addr, t_data *data,
		uint32_t size)
{
	uint32_t	i;

	data->ppc = 0;
	i = 0;
	while (i < size)
	{
		if (i + 16 > size)
		{
			ft_printf("%08zx\t", addr + i);
			print_one_by_one(ptr, (int)(size - i), 1);
			return ;
		}
		ft_printf("%08zx\t%08x %08x %08x %08x \n", addr + i, ptr[0], ptr[1],
				ptr[2], ptr[3]);
		i += 16;
		ptr = ptr + 4;
	}
}

void		print_ppc_little_64(uint32_t *ptr, uint64_t addr, t_data *data,
		uint64_t size)
{
	uint64_t	i;

	data->ppc = 0;
	i = 0;
	while (i < size)
	{
		if (i + 16 > size)
		{
			ft_printf("%016zx\t", addr + i);
			print_one_by_one(ptr, (int)(size - i), 1);
			return ;
		}
		ft_printf("%016zx\t%08x %08x %08x %08x \n", addr + (uint32_t)i, ptr[0],
				ptr[1], ptr[2], ptr[3]);
		i += 16;
		ptr = ptr + 4;
	}
}

void		print_ppc_big_32(uint32_t *ptr, uint32_t addr, t_data *data,
		uint32_t size)
{
	uint32_t	i;

	data->ppc = 0;
	i = 0;
	while (i < size)
	{
		if (i + 16 > size)
		{
			ft_printf("%08zx\t", addr + i);
			print_one_by_one(ptr, (int)(size - i), 0);
			return ;
		}
		ft_printf("%08zx\t%08x %08x %08x %08x \n", addr + i, lte_32(ptr[0]),
				lte_32(ptr[1]), lte_32(ptr[2]), lte_32(ptr[3]));
		i += 16;
		ptr = ptr + 4;
	}
}

void		print_ppc_big_64(uint32_t *ptr, uint64_t addr, t_data *data,
		uint64_t size)
{
	uint64_t	i;

	data->ppc = 0;
	i = 0;
	while (i < size)
	{
		if (i + 16 > size)
		{
			ft_printf("%016zx\t", addr + i);
			print_one_by_one(ptr, (int)(size - i), 0);
			return ;
		}
		ft_printf("%016zx\t%08x %08x %08x %08x \n", addr + (uint32_t)i,
				lte_32(ptr[0]), lte_32(ptr[1]), lte_32(ptr[2]), lte_32(ptr[3]));
		i += 16;
		ptr = ptr + 4;
	}
}
