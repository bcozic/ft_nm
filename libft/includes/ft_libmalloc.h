/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libmalloc.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 22:37:53 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/08 11:31:19 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBMALLOC_H
# define FT_LIBMALLOC_H

# include "libft.h"
# include <unistd.h>
# include <sys/mman.h>
# include <sys/resource.h>
# include <pthread.h>

# define TINY_PK	16
# define SMALL_PK	512

typedef struct				s_mem
{
	void					*ptr;
	size_t					size;
	struct s_mem			*next;
}							t_mem;

typedef struct				s_zone
{
	t_mem					*page;
	t_mem					*packet;
	t_mem					*used_packet;
	size_t					size_packet_zone;
}							t_zone;

typedef struct				s_data
{
	size_t					pages_size;
	t_zone					tiny;
	t_zone					small;
	t_zone					large;
	t_zone					data_page;
	struct rlimit			rlimit_memlock;
	size_t					allocate_size;
}							t_data;

extern						t_data* g_data;
extern pthread_mutex_t		g_mutex;

void						*ft_malloc(size_t size);
void						*ft_calloc(size_t count, size_t size);
void						*ft_valloc(size_t size);
void						ft_free(void *ptr);
void						*ft_realloc(void *ptr, size_t size);
void						*ft_reallocf(void *ptr, size_t size);
int							init_data(size_t pages_size);
void						*get_new_struct(size_t size);
void						*get_alloc(size_t size, t_zone *zone,
									size_t nb_page);
t_mem						*get_new_page(t_zone *zone, size_t nb_pages);
void						remove_struct(t_mem *packet);
t_mem						*insert_new_element(t_mem **list_ptr,
									t_mem *new_ptr);
void						*get_memory(t_zone *zone, t_mem *previous,
									t_mem *packet, size_t size);
int							cut_end_packet(t_mem *packet, size_t size);
void						unmap_at_exit(void) __attribute__((destructor));
int							chr_allocation(void *ptr, t_zone *zone);
t_mem						*find_packet(void *ptr, t_zone *zone);

#endif
