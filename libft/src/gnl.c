/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 10:58:15 by fbabin            #+#    #+#             */
/*   Updated: 2018/05/21 13:05:03 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				gnl(char **line, char *buffer)
{
	static int		idx = -1;
	unsigned int	*c;

	if (idx != -1 && buffer[idx] == 0)
		return (-1);
	idx++;
	*line = buffer + idx;
	c = (unsigned int *)((void*)(*line));
	while (1)
	{
		if (((*c & 0xFF) == 0x0A) || !(*c & 0xFF))
			return ((int)(&(buffer[idx]) - *line));
		if (((*c & 0xFF00) == 0x0A00) || !(*c & 0xFF00))
			return ((int)(&(buffer[++idx]) - *line));
		if (((*c & 0xFF0000) == 0x0A0000) || !(*c & 0xFF0000))
			return ((int)(&(buffer[(idx += 2)]) - *line));
		if (((*c & 0xFF000000) == 0x0A000000) || !(*c & 0xFF000000))
			return ((int)(&(buffer[(idx += 3)]) - *line));
		idx += 4;
		c++;
	}
}
