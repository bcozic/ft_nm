/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:28:05 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/03 07:13:41 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*cpy;

	len = ft_strlen(src) + 1;
	if (!(cpy = malloc(sizeof(char) * len)))
		return (0);
	memmove(cpy, src, len);
	return (cpy);
}
