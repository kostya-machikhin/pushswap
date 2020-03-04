/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:34:34 by scuger            #+#    #+#             */
/*   Updated: 2020/02/05 15:34:34 by scuger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	visualization(char *str, t_check *check)
{
	t_elem *cur[2];

	cur[0] = check->stack[0].head;
	cur[1] = check->stack[1].head;
	ft_printf("{RED}%21s{RESET}\n", str);
	while (cur[0] || cur[1])
	{
		if (cur[0])
		{
			ft_printf("%14lld", cur[0]->num);
			cur[0] = cur[0]->next;
		}
		else
			ft_printf("%14c", ' ');
		if (cur[1])
		{
			ft_printf("%14lld", cur[1]->num);
			cur[1] = cur[1]->next;
		}
		ft_printf("\n");
	}
	ft_printf("%14_%14_\n{BLUE}%14a%14b{RESET}\n");
	ft_printf("\t{BGGREEN}{BLUE}-------------------------{RESET}{BGRESET}\n");
}

void	create_check_part(t_check *check, int *ac, char ***av)
{
	int pl;
	int i;

	i = 0;
	pl = 0;
	while (++i < *ac)
		if (!ft_strcmp((*av)[i], "-v"))
		{
			check->v = TRUE;
			pl++;
		}
		else if (!ft_strcmp((*av)[i], "-f"))
		{
			if (check->fd != 0)
				close(check->fd);
			check->fd = open((*av)[++i], O_RDONLY);
			pl += 2;
		}
		else
			break ;
	*ac -= pl;
	*av += pl;
}

t_check	create_check(int *ac, char ***av)
{
	t_check	check;
	int		i;

	i = 0;
	check.stack[0] = create_stack();
	check.stack[1] = create_stack();
	check.v = FALSE;
	create_check_part(&check, ac, av);
	return (check);
}

int		checker(int ac, char **av, t_check *check)
{
	char	*str;

	if (!fill_stack(ac, av, &check->stack[0])
	|| check_repeated(&check->stack[0]) || check_maxint(&check->stack[0])
	|| (!check->stack[0].size && !check->stack[1].size))
		return (1);
	if (check->v)
		visualization("DATA", check);
	while (get_next_line(check->fd, &str) > 0)
		if (!do_command(str, check))
			return (1);
	if (!check->stack[0].size || check->stack[1].size)
		ft_putstr("KO\n");
	else
	{
		stack_index(&check->stack[0]);
		distribution_one(&check->stack[0]);
		if (check_dist(&check->stack[0]))
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_check	check;

	if (ac > 1)
	{
		check = create_check(&ac, &av);
		if (check.fd == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (0);
		}
		if (checker(ac, av, &check))
			ft_putstr_fd("Error\n", 2);
		free_stack(&check.stack[0]);
		free_stack(&check.stack[1]);
		close(check.fd);
	}
	return (0);
}
