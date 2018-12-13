/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:35:11 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/13 12:17:04 by bcozic           ###   ########.fr       */
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
		{
			write(2, "a.out: No such file or directory.\n", 34);
			return (0);
		}
		get_stat(fd, "a.out");
		close(fd);
	}
	while (++i < ac)
	{
		if ((fd = open(av[i], O_RDONLY)) < 0)
		{
			write(2, av[i], ft_strlen(av[1]));
			write(2, ": No such file or directory.\n", 30);
			return (0);
		}
		if (ac > 2)
			ft_printf("%s:\n", av[i]);
		get_stat(fd, av[i]);
		close(fd);
	}
	return (0);
}
