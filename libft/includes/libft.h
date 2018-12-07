/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcozic <bcozic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:51:01 by bcozic            #+#    #+#             */
/*   Updated: 2018/12/07 08:49:12 by bcozic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include "ft_printf.h"
# include "ft_libc.h"

# define BUFF_SIZE	256
# define STR_HEXA	"0123456789ABCDEF"

int					ft_nbrlen(long long n);
int					ft_isint(char *str);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
int					ft_memcmp(void *s1, void *s2, size_t n);
int					ft_tab_strlen(char **str);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(char *s, int c);
char				*ft_strrchr(char *s, int c);
char				*ft_strstr(char *haystack, const char *needle);
char				*ft_strnstr(char *haystack,
		const char *needle, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
unsigned int		ft_atoi_unsigned(const char *str);
int					ft_issignnb(int c);
int					ft_isspace(int c);
int					ft_isnum(char *str);
int					ft_isstr_f(char *str, int(*f)(int c));
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinflush(char **s1, char const *s2);
char				*ft_strnjoinflush(char **s1, char const *s2, size_t len);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putstr(char const *s);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_strup(char *str);
int					get_next_line(const int fd, char **line);
void				ft_free_and_reset(int nb, ...);
void				ft_putsizet(size_t n);

/*
**	sources asm
*/

void				*ft_bzero(void *s, size_t n);
char				*ft_strcat(char *restrict s1, const char *restrict s2);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_puts(const char *s);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memcpy(void *restrict dst, const void *restrict src,
		size_t n);
char				*ft_strdup(const char *s1);
void				ft_cat(const int fd);
int					ft_abs(int i);
void				*ft_memchr(const void *s, int c, size_t n);
char				*ft_strncat(char *restrict s1, const char *restrict s2,
		size_t n);
size_t				ft_strlen(const char *s);

#endif
