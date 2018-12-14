/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list_sym.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:06:09 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/14 19:33:01 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	free_list_sym_64(t_list_sym_64 *list_sym)
{
	if (!list_sym)
		return ;
	free_list_sym_64(list_sym->next);
	ft_free(list_sym);
}

void	free_list_sym_32(t_list_sym_32 *list_sym)
{
	if (!list_sym)
		return ;
	free_list_sym_32(list_sym->next);
	ft_free(list_sym);
}
