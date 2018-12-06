/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:27:31 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/03 07:23:24 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len1;
	size_t	len2;

	len2 = ft_strlen(s2);
	if (!s2)
		return (0);
	if (!s1)
	{
		if (!(str = malloc(len2 + 1)))
			return (0);
		ft_memcpy(str, s2, len2 + 1);
		return (str);
	}
	len1 = ft_strlen(s1);
	if (!(str = malloc(len1 + len2 + 1)))
		return (0);
	ft_memcpy(str, s1, len1 + 1);
	ft_memcpy(str + len1, s2, len2 + 1);
	return (str);
}
