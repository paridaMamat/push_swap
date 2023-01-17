/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:16:11 by pmaimait          #+#    #+#             */
/*   Updated: 2022/09/08 11:16:35 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp && tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !sorted(stack_a))
		sa(stack_a);
	else if (stack_size == 3 && !sorted(stack_a))
		sort_for_three(stack_a);
	else if (stack_size > 3 && !sorted(stack_a))
		sort_for_more(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (ac < 2)
		return (0);
	stack_b = NULL;
	if (!is_correct_input(av))
		return (0);
	stack_a = fill_stack_values(ac, av);
	if (!check_double(&stack_a))
		return (0);
	stack_size = ac - 1;
	assign_index(&stack_a);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
