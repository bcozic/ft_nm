/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_endianness.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 11:41:14 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/10 11:51:11 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nm_otool.h"

int	get_endianness(uint32_t magic_nbr)
{
	if (magic_nbr == FAT_CIGAM || magic_nbr == FAT_CIGAM_64
			|| magic_nbr == MH_CIGAM_64 || magic_nbr == MH_CIGAM)
		return (IS_BIG_ENDIAN);
	return (IS_LITTLE_ENDIAN);
}
