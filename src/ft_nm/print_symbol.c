/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_symbol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 14:58:42 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/14 19:33:01 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	print_symbol_little_64(char type, t_arch_64 *arch,
		struct nlist_64 *symbol)
{
	if (type != 'U')
		ft_printf("%016zx %c %s\n", symbol->n_value, type,
			arch->stringtable + symbol->n_un.n_strx);
	else
		ft_printf("                 %c %s\n", type, arch->stringtable
				+ symbol->n_un.n_strx);
}

void	print_symbol_little_32(char type, t_arch_32 *arch, struct nlist *symbol)
{
	if (type != 'U')
		ft_printf("%08zx %c %s\n", symbol->n_value, type,
			arch->stringtable + symbol->n_un.n_strx);
	else
		ft_printf("         %c %s\n", type, arch->stringtable
				+ symbol->n_un.n_strx);
}

void	print_symbol_big_64(char type, t_arch_64 *arch, struct nlist_64 *symbol)
{
	if (type != 'U')
		ft_printf("%016zx %c %s\n", lte_64(symbol->n_value), type,
				arch->stringtable + lte_32(symbol->n_un.n_strx));
	else
		ft_printf("                 %c %s\n", type, arch->stringtable
				+ lte_32(symbol->n_un.n_strx));
}

void	print_symbol_big_32(char type, t_arch_32 *arch, struct nlist *symbol)
{
	if (type != 'U')
		ft_printf("%08zx %c %s\n", lte_32(symbol->n_value), type,
				arch->stringtable + lte_32(symbol->n_un.n_strx));
	else
		ft_printf("         %c %s\n", type, arch->stringtable
				+ lte_32(symbol->n_un.n_strx));
}
