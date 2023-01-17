/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:07:41 by pmaimait          #+#    #+#             */
/*   Updated: 2022/09/28 10:11:17 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_move(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(stack_a, stack_b);
		(cost_a)++;
		(cost_b)++;
	}
	while (cost_a < 0)
	{
		rra(stack_a);
		(cost_a)++;
	}
	while (cost_b < 0)
	{
		rrb(stack_b);
		(cost_b)++;
	}
	do_rota(stack_a, stack_b, cost_a, cost_b);
	pa(stack_a, stack_b);
	return ;
}

void	do_rota(t_stack **stack_a, t_stack **stack_b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(stack_a, stack_b);
		(cost_a)--;
		(cost_b)--;
	}
	while ((cost_a) > 0)
	{
		ra(stack_a);
		(cost_a)--;
	}
	while ((cost_b) > 0)
	{
		rb(stack_b);
		(cost_b)--;
	}
}
