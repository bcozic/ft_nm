/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sym_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 10:56:10 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/14 19:01:10 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

static int	check_len(char *str, size_t end_file)
{
	int	i;

	i = 0;
	while ((size_t)&(str[i]) < end_file && str[i])
	{
		i++;
	}
	if ((size_t)&(str[i]) >= end_file)
		return (0);
	return (1);
}

int			insert_sym_list_little_64(struct nlist_64 *symbol, t_arch_64 *arch)
{
	t_list_sym_64	*new;
	char			*str;

	if (symbol->n_type & N_STAB)
		return (1);
	str = arch->stringtable + symbol->n_un.n_strx;
	if ((size_t)str > arch->end_file || !check_len(str, arch->end_file))
		return (0);
	if (!(new = ft_malloc(sizeof(t_list_sym_64))))
	{
		write(2, "ERROR malloc\n", 13);
		return (0);
	}
	new->symbol = symbol;
	new->next = NULL;
	if (arch->list_sym == NULL)
	{
		arch->list_sym = new;
		return (1);
	}
	insert_by_name_little_64(new, arch);
	return (1);
}

int			insert_sym_list_little_32(struct nlist *symbol, t_arch_32 *arch)
{
	t_list_sym_32	*new;
	char			*str;

	if (symbol->n_type & N_STAB)
		return (1);
	str = arch->stringtable + symbol->n_un.n_strx;
	if ((size_t)str > arch->end_file || !check_len(str, arch->end_file))
		return (0);
	if (!(new = ft_malloc(sizeof(t_list_sym_32))))
	{
		write(2, "ERROR malloc\n", 13);
		return (0);
	}
	new->symbol = symbol;
	new->next = NULL;
	if (arch->list_sym == NULL)
	{
		arch->list_sym = new;
		return (1);
	}
	insert_by_name_little_32(new, arch);
	return (1);
}

int			insert_sym_list_big_64(struct nlist_64 *symbol, t_arch_64 *arch)
{
	t_list_sym_64	*new;
	char			*str;

	if (symbol->n_type & N_STAB)
		return (1);
	str = arch->stringtable + lte_32(symbol->n_un.n_strx);
	if ((size_t)str > arch->end_file || !check_len(str, arch->end_file))
		return (0);
	if (!(new = ft_malloc(sizeof(t_list_sym_64))))
	{
		write(2, "ERROR malloc\n", 13);
		return (0);
	}
	new->symbol = symbol;
	new->next = NULL;
	if (arch->list_sym == NULL)
	{
		arch->list_sym = new;
		return (1);
	}
	insert_by_name_big_64(new, arch);
	return (1);
}

int			insert_sym_list_big_32(struct nlist *symbol, t_arch_32 *arch)
{
	t_list_sym_32	*new;
	char			*str;

	if (symbol->n_type & N_STAB)
		return (1);
	str = arch->stringtable + lte_32(symbol->n_un.n_strx);
	if ((size_t)str > arch->end_file || !check_len(str, arch->end_file))
		return (0);
	if (!(new = ft_malloc(sizeof(t_list_sym_32))))
	{
		write(2, "ERROR malloc\n", 13);
		return (0);
	}
	new->symbol = symbol;
	new->next = NULL;
	if (arch->list_sym == NULL)
	{
		arch->list_sym = new;
		return (1);
	}
	insert_by_name_big_32(new, arch);
	return (1);
}
