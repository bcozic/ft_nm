/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat_header_little_64.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:21:39 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/15 21:01:57 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

static int	only_one_arch(struct fat_header *header, t_data *data, void *ptr)
{
	struct fat_arch_64	*arch;
	void				*ptr_arch;
	uint32_t			i;

	ptr_arch = (char*)ptr + sizeof(struct fat_header);
	i = 0;
	while (i++ < header->nfat_arch)
	{
		arch = (struct fat_arch_64*)ptr_arch;
		if (arch->cputype == CPU_TYPE_X86_64)
		{
			ft_printf("%s:\n", data->file_name);
			ft_otool((char*)ptr + arch->offset, data);
			return (1);
		}
		ptr_arch = (char*)ptr_arch + sizeof(struct fat_arch_64);
	}
	ptr_arch = (char*)ptr + sizeof(struct fat_header);
	if (header->nfat_arch == 1)
	{
		arch = (struct fat_arch_64*)ptr_arch;
		ft_printf("%s:\n", data->file_name);
		ft_otool((char*)ptr + arch->offset, data);
		return (1);
	}
	return (0);
}

void		fat_header_little_64(void *ptr, t_data *data)
{
	struct fat_header	*header;
	struct fat_arch_64	*arch;
	void				*ptr_arch;
	uint32_t			i;

	header = (struct fat_header*)ptr;
	if ((size_t)ptr + sizeof(struct fat_arch_64)
			* header->nfat_arch > data->end_file)
		return ;
	if (only_one_arch(header, data, ptr))
		return ;
	ptr_arch = (char*)ptr + sizeof(struct fat_header);
	i = 0;
	while (i++ < header->nfat_arch)
	{
		arch = (struct fat_arch_64*)ptr_arch;
		print_architecture((uint32_t)arch->cputype, data);
		ft_otool((char*)ptr + arch->offset, data);
		ptr_arch = (char*)ptr_arch + sizeof(struct fat_arch_64);
	}
}
