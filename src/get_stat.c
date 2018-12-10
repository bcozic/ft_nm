/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:38:44 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/10 16:10:02 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <sys/stat.h>
#include "ft_nm_otool.h"

void	get_stat(int fd)
{
	struct stat	buf;
	char		*ptr;

	if (fstat(fd, &buf) < 0)
	{
		write(2, "fstat Failure\n", 14);
		return ;
	}
	if ((ptr = mmap(0, (size_t)buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
	{
		write(2, "mmap Failure\n", 13);
		return ;
	}
	ft_nm((void*)ptr);
	if ((munmap(ptr, (size_t)buf.st_size)) < 0)
	{
		write(2, "munmap Failure\n", 15);
		return ;
	}
}
