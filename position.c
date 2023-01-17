/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:32:05 by pmaimait          #+#    #+#             */
/*   Updated: 2022/09/28 10:24:01 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_position(t_stack **stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->position = i;
		tmp = tmp->next;
		i++;
	}
}

int	get_target(t_stack **stack_a, int b, int max, int target_pos)
{
	t_stack	*a;

	a = *stack_a;
	while (a)
	{
		if (a->index > b && a->index < max)
		{
			max = a->index;
			target_pos = a->position;
		}
		a = a->next;
	}
	if (max != INT_MAX)
		return (target_pos);
	a = *stack_a;
	while (a)
	{
		if (a->index < max)
		{
			max = a->index;
			target_pos = a->position;
		}
		a = a->next;
	}
	return (target_pos);
}

void	give_b_position_in_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;
	int		target_pos;

	b = *stack_b;
	give_position(stack_a);
	give_position(&b);
	target_pos = 0;
	while (b)
	{
		target_pos = get_target(stack_a, b->index, INT_MAX, target_pos);
		b->target_position = target_pos;
		b = b->next;
	}
}
