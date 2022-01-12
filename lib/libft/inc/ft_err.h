/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:42:25 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/12 01:09:30 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERR_H
# define FT_ERR_H

typedef struct s_err
{
	int				code;
	char			*desc;
	struct s_err	*next;
}				t_err;

t_err	*p_get_err(void);
void	p_clear_err(void);

int		add_err(int code, char *desc);
void	exit_err(int code);
char	*get_err(int code);
int		load_err(char *path);
int		print_err(int code, int fd);
int		set_err(int code, char *desc);

#endif //FT_ERR_H
