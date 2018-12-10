/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 16:58:16 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/10 12:26:39 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

void	free_all_64(t_data_64 *data)
{
	free_list_sym_64(data->list_sym);
	free_section_64(data->section);	
	ft_free(data);
}

void	free_all_32(t_data_32 *data)
{
	free_list_sym_32(data->list_sym);
	free_section_32(data->section);	
	ft_free(data);
}