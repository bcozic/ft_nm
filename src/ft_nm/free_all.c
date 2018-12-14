/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:58:16 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/14 14:45:59 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	free_all_64(t_arch_64 *arch)
{
	free_list_sym_64(arch->list_sym);
	free_section_64(arch->section);
	ft_bzero(arch, sizeof(t_arch_64));
}

void	free_all_32(t_arch_32 *arch)
{
	free_list_sym_32(arch->list_sym);
	free_section_32(arch->section);
	ft_bzero(arch, sizeof(t_arch_32));
}
