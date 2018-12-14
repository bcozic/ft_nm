/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_by_name_big_32.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 15:43:16 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/14 19:33:01 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

static void	delete_next(t_list_sym_32 *current)
{
	t_list_sym_32	*to_delete;

	to_delete = current->next;
	current->next = current->next->next;
	ft_free(to_delete);
}

static void	check_duplicate_first(t_list_sym_32 *current, t_arch_32 *arch)
{
	t_list_sym_32	*to_delete;

	if (ft_strcmp((arch->stringtable + lte_32(current->symbol->n_un.n_strx)),
			arch->stringtable + lte_32(current->next->symbol->n_un.n_strx)))
		return ;
	if (current->symbol->n_value == current->next->symbol->n_value)
	{
		if (current->symbol->n_type & N_EXT)
			delete_next(current);
		else if (current->next->symbol->n_type & N_EXT)
		{
			to_delete = current;
			arch->list_sym = current->next;
			ft_free(to_delete);
		}
	}
	else if (!current->symbol->n_value)
	{
		to_delete = current;
		arch->list_sym = current->next;
		ft_free(to_delete);
	}
	else if (!current->next->symbol->n_value)
		delete_next(current);
}

static void	check_duplicate(t_list_sym_32 *current, t_arch_32 *arch)
{
	if (!current->next->next || ft_strcmp((arch->stringtable
			+ lte_32(current->next->symbol->n_un.n_strx)), arch->stringtable
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

void		insert_by_name_big_32(t_list_sym_32 *new, t_arch_32 *arch)
{
	t_list_sym_32	*c;
	int				d;

	c = arch->list_sym;
	if ((d = ft_strcmp((arch->stringtable + lte_32(new->symbol->n_un.n_strx)),
			arch->stringtable + lte_32(c->symbol->n_un.n_strx))) < 0 || (!d
			&& lte_32(new->symbol->n_value) < lte_32(c->symbol->n_value)))
	{
		new->next = c;
		arch->list_sym = new;
		check_duplicate_first(arch->list_sym, arch);
		return ;
	}
	while (c->next && ft_strcmp(arch->stringtable
			+ lte_32(new->symbol->n_un.n_strx), arch->stringtable
			+ lte_32(c->next->symbol->n_un.n_strx)) > 0)
		c = c->next;
	while (c->next && !ft_strcmp(arch->stringtable
			+ lte_32(new->symbol->n_un.n_strx), arch->stringtable
			+ lte_32(c->next->symbol->n_un.n_strx))
			&& lte_32(new->symbol->n_value) > lte_32(c->next->symbol->n_value))
		c = c->next;
	new->next = c->next;
	c->next = new;
	check_duplicate(c, arch);
}
