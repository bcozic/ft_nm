/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:59:20 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/15 18:36:29 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

void	handle_ar(t_data *data, void *offset, void *ptr)
{
	struct ar_hdr	*header;
	size_t			i;

	header = (struct ar_hdr*)offset;
	offset = (char*)offset + sizeof(struct ar_hdr);
	if ((size_t)offset + 48 > data->end_file)
		return ;
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
	if (!ft_strcmp(offset, SYMDEF) || !ft_strcmp(offset, SYMDEF_SORTED))
		get_header_32(data, (char*)offset + i, ptr);
	else if (!ft_strcmp(offset, SYMDEF_64)
			|| !ft_strcmp(offset, SYMDEF_64_SORTED))
		get_header_64(data, (char*)offset + i, ptr);
}
