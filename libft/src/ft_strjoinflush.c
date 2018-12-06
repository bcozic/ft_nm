/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinflush.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:27:31 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/03 07:21:01 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoinflush(char **s1, char const *s2)
{
	size_t	size_s1;
	char	*str;

	size_s1 = 1;
	if (!s2 || !s1)
		return (0);
	if (*s1)
		size_s1 += ft_strlen(*s1);
	if (!(str = (char *)malloc(sizeof(char) * size_s1 + ft_strlen(s2))))
		return (0);
	str[0] = '\0';
	if (*s1)
	{
		ft_strcpy(str, *s1);
		free(*s1);
	}
	ft_strcat(str, s2);
	*s1 = str;
	return (*s1);
}
