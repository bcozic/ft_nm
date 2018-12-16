/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_architecture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:48:52 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/16 14:43:53 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_otool.h"

void	print_architecture(uint32_t arch, t_data *data)
{
	ft_printf("%s ", data->file_name);
	if (arch == CPU_TYPE_POWERPC || arch == CPU_TYPE_POWERPC64)
		data->ppc = 1;
	if (arch == CPU_TYPE_POWERPC)
		ft_printf("(architecture ppc):\n");
	else if (arch == CPU_TYPE_POWERPC64)
		ft_printf("(architecture ppc64):\n");
	else if (arch == CPU_TYPE_I386)
		ft_printf("(architecture i386):\n");
	else if (arch == CPU_TYPE_I860)
		ft_printf("(architecture i860):\n");
	else
		ft_printf(":\n");
}
