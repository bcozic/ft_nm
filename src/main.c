/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:35:11 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/10 10:52:26 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "ft_nm_otool.h"

int	main(int ac, char **av)
{
	int	i;
	int	fd;

	i = 0;
	if (ac < 2)
	{
		if ((fd = open("a.out", O_RDONLY)) < 0)
		{
			ft_printf("a.out: No such file or directory.\n");
			return (0);
		}
		get_stat(fd);
		close(fd);
	}
	while (++i < ac)
	{
		if ((fd = open(av[i], O_RDONLY)) < 0)
		{
			ft_printf("%s: No such file or directory.\n", av[1]);
			return (0);
		}
		get_stat(fd);
		close(fd);
	}
	return (0);
}
