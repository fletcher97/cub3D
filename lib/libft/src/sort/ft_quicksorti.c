/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksorti.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgueifao <mgueifao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 00:22:34 by mgueifao          #+#    #+#             */
/*   Updated: 2021/05/31 15:49:06 by mgueifao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	swapqs(int *first, int *second)
{
	int	temp;

	temp = *first;
	*first = *second;
	*second = temp;
}

static int	partitionqs(int arr[], int lower, int upper)
{
	int	i;
	int	pivot;
	int	j;

	i = (lower - 1);
	pivot = arr[upper];
	j = lower - 1;
	while (++j < upper)
	{
		if (arr[j] <= pivot)
		{
			i++;
			swapqs(&arr[i], &arr[j]);
		}
	}
	swapqs(&arr[i + 1], &arr[upper]);
	return (i + 1);
}

void	quicksorti(int arr[], int lower, int upper)
{
	int	partition_index;

	if (upper > lower)
	{
		partition_index = partitionqs(arr, lower, upper);
		quicksorti(arr, lower, partition_index - 1);
		quicksorti(arr, partition_index + 1, upper);
	}
}
