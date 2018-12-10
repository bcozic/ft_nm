/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sym_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 10:56:10 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/10 16:01:13 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

int	insert_sym_list_little_64(struct nlist_64 *symbol, t_data_64 *data)
{
	t_list_sym_64	*new;

	if (symbol->n_type & N_STAB)
		return (1);
	if (!(new = ft_malloc(sizeof(t_list_sym_64))))
	{
		ft_printf("ERROR malloc\n");
		return (0);
	}
	new->symbol = symbol;
	new->next = NULL;
	if (data->list_sym == NULL)
	{
		data->list_sym = new;
		return (1);
	}
	insert_by_name_little_64(new, data);
	return (1);
}

int	insert_sym_list_little_32(struct nlist *symbol, t_data_32 *data)
{
	t_list_sym_32	*new;

	if (symbol->n_type & N_STAB)
		return (1);
	if (!(new = ft_malloc(sizeof(t_list_sym_32))))
	{
		ft_printf("ERROR malloc\n");
		return (0);
	}
	new->symbol = symbol;
	new->next = NULL;
	if (data->list_sym == NULL)
	{
		data->list_sym = new;
		return (1);
	}
	insert_by_name_little_32(new, data);
	return (1);
}

int	insert_sym_list_big_64(struct nlist_64 *symbol, t_data_64 *data)
{
	t_list_sym_64	*new;

	if (symbol->n_type & N_STAB)
		return (1);
	if (!(new = ft_malloc(sizeof(t_list_sym_64))))
	{
		ft_printf("ERROR malloc\n");
		return (0);
	}
	new->symbol = symbol;
	new->next = NULL;
	if (data->list_sym == NULL)
	{
		data->list_sym = new;
		return (1);
	}
	insert_by_name_big_64(new, data);
	return (1);
}

int	insert_sym_list_big_32(struct nlist *symbol, t_data_32 *data)
{
	t_list_sym_32	*new;

	if (symbol->n_type & N_STAB)
		return (1);
	if (!(new = ft_malloc(sizeof(t_list_sym_32))))
	{
		ft_printf("ERROR malloc\n");
		return (0);
	}
	new->symbol = symbol;
	new->next = NULL;
	if (data->list_sym == NULL)
	{
		data->list_sym = new;
		return (1);
	}
	insert_by_name_big_32(new, data);
	return (1);
}
