/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:38:44 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/16 18:57:40 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <sys/stat.h>
#include "ft_nm.h"

static size_t	get_ptr(t_data *data, int fd, char *exec_name)
{
	struct stat	buf;
	size_t		size;

	if (fstat(fd, &buf) < 0)
		return ((size_t)aff_error(exec_name, data->file_name, "fstat Failure\n"));
	if ((buf.st_mode & S_IFMT) == S_IFDIR)
		return ((size_t)aff_error(exec_name, data->file_name, "Is a directory.\n"));
	if (buf.st_size == 0)
		return (0);
	size = (((size_t)buf.st_size / 4096) + 1) * 4096;
	if ((data->ptr = mmap(0, size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return ((size_t)aff_error(exec_name, data->file_name, "mmap Failure\n"));
	data->end_file = (size_t)data->ptr + (size_t)buf.st_size;	
	return (size);
}

int	get_stat(int fd, char *file_name, char *exec_name)
{
	t_data		data;
	void		*ptr;
	size_t		size;

	ft_bzero(&data, sizeof(t_data));
	data.file_name = file_name;
	if ((size = get_ptr(&data, fd, exec_name)) == 0)
		return (0);
	ptr = data.ptr;
	if ((size_t)ptr + sizeof(struct mach_header_64)
			> data.end_file || !(ft_nm(ptr, &data)))
		aff_error(exec_name, file_name, "The file was not recognized "
				"as a valid object file\n");
	if (munmap(ptr, size) < 0)
		return (aff_error(exec_name, file_name, "munmap Failure\n"));
	return (0);
}
