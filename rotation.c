/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:45:42 by pmaimait          #+#    #+#             */
/*   Updated: 2022/09/28 10:32:55 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotation(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	while (!(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_stack_last(*stack);
	tail->next = tmp;
	tmp->next = NULL;
}

void	ra(t_stack **stack_a)
{
	rotation(stack_a);
	ft_putstr("ra\n");
}

void	rb(t_stack **stack_b)
{
	rotation(stack_b);
	ft_putstr("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotation(stack_a);
	rotation(stack_b);
	ft_putstr("rr\n");
}
