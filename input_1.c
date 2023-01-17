/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 11:16:47 by pmaimait          #+#    #+#             */
/*   Updated: 2022/09/08 11:17:22 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

long int	ft_atoi(const char *str)
{
	long int	r;
	int			i;
	int			s;

	i = 0;
	r = 0;
	s = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			r = r * 10 + str[i] - '0';
		else
			break ;
		i++;
	}
	return (s * r);
}

int	input_is_number(const char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '0' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (1);
	if (str[i] == '.' && (str[i - 1] >= '0' && str[i - 1] <= '9'))
	{
		i++;
		while (str[i] >= '0' && str[i] <= '9')
		{
			i++;
			if (str[i] == '\0')
				return (1);
		}
	}
	return (0);
}

t_stack	*fill_stack_values(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (i == 1)
			stack_a = stack_new((int)nb);
		else
			stack_add_tail(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}
