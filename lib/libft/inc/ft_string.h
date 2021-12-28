/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 20:22:26 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/25 21:51:10 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include <stddef.h>

typedef unsigned char	t_uc;

void	ft_bzero(void *s, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup(const char *s);
int		ft_strendw(const char *str, const char *end);
int		ft_strichr(const char *str, const char c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strncat(char *dest, const char *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strpbrk(const char *s1, const char *s2);
char	*ft_strrchr(const char *s, int c);
char	*ft_strrev(char *str);
char	*ft_strsjoin(int size, char **strs, char *sep);
int		ft_strstartw(const char *str, const char *start);
char	*ft_strtok(char *str, const char *delim);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_strwcnt(const char *str, const char *delim);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
