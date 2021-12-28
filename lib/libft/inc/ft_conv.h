/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 15:58:16 by mgueifao          #+#    #+#             */
/*   Updated: 2021/05/31 01:45:50 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONV_H
# define FT_CONV_H

# define HEX_L "0123456789abcdef"
# define HEX_U "0123456789ABCDEF"
# define OCT "01234567"
# define DEC "0123456789"

char	*ft_itoa_base(int n, const char *base);
char	*ft_itoa(int n);
char	*ft_ltoa_base(long l, const char *base);
char	*ft_ltoa(long l);
char	*ft_uitoa_base(unsigned int n, const char *base);
char	*ft_uitoa(unsigned int n);
char	*ft_ultoa_base(unsigned long l, const char *base);
char	*ft_ultoa(unsigned long l);

#endif
