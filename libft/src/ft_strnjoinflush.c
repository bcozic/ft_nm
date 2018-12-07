/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinflush.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:03:29 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/07 08:47:32 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoinflush(char **s1, char const *s2, size_t len)
{
	char	*str;
	size_t	size;

	size = 1;
	if (!s2)
		return (0);
	if (*s1)
		size += ft_strlen(*s1);
	if (ft_strlen(s2) < len)
		size += ft_strlen(s2);
	else
		size += len;
	if (!(str = ft_malloc(sizeof(char) * size)))
		return (0);
	str[0] = '\0';
	if (*s1)
	{
		ft_strncpy(str, *s1, len);
		ft_free(*s1);
	}
	ft_strncat(str, s2, len);
	*s1 = str;
	return (*s1);
}
