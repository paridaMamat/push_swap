/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 10:35:33 by pmaimait          #+#    #+#             */
/*   Updated: 2022/09/12 10:36:01 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack_a;
	tmp2 = *stack_a;
	while (tmp2)
	{
		while (tmp)
		{
			if (tmp2->value > tmp->value)
				tmp2->index = tmp2->index + 1;
			tmp = tmp->next;
		}
		tmp = *stack_a;
		tmp2 = tmp2->next;
	}
}
