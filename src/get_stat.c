/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:38:44 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/06 14:46:48 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <sys/stat.h>
#include "ft_nm_otool.h"

void	get_stat(int fd, void (*f)(void*))
{
	struct stat	buf;
	char		*ptr;

	if (fstat(fd, &buf) < 0)
	{
		ft_printf("fstat Failure\n");
		return ;
	}
	if ((ptr = mmap(0, (size_t)buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
	{
		ft_printf("mmap Failure\n");
		return ;
	}
	f((void*)ptr);
	if ((munmap(ptr, (size_t)buf.st_size)) < 0)
	{
		ft_printf("munmap Failure\n");
		return ;
	}
}
