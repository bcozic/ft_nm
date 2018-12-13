/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:38:44 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/13 13:46:45 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <sys/stat.h>
#include "ft_nm_otool.h"

void	get_stat(int fd, char *file_name)
{
	struct stat	buf;
	t_data		data;

	ft_bzero(&data, sizeof(t_data));
	if (fstat(fd, &buf) < 0)
	{
		write(2, "fstat Failure\n", 14);
		return ;
	}
	if ((data.ptr = mmap(0, (size_t)buf.st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
	{
		write(2, "mmap Failure\n", 13);
		return ;
	}
	data.end_file = (size_t)data.ptr + (size_t)buf.st_size;
	data.file_name = file_name;
	if (!(ft_nm(data.ptr, &data)))
	{
		write(2, file_name, ft_strlen(file_name));
		write(2, " The file was not recognized as a valid object file\n", 52);
	}
	if ((munmap(data.ptr, (size_t)buf.st_size)) < 0)
	{
		write(2, "munmap Failure\n", 15);
		return ;
	}
}
