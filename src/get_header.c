/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_header.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:33:43 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/13 16:45:57 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static void	call_ft_nm(t_data *data, void *offset)
{
	struct ar_hdr	*header;
	size_t			i;

	header = (struct ar_hdr*)offset;
	offset = (char*)offset + sizeof(struct ar_hdr);
	ft_printf("\n%s(%s):\n", data->file_name, offset);
	i = ft_strlen(offset);
	while (*(uint8_t*)(void*)((char*)offset + i) == 0)
		i++;
	offset = (char*)offset + i;
	ft_nm(offset, data);
}

void	get_header_64(t_data *data, void *offset)
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
		if (ranlib->ran_off != last_offset)
			call_ft_nm(data, (char*)data->ptr + ranlib->ran_off);
		last_offset = ranlib->ran_off;
		ranlib = (struct ranlib_64*)((size_t)ranlib + sizeof(struct ranlib_64));
		current += sizeof(struct ranlib_64);
	}
}

void	get_header_32(t_data *data, void *offset)
{
	struct ranlib	*ranlib;
	uint32_t		size;
	uint32_t		current;
	uint32_t		last_offset;

	size = *(uint32_t*)offset;
	offset = (char*)offset + sizeof(uint32_t);
	ranlib = (struct ranlib*)offset;
	current = 0;
	last_offset = 0;
	while (current < size)
	{
		if (ranlib->ran_off != last_offset)
			call_ft_nm(data, (char*)data->ptr + ranlib->ran_off);
		last_offset = ranlib->ran_off;
		ranlib = (struct ranlib*)((size_t)ranlib + sizeof(struct ranlib));
		current += sizeof(struct ranlib);
	}
}
