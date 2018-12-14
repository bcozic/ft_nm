/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:35:11 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/14 15:46:06 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_nm_otool.h"

int	main(int ac, char **av)
{
	int		i;
	int		fd;

	i = 0;
	if (ac < 2)
	{
		if ((fd = open("a.out", O_RDONLY)) < 0)
			return (aff_error(av[0], "a.out", "No such file or directory.\n"));
		get_stat(fd, "a.out", av[0]);
		close(fd);
	}
	while (++i < ac)
	{
		if ((fd = open(av[i], O_RDONLY)) < 0)
			return (aff_error(av[0], av[i], "No such file or directory.\n"));
		if (ac > 2)
			ft_printf("\n%s:\n", av[i]);
		get_stat(fd, av[i], av[0]);
		close(fd);
	}
	return (0);
}
