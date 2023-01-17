/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_plus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:53:21 by pmaimait          #+#    #+#             */
/*   Updated: 2022/09/28 10:49:24 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h" 

void	exit_all_and_stay_three(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	stack_size;
	int	pushed;

	stack_size = get_stack_size(*stack_a);
	i = 0;
	pushed = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		i++;
	}
	while ((stack_size - pushed) > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

void	roll_stack(t_stack **stack_a)
{
	int		stack_size;
	t_stack	*a;
	int		i;

	i = 0;
	stack_size = get_stack_size(*stack_a);
	a = *stack_a;
	while (a)
	{
		if (a->index == 1)
			break ;
		a = a->next;
		i++;
	}
	if (i > stack_size / 2)
	{
		while (i < stack_size)
		{
			rra(stack_a);
			i++;
		}
	}
	else
		while (i-- > 0)
			ra(stack_a);
}

void	sort_for_more(t_stack **stack_a, t_stack **stack_b)
{
	exit_all_and_stay_three(stack_a, stack_b);
	sort_for_three(stack_a);
	while (*stack_b)
	{
		give_b_position_in_a(stack_a, stack_b);
		label_cost(stack_a, stack_b);
		find_cheapest_move(stack_a, stack_b);
	}
	if (!sorted(stack_a))
		roll_stack(stack_a);
}
