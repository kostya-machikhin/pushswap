/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scuger <scuger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 15:36:33 by scuger            #+#    #+#             */
/*   Updated: 2020/02/05 15:36:33 by scuger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TRUE 1
# define FALSE 0

# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"
# include <unistd.h>

typedef struct	s_elem
{
	long long		num;
	int				index;
	int				dist;
	struct s_elem	*next;
	struct s_elem	*prev;
}				t_elem;

typedef struct	s_stack
{
	t_elem	*head;
	t_elem	*tail;
	int		size;
}				t_stack;

typedef struct	s_check
{
	t_stack			stack[2];
	unsigned char	v : 1;
	int				fd;
}				t_check;

typedef struct	s_command
{
	int stack_a;
	int stack_b;
	int same;
	int sum;
}				t_command;

typedef struct	s_distribution
{
	void	(*func) (t_stack *);
	int		*dist;
	int		size;
}				t_distribution;

/*
 ** stack
*/
t_stack			create_stack(void);
t_stack			*add_elem(t_stack *stack, t_elem *newelem);
t_elem			*newelem(long long data);
void			free_stack(t_stack *stack);

/*
 **create_stack
*/
int				checkdigit(char **av, int ac);
t_stack			*fill_stack(int ac, char **av, t_stack *stack);
int				check_repeated(t_stack *stack);
int				check_maxint(t_stack *stack);
void			free_nums(char **nums);

int				push_swap(int ac, char **av, t_distribution *dist);
void			clean_dist(t_stack *stack);
void			stack_index(t_stack *stack);
void			distribution_one(t_stack *stack);
void			distribution_two(t_stack *stack);
t_distribution	create_dist(void (*func) (t_stack *));
void			add_command(t_distribution *dist, int command);

/*
 **commands
*/
void			swap(t_stack *stack, t_distribution *dist, char name);
void			push(t_stack *first_stack,
		t_stack *second_stack, t_distribution *dist, char name);
void			rotate(t_stack *stack, t_distribution *dist, char name);
void			reverse_rotate(t_stack *stack, t_distribution *dist, char name);
void			rr(t_stack *first_stack,
		t_stack *second_stack, t_distribution *dist);
void			rrr(t_stack *first_stack,
		t_stack *second_stack, t_distribution *dist);
void			return_command(t_distribution *dist);
void			print_command(int *array, int index);

/*
 **push_b
*/
void			rotate_dist(t_stack *stack, t_distribution *dist,
		void (*f1) (t_stack *, t_distribution *, char),
		void (*f2) (t_stack *, t_distribution *, char));
int				find_first_dist(t_stack *stack);
int				check_dist(t_stack *stack);
void			push_b(t_stack *stack, t_distribution *dist);

/*
 **swap_needed
*/
int				sum_dist(t_stack *stack);
int				swap_needed(t_stack *stack_a, t_distribution *dist, char name);
int				*sn_array(t_stack *stack);
void			sn_dist_before(t_stack *stack, const int *d);

/*
 **num_of_command
*/
t_command		*num_command(t_stack *stack_a, t_stack *stack_b);
int				command_sum(t_command command);
int				command_same(t_command command);
int				max_stack_a(t_stack *stack);
void			command_stack_a(int index,
		t_stack *stack_a, t_command *command);
void			command_stack_b(int i, t_stack *stack_b, t_command *command);

/*
 **push_a
*/
void			push_a(t_stack *stack_a,
		t_stack *stack_b, t_distribution *dist);
void			decryption(t_command command,
		t_stack *stack_a, t_stack *stack_b, t_distribution *dist);
t_command		find_min_command(t_command *commands, int size);

/*
 **scrolling
*/
void			scrolling(t_stack *stack_a, t_distribution *dist);
int				find_min(t_stack *stack_a);

/*
 **checker
*/
int				do_command(char *str, t_check *check);
int				do_command_part(char *str, t_check *check);
int				checker(int ac, char **av, t_check *check);
void			visualization(char *str, t_check *check);
t_check			create_check(int *ac, char ***av);
void			create_check_part(t_check *check, int *ac, char ***av);

long long		ft_atoi_ps(const char *str);

#endif
