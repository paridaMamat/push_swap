/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:17:07 by pmaimait          #+#    #+#             */
/*   Updated: 2022/09/27 15:17:49 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	label_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*a;
	t_stack	*b;
	int		size_a;
	int		size_b;

	a = *stack_a;
	b = *stack_b;
	size_a = get_stack_size(a);
	size_b = get_stack_size(b);
	while (b)
	{
		b->cost_b = b->position;
		if (b->position > size_b / 2)
			b->cost_b = (size_b - b->position) * -1;
		b->cost_a = b->target_position;
		if (b->target_position > size_a / 2)
			b->cost_a = (size_a - b->target_position) * -1;
		b = b->next;
	}
}

void	find_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	b = *stack_b;
	cheapest = INT_MAX;
	while (b)
	{
		if (value_abs(b->cost_a) + value_abs(b->cost_b) < value_abs(cheapest))
		{
			cheapest = value_abs(b->cost_b) + value_abs(b->cost_a);
			cost_a = b->cost_a;
			cost_b = b->cost_b;
		}
		b = b->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}
