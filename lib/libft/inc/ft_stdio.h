/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 20:15:07 by mgueifao          #+#    #+#             */
/*   Updated: 2021/03/03 19:06:58 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define FD_MAX_COUNT 4096

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		get_next_line(int fd, char **line);

#endif
