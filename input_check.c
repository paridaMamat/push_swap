/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 15:31:17 by pmaimait          #+#    #+#             */
/*   Updated: 2022/09/20 15:31:38 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_correct_input(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (input_is_number(av[i]) == 0 || not_only_zero(av[i]) == 0
			|| ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	not_only_zero( const char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '0' && !str[i + 1])
		return (1);
	if (str[i] == '0' && str[i + 1] == '.')
		i = i + 2;
	while (str[i] != '\0')
	{
		if (str[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

int	check_double(t_stack **stack_a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp2 = *stack_a;
	while (tmp2->next != NULL)
	{
		tmp = tmp2->next;
		while (tmp)
		{
			if (tmp2->value == tmp->value)
			{
				free_stack(stack_a);
				write(2, "Error\n", 6);
				return (0);
			}
			tmp = tmp->next;
		}
		tmp2 = tmp2->next;
	}
	return (1);
}
