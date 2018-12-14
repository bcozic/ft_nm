/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_section.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 12:06:56 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/14 19:33:01 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm.h"

void	free_section_64(t_section_64 *section)
{
	if (!section)
		return ;
	free_section_64(section->next);
	ft_free(section);
}

void	free_section_32(t_section_32 *section)
{
	if (!section)
		return ;
	free_section_32(section->next);
	ft_free(section);
}
