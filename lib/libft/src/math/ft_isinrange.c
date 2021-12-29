/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinrange.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 15:12:50 by mgueifao          #+#    #+#             */
/*   Updated: 2021/12/29 15:13:59 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_isinrange(double value, double v1, double v2)
{
	if (v1 < v2)
		return (value >= v1 && value <= v2);
	return (value >= v2 && value <= v1);
}
