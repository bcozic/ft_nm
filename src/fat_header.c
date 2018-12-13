/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fat_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:57:00 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/13 18:10:41 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	fat_header_little_64(void *ptr, t_data *data)
{
	struct fat_header	*header;
	struct fat_arch_64	*arch;
	void				*ptr_arch;
	uint32_t			i;

	header = (struct fat_header*)ptr;
	ptr_arch = (char*)ptr + sizeof(struct fat_header);
	i = 0;
	while (i++ < header->nfat_arch)
	{
		arch = (struct fat_arch_64*)ptr_arch;
		if (arch->cputype == CPU_TYPE_X86_64)
		{
			ft_nm((char*)ptr + arch->offset, data);
			return ;
		}
		ptr_arch = (char*)ptr_arch + sizeof(struct fat_arch_64);
	}
	ptr_arch = (char*)ptr + sizeof(struct fat_header);
	i = 0;
	if (header->nfat_arch == 1)
	{
		arch = (struct fat_arch_64*)ptr_arch;
		ft_printf("%s:\n", data->file_name);
		ft_nm((char*)ptr + arch->offset, data);
		ptr_arch = (char*)ptr_arch + sizeof(struct fat_arch_64);
		return ;
	}
	while (i++ < header->nfat_arch)
	{
		arch = (struct fat_arch_64*)ptr_arch;
		print_architecture((uint32_t)arch->cputype, data);
		ft_nm((char*)ptr + arch->offset, data);
		ptr_arch = (char*)ptr_arch + sizeof(struct fat_arch_64);
	}
}

void	fat_header_little_32(void *ptr, t_data *data)
{
	struct fat_header	*header;
	struct fat_arch		*arch;
	void				*ptr_arch;
	uint32_t			i;

	header = (struct fat_header*)ptr;
	ptr_arch = (char*)ptr + sizeof(struct fat_header);
	i = 0;
	while (i++ < header->nfat_arch)
	{
		arch = (struct fat_arch*)ptr_arch;
		if (arch->cputype == CPU_TYPE_X86_64)
		{
			ft_nm((char*)ptr + arch->offset, data);
			return ;
		}
		ptr_arch = (char*)ptr_arch + sizeof(struct fat_arch);
	}
	ptr_arch = (char*)ptr + sizeof(struct fat_header);
	i = 0;
	if (header->nfat_arch == 1)
	{
		arch = (struct fat_arch*)ptr_arch;
		ft_printf("%s:\n", data->file_name);
		ft_nm((char*)ptr + arch->offset, data);
		ptr_arch = (char*)ptr_arch + sizeof(struct fat_arch);
		return ;
	}
	while (i++ < header->nfat_arch)
	{
		arch = (struct fat_arch*)ptr_arch;
		print_architecture((uint32_t)arch->cputype, data);
		ft_nm((char*)ptr + arch->offset, data);
		ptr_arch = (char*)ptr_arch + sizeof(struct fat_arch);
	}
}

void	fat_header_big_64(void *ptr, t_data *data)
{
	struct fat_header	*header;
	struct fat_arch_64	*arch;
	void				*ptr_arch;
	uint32_t			nfat_arch;

	header = (struct fat_header*)ptr;
	ptr_arch = (char*)ptr + sizeof(struct fat_header);
	nfat_arch = lte_32(header->nfat_arch);
	while (nfat_arch--)
	{
		arch = (struct fat_arch_64*)ptr_arch;
		if (lte_32((uint32_t)arch->cputype) == CPU_TYPE_X86_64)
		{
			ft_nm((char*)ptr + lte_64(arch->offset), data);
			return ;
		}
		ptr_arch = (char*)ptr_arch + sizeof(struct fat_arch_64);
	}
	ptr_arch = (char*)ptr + sizeof(struct fat_header);
	nfat_arch = lte_32(header->nfat_arch);
	if (nfat_arch == 1)
	{
		arch = (struct fat_arch_64*)ptr_arch;
		ft_printf("%s:\n", data->file_name);
		ft_nm((char*)ptr + lte_64(arch->offset), data);
		ptr_arch = (char*)ptr_arch + sizeof(struct fat_arch_64);
		return ;
	}
	while (nfat_arch--)
	{
		arch = (struct fat_arch_64*)ptr_arch;
		print_architecture(lte_32((uint32_t)arch->cputype), data);
		ft_nm((char*)ptr + lte_64(arch->offset), data);
		ptr_arch = (char*)ptr_arch + sizeof(struct fat_arch_64);
	}
}

void	fat_header_big_32(void *ptr, t_data *data)
{
	struct fat_header	*header;
	struct fat_arch		*arch;
	void				*ptr_arch;
	uint32_t			nfat_arch;

	header = (struct fat_header*)ptr;
	ptr_arch = (char*)ptr + sizeof(struct fat_header);
	nfat_arch = lte_32(header->nfat_arch);
	while (nfat_arch--)
	{
		arch = (struct fat_arch*)ptr_arch;
		if (lte_32((uint32_t)arch->cputype) == CPU_TYPE_X86_64)
		{
			ft_nm((char*)ptr + lte_32(arch->offset), data);
			return ;
		}
		ptr_arch = (char*)ptr_arch + sizeof(struct fat_arch);
	}
	ptr_arch = (char*)ptr + sizeof(struct fat_header);
	nfat_arch = lte_32(header->nfat_arch);
	if (nfat_arch == 1)
	{
		arch = (struct fat_arch*)ptr_arch;
		ft_printf("%s:\n", data->file_name);
		ft_nm((char*)ptr + lte_32(arch->offset), data);
		ptr_arch = (char*)ptr_arch + sizeof(struct fat_arch);
		return ;
	}
	while (nfat_arch--)
	{
		arch = (struct fat_arch*)ptr_arch;
		print_architecture(lte_32((uint32_t)arch->cputype), data);
		ft_nm((char*)ptr + lte_32(arch->offset), data);
		ptr_arch = (char*)ptr_arch + sizeof(struct fat_arch);
	}
}
