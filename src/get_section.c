/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_section.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:27:00 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/12 12:11:53 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

struct section_64	*get_section_64(uint8_t n_sect, t_section_64 *current)
{
	int	i;

	if (n_sect == 0)
		return (NULL);
	i = 0;
	while(++i < n_sect)
	{
		if (!current)
			return (NULL);
		current = current->next;
	}
	if (!current)
		return (NULL);
	return (current->section);
}

struct section		*get_section_32(uint8_t n_sect, t_section_32 *current)
{
	int	i;

	if (n_sect == 0)
		return (NULL);
	i = 0;
	while(++i < n_sect)
	{
		if (!current)
			return (NULL);
		current = current->next;
	}
	if (!current)
		return (NULL);
	return (current->section);
}
