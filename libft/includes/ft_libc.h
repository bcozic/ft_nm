/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:41:57 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/13 13:42:38 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBC_H
# define FT_LIBC_H

void						*ft_malloc(size_t size);
void						*ft_calloc(size_t count, size_t size);
void						*ft_valloc(size_t size);
void						ft_free(void *ptr);
void						*ft_realloc(void *ptr, size_t size);
void						*ft_reallocf(void *ptr, size_t size);

#endif
