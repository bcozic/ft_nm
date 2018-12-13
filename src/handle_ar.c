/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 14:59:20 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/13 18:31:22 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	handle_ar(t_data *data, void *offset, void *ptr)
{
	struct ar_hdr	*header;
	size_t			i;

	header = (struct ar_hdr*)offset;
	offset = (char*)offset + sizeof(struct ar_hdr);
	if ((size_t)offset > data->end_file)
		return ;
	if (!ft_strcmp(offset, SYMDEF) || !ft_strcmp(offset, SYMDEF_SORTED))
	{
		i = ft_strlen(offset);
		while (*((char*)offset + i) == 0)
			i += 1;
		offset = (char*)offset + i;
		get_header_32(data, offset, ptr);
	}
	if (!ft_strcmp(offset, SYMDEF_64) || !ft_strcmp(offset, SYMDEF_64_SORTED))
	{
		i = ft_strlen(offset);
		while (*((char*)offset + i) == 0)
			i += 1;
		offset = (char*)offset + i;
		get_header_64(data, offset, ptr);
	}
}
