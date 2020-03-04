/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:35:04 by scuger            #+#    #+#             */
/*   Updated: 2020/02/05 17:41:10 by scuger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		check_maxint(t_stack *stack)
{
	t_elem *cur;

	cur = stack->head;
	while (cur)
	{
		if (cur->num > 2147483647 || cur->num < -2147483648)
			return (1);
		cur = cur->next;
	}
	return (0);
}

int		check_repeated(t_stack *stack)
{
	t_elem	*cur;
	t_elem	*next;

	cur = stack->head;
	while (cur)
	{
		next = cur->next;
		while (next)
		{
			if (cur->num == next->num)
				return (1);
			next = next->next;
		}
		cur = cur->next;
	}
	return (0);
}

void	free_nums(char **nums)
{
	int i;

	i = 0;
	while (nums[i])
		free(nums[i++]);
	free(nums);
}

int		checkdigit(char **av, int ac)
{
	int length;
	int i;
	int j;

	j = 0;
	while (++j < ac)
	{
		length = ft_strlen(av[j]);
		i = -1;
		if (av[j][0] == ' ' || av[j][ft_strlen(av[j]) - 1] == ' ')
			return (0);
		while (++i < length)
			if (!ft_isdigit(av[j][i]) &&
			!(av[j][i] == '-' && ft_isdigit(av[j][i + 1])))
				return (0);
	}
	return (1);
}

t_stack	*fill_stack(int ac, char **av, t_stack *stack)
{
	char	**nums;
	int		size;
	int		i;
	int		j;

	if (checkdigit(av, ac))
	{
		j = 0;
		while (++j < ac)
		{
			if (!*av[j])
				return (0);
			size = 0;
			i = -1;
			nums = ft_strsplit(av[j], ' ');
			while (nums[size])
				size++;
			while (++i < size)
				stack = add_elem(stack, newelem(ft_atoi_ps(nums[i])));
			free_nums(nums);
		}
		return (stack);
	}
	return (0);
}
