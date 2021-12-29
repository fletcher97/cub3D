/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memutils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:31:46 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/29 15:32:57 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMUTILS_H
# define FT_MEMUTILS_H

void	ft_free_matrix_s(void **matrix, int count, void (*del)(void *));
void	ft_free_matrix(void **matrix, void (*del)(void *));

#endif //FT_MEMUTILS_H
