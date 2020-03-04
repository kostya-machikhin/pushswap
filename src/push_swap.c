/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:35:38 by scuger            #+#    #+#             */
/*   Updated: 2020/02/05 15:35:38 by scuger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_distribution	create_dist(void (*func) (t_stack *))
{
	t_distribution	dist;

	dist.dist = 0;
	dist.size = 0;
	dist.func = func;
	return (dist);
}

int				push_swap(int ac, char **av, t_distribution *dist)
{
	t_stack			stack[2];

	stack[0] = create_stack();
	stack[1] = create_stack();
	if (ac > 1)
	{
		if (!(fill_stack(ac, av, &stack[0]))
		|| check_repeated(&stack[0]) || check_maxint(&stack[0]))
		{
			free_stack(&stack[0]);
			return (0);
		}
		stack_index(&stack[0]);
		dist->func(&stack[0]);
		push_b(stack, dist);
		push_a(&stack[0], &stack[1], dist);
		scrolling(&stack[0], dist);
		free_stack(&stack[0]);
		free_stack(&stack[1]);
	}
	return (1);
}

int				main(int ac, char **av)
{
	t_distribution	dist[2];
	int				i;

	i = -1;
	dist[0] = create_dist(distribution_one);
	dist[1] = create_dist(distribution_two);
	while (++i < 2)
	{
		if (!push_swap(ac, av, &dist[i]))
		{
			ft_putstr_fd("Error\n", 2);
			break ;
		}
	}
	return_command(dist);
	if (dist[0].dist)
		free(dist[0].dist);
	if (dist[1].dist)
		free(dist[1].dist);
	return (0);
}
