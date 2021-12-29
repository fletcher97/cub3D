/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 01:11:36 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/29 01:11:56 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_pow(double base, double exp)
{
	if (exp == 0)
		return (1);
	if (exp > 0)
		return (base * ft_pow(base, exp - 1));
	else
	{
		base = 1 / base;
		exp *= -1;
		return (base * ft_pow(base, exp - 1));
	}
}
