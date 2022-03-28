/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 00:28:20 by mgueifao          #+#    #+#             */
/*   Updated: 2022/01/14 00:28:21 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "c3d_map.h"
#include "errors.h"
#include "ft_string.h"
#include "ft_stdlib.h"
#include "ft_math.h"

/*
 *	Counts the number of characters 'chr' in the string 'str'. In this case, the
 *	character of interest is the comma, which splits the RGB channels.
 */

int	ft_strchr_all(char *str, char chr)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == chr)
			count++;
		i++;
	}
	return (count);
}

/*
 *	Gets a string with the R,G,B color values separated by commas (ex: 255,255,
 *	255). Starts by checking if the string has the correct number of commas (2
 *	in this case, as the number of channels is 3), otherwise the map is invalid.
 *	Splits the colors string using the comma char as the separator.
 *	Converts the channel value from string to int, and if on the correct range,
 *	adds it to *color using a bitwise operation.
*/

int	load_color(int *color, char *comma_sep_channels)
{
	char	**temp;
	int		i;
	int		number;

	if (ft_strchr_all(comma_sep_channels, ',') != NUMBER_OF_CHANNELS - 1)
		return (INVALID_MAP);
	temp = ft_split(comma_sep_channels, ',');
	if (!temp)
		return (FAILED_MALLOC);
	*color = 0;
	i = -1;
	while (++i < NUMBER_OF_CHANNELS)
	{
		number = ft_atoi(temp[i]);
		if (!ft_isinrange(number, 0, 255))
		{
			free_split(temp);
			return (INVALID_MAP);
		}
		*color += number << (BITS_PER_BYTE * (2 - i));
	}
	free_split(temp);
	return (SUCCESSFUL_IMPORT);
}
