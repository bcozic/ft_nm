/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_architecture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:48:52 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/15 21:02:07 by bcozic           ###   ########.fr       */
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
		ft_printf("(for architecture ppc64):\n");
	else if (arch == CPU_TYPE_I386)
		ft_printf("(architecture i386):\n");
	else if (arch == CPU_TYPE_I860)
		ft_printf("(for architecture i860):\n");
	else if (arch == CPU_TYPE_MC680x0)
		ft_printf("(for architecture mc680x0):\n");
	else if (arch == CPU_TYPE_MC98000)
		ft_printf("(for architecture mc98000):\n");
	else if (arch == CPU_TYPE_HPPA)
		ft_printf("(for architecture hppa):\n");
	else if (arch == CPU_TYPE_ARM)
		ft_printf("(for architecture arm):\n");
	else if (arch == CPU_TYPE_ARM64)
		ft_printf("(for architecture arm64):\n");
	else if (arch == CPU_TYPE_MC88000)
		ft_printf("(for architecture mc88000):\n");
	else if (arch == CPU_TYPE_SPARC)
		ft_printf("(for architecture sparc):\n");
	else
		ft_printf(":\n");
}
