/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:33:43 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/14 18:58:47 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static void	call_ft_nm(t_data *data, void *offset)
{
	struct ar_hdr	*header;
	size_t			i;

	header = (struct ar_hdr*)offset;
	offset = (char*)offset + sizeof(struct ar_hdr);
	if ((size_t)offset + 48 > data->end_file)
		return ;
	ft_printf("\n%s(%s):\n", data->file_name, offset);
	i = 0;
	while (*(uint8_t*)(void*)((char*)offset + i))
	{
		if ((size_t)offset + i > data->end_file)
			return ;
		i++;
	}
	while (*(uint8_t*)(void*)((char*)offset + i) == 0)
	{
		if ((size_t)offset + i > data->end_file)
			return ;
		i++;
	}
	offset = (char*)offset + i;
	ft_nm(offset, data);
}

void		get_header_64(t_data *data, void *offset, void *ptr)
{
	struct ranlib_64	*ranlib;
	uint32_t			size;
	uint32_t			current;
	uint64_t			last_offset;

	size = *(uint32_t*)offset;
	offset = (char*)offset + sizeof(uint32_t);
	ranlib = (struct ranlib_64*)offset;
	current = 0;
	last_offset = 0;
	while (current < size)
	{
		if (ranlib->ran_off > last_offset)
			call_ft_nm(data, (char*)ptr + ranlib->ran_off);
		last_offset = ranlib->ran_off;
		ranlib = (struct ranlib_64*)((size_t)ranlib + sizeof(struct ranlib_64));
		current += sizeof(struct ranlib_64);
	}
}

void		get_header_32(t_data *data, void *offset, void *ptr)
{
	struct ranlib	*ranlib;
	uint32_t		size;
	uint32_t		current;
	uint32_t		last_offset;

	if (!ft_strncmp(AR_EFMT1, offset, 3))
		return ;
	size = *(uint32_t*)offset;
	offset = (char*)offset + sizeof(uint32_t);
	ranlib = (struct ranlib*)offset;
	current = 0;
	last_offset = 0;
	while (current < size && size)
	{
		if (ranlib->ran_off != last_offset)
			call_ft_nm(data, (char*)ptr + ranlib->ran_off);
		last_offset = ranlib->ran_off;
		ranlib = (struct ranlib*)((size_t)ranlib + sizeof(struct ranlib));
		current += sizeof(struct ranlib);
	}
}
