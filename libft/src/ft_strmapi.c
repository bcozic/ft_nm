/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:24:35 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/07 08:46:43 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*rt_str;

	if (!s | !f)
		return (0);
	if (!(rt_str = ft_malloc(ft_strlen(s) + 1)))
		return (0);
	i = 0;
	while (s[i])
	{
		rt_str[i] = f(i, s[i]);
		i++;
	}
	rt_str[i] = '\0';
	return (rt_str);
}
