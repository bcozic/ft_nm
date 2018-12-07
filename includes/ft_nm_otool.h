/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nm_otool.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:06:01 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/07 10:01:28 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBC_H
# define FT_LIBC_H

#include <mach-o/loader.h>
#include <mach-o/nlist.h>
#include <sys/types.h>
#include "libft.h"

void	get_stat(int fd, void (*f)(void * ptr));
void	ft_nm(void* ptr);
void	handle_64(void *ptr);
void	handle_32(void *ptr);
void	get_symbols(struct symtab_command *sym, void* ptr);

#endif
