/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 14:03:46 by mgueifao          #+#    #+#             */
/*   Updated: 2021/03/03 19:10:28 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDLIB_H
# define FT_STDLIB_H

# include <stddef.h>

int		ft_abs(int x);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_free(void *ptr);
void	*ft_malloc(size_t size);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
void	ft_swap(void *e1, void *e2, size_t size);
void	*ft_realloc(void *ptr, size_t osize, size_t nsize);

#endif
