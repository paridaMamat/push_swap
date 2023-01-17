/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:03:52 by pmaimait          #+#    #+#             */
/*   Updated: 2022/09/28 10:30:38 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotation(t_stack **stack)
{
	t_stack	*before_tail;
	t_stack	*tail;
	t_stack	*tmp;

	while (!(*stack) || !(*stack)->next)
		return ;
	tail = get_stack_last(*stack);
	before_tail = get_stack_before_last(*stack);
	tmp = *stack;
	*stack = tail;
	(*stack)->next = tmp;
	before_tail->next = NULL;
}

void	rra(t_stack **stack_a)
{
	reverse_rotation(stack_a);
	ft_putstr("rra\n");
}

void	rrb(t_stack **stack_b)
{
	reverse_rotation(stack_b);
	ft_putstr("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotation(stack_a);
	reverse_rotation(stack_b);
	ft_putstr("rrr\n");
}
