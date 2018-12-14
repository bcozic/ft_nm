/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 13:38:44 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/14 19:33:01 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/mman.h>
#include <sys/stat.h>
#include "ft_nm.h"

int	get_stat(int fd, char *file_name, char *exec_name)
{
	struct stat	buf;
	t_data		data;

	ft_bzero(&data, sizeof(t_data));
	if (fstat(fd, &buf) < 0)
		return (aff_error(exec_name, file_name, "fstat Failure\n"));
	if ((buf.st_mode & S_IFMT) == S_IFDIR)
		return (aff_error(exec_name, file_name, "Is a directory.\n"));
	if ((data.ptr = mmap(0, (size_t)buf.st_size, PROT_READ,
			MAP_PRIVATE, fd, 0)) == MAP_FAILED)
		return (aff_error(exec_name, file_name, "mmap Failure\n"));
	data.end_file = (size_t)data.ptr + (size_t)buf.st_size;
	data.file_name = file_name;
	if ((size_t)data.ptr + sizeof(struct mach_header_64)
			> data.end_file || !(ft_nm(data.ptr, &data)))
		aff_error(exec_name, file_name, "The file was not recognized "
				"as a valid object file\n");
	if ((munmap(data.ptr, (size_t)buf.st_size)) < 0)
		return (aff_error(exec_name, file_name, "munmap Failure\n"));
	return (0);
}
