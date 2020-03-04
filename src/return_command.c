/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:35:43 by scuger            #+#    #+#             */
/*   Updated: 2020/02/05 15:35:43 by scuger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_command(int *array, int index)
{
	if (array[index] == 1)
		ft_putstr("sa\n");
	else if (array[index] == 2)
		ft_putstr("sb\n");
	else if (array[index] == 3)
		ft_putstr("pa\n");
	else if (array[index] == 4)
		ft_putstr("pb\n");
	else if (array[index] == 5)
		ft_putstr("ra\n");
	else if (array[index] == 6)
		ft_putstr("rb\n");
	else if (array[index] == 7)
		ft_putstr("rra\n");
	else if (array[index] == 8)
		ft_putstr("rrb\n");
	else if (array[index] == 9)
		ft_putstr("rr\n");
	else if (array[index] == 10)
		ft_putstr("rrr\n");
}

void	return_command(t_distribution *dist)
{
	int *array;
	int size;
	int i;

	i = 0;
	array = dist[0].size < dist[1].size ? dist[0].dist : dist[1].dist;
	size = dist[0].size < dist[1].size ? dist[0].size : dist[1].size;
	while (i < size)
	{
		print_command(array, i);
		i++;
	}
}
