/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:34:46 by scuger            #+#    #+#             */
/*   Updated: 2020/02/05 15:34:46 by scuger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *first_stack, t_stack *second_stack, t_distribution *dist)
{
	rotate(first_stack, dist, 't');
	rotate(second_stack, dist, 't');
	add_command(dist, 9);
}

void	rrr(t_stack *first_stack, t_stack *second_stack, t_distribution *dist)
{
	reverse_rotate(first_stack, dist, 't');
	reverse_rotate(second_stack, dist, 't');
	add_command(dist, 10);
}
