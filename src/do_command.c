/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:34:57 by scuger            #+#    #+#             */
/*   Updated: 2020/02/05 15:34:57 by scuger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		do_command_part(char *str, t_check *check)
{
	if (!ft_strcmp(str, "sa"))
		swap(&check->stack[0], NULL, 't');
	else if (!ft_strcmp(str, "ra"))
		rotate(&check->stack[0], NULL, 't');
	else if (!ft_strcmp(str, "pa"))
		push(&check->stack[1], &check->stack[0], NULL, 't');
	else if (!ft_strcmp(str, "rra"))
		reverse_rotate(&check->stack[0], NULL, 't');
	else if (!ft_strcmp(str, "sb"))
		swap(&check->stack[1], NULL, 't');
	else if (!ft_strcmp(str, "rb"))
		rotate(&check->stack[1], NULL, 't');
	else if (!ft_strcmp(str, "pb"))
		push(&check->stack[0], &check->stack[1], NULL, 't');
	else
		return (0);
	return (1);
}

int		do_command(char *str, t_check *check)
{
	if (do_command_part(str, check))
		;
	else if (!ft_strcmp(str, "rrb"))
		reverse_rotate(&check->stack[1], NULL, 't');
	else if (!ft_strcmp(str, "rr"))
		rr(&check->stack[0], &check->stack[1], NULL);
	else if (!ft_strcmp(str, "rrr"))
		rrr(&check->stack[0], &check->stack[1], NULL);
	else
	{
		free(str);
		return (0);
	}
	if (check->v)
		visualization(str, check);
	free(str);
	return (1);
}
