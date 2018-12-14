/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat_header_big_32.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:41:12 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/14 19:31:01 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static int	only_one_arch(struct fat_header *header, t_data *data, void *ptr)
{
	struct fat_arch		*arch;
	void				*ptr_arch;
	uint32_t			nfat_arch;

	nfat_arch = lte_32(header->nfat_arch);
	ptr_arch = (char*)ptr + sizeof(struct fat_header);
	while (nfat_arch--)
	{
		arch = (struct fat_arch*)ptr_arch;
		if (lte_32((uint32_t)arch->cputype) == CPU_TYPE_X86_64)
		{
			ft_nm((char*)ptr + lte_32(arch->offset), data);
			return (1);
		}
		ptr_arch = (char*)ptr_arch + sizeof(struct fat_arch);
	}
	ptr_arch = (char*)ptr + sizeof(struct fat_header);
	if (lte_32(header->nfat_arch) == 1)
	{
		arch = (struct fat_arch*)ptr_arch;
		ft_printf("%s:\n", data->file_name);
		ft_nm((char*)ptr + lte_32(arch->offset), data);
		return (1);
	}
	return (0);
}

void		fat_header_big_32(void *ptr, t_data *data)
{
	struct fat_header	*header;
	struct fat_arch		*arch;
	void				*ptr_arch;
	uint32_t			nfat_arch;

	header = (struct fat_header*)ptr;
	nfat_arch = lte_32(header->nfat_arch);
	if ((size_t)ptr + sizeof(struct fat_arch_64)
			* nfat_arch > data->end_file)
		return ;
	if (only_one_arch(header, data, ptr))
		return ;
	ptr_arch = (char*)ptr + sizeof(struct fat_header);
	while (nfat_arch--)
	{
		arch = (struct fat_arch*)ptr_arch;
		print_architecture(lte_32((uint32_t)arch->cputype), data);
		ft_nm((char*)ptr + lte_32(arch->offset), data);
		ptr_arch = (char*)ptr_arch + sizeof(struct fat_arch);
	}
}
