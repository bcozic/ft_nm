/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 19:59:42 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/15 20:07:36 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

int	print_name(void *ptr, t_data *data)
{
	if ((size_t)ptr + sizeof(uint32_t) > data->end_file)
		return (0);
	if (*(uint32_t*)ptr == MH_MAGIC_64 || *(uint32_t*)ptr == MH_CIGAM_64 || *(uint32_t*)ptr == MH_MAGIC || *(uint32_t*)ptr == MH_CIGAM)
		ft_printf("%s:\n", data->file_name);
	return (1);
}
