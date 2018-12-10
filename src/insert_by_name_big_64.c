/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_by_name_big_64.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:43:11 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/10 15:53:57 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static void	delete_next(t_list_sym_64 *current)
{
	t_list_sym_64	*to_delete;

	to_delete = current->next;
	current->next = current->next->next;
	ft_free(to_delete);
}

static void	check_duplicate_first(t_list_sym_64 *current, t_data_64 *data)
{
	t_list_sym_64	*to_delete;

	if (ft_strcmp((data->stringtable + lte_32(current->symbol->n_un.n_strx)),
			data->stringtable + lte_32(current->next->symbol->n_un.n_strx)))
		return ;
	if (current->symbol->n_value == current->next->symbol->n_value)
	{
		if (current->symbol->n_type & N_EXT)
			delete_next(current);
		else if (current->next->symbol->n_type & N_EXT)
		{
			to_delete = current;
			data->list_sym = current->next;
			ft_free(to_delete);
		}
	}
	else if (!current->symbol->n_value)
	{
		to_delete = current;
		data->list_sym = current->next;
		ft_free(to_delete);
	}
	else if (!current->next->symbol->n_value)
		delete_next(current);
}

static void	check_duplicate(t_list_sym_64 *current, t_data_64 *data)
{
	if (!current->next->next || ft_strcmp((data->stringtable
			+ lte_32(current->next->symbol->n_un.n_strx)), data->stringtable
			+ lte_32(current->next->next->symbol->n_un.n_strx)))
		return ;
	if (current->next->symbol->n_value
			== current->next->next->symbol->n_value)
	{
		if (current->next->symbol->n_type & N_EXT)
			delete_next(current->next);
		else if (current->next->next->symbol->n_type & N_EXT)
			delete_next(current);
	}
	else if (!current->next->symbol->n_value)
		delete_next(current);
	else if (!current->next->next->symbol->n_value)
		delete_next(current->next);
}

void		insert_by_name_big_64(t_list_sym_64 *new_elem, t_data_64 *data)
{
	t_list_sym_64	*current;
	int				diff;
	uint32_t		new_strx;

	current = data->list_sym;
	new_strx = lte_32(new_elem->symbol->n_un.n_strx);
	if ((diff = ft_strcmp((data->stringtable + new_strx), data->stringtable
			+ lte_32(current->symbol->n_un.n_strx))) < 0 || (!diff &&
			lte_64(new_elem->symbol->n_value)
			< lte_64(current->symbol->n_value)))
	{
		new_elem->next = current;
		data->list_sym = new_elem;
		check_duplicate_first(data->list_sym, data);
		return ;
	}
	while (current->next && ft_strcmp(data->stringtable
			+ new_strx, data->stringtable
			+ lte_32(current->next->symbol->n_un.n_strx)) > 0)
		current = current->next;
	while (current->next && !ft_strcmp(data->stringtable
			+ new_strx, data->stringtable
			+ lte_32(current->next->symbol->n_un.n_strx))
			&& lte_64(new_elem->symbol->n_value)
			> lte_64(current->next->symbol->n_value))
		current = current->next;
	new_elem->next = current->next;
	current->next = new_elem;
	check_duplicate(current, data);
}
