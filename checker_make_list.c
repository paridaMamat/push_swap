/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_make_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:05:23 by pmaimait          #+#    #+#             */
/*   Updated: 2022/10/03 14:04:34 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_list(char *str2, int j)
{
	str2[j] = '\0';
	if (ft_strcmp(str2, "pa") == 0 || ft_strcmp(str2, "pb") == 0
		|| ft_strcmp(str2, "sa") == 0 || ft_strcmp(str2, "sb") == 0
		|| ft_strcmp(str2, "ss") == 0 || ft_strcmp(str2, "ra") == 0
		|| ft_strcmp(str2, "rb") == 0 || ft_strcmp(str2, "rr") == 0
		|| ft_strcmp(str2, "rra") == 0 || ft_strcmp(str2, "rrb") == 0
		|| ft_strcmp(str2, "rrr") == 0)
		return (1);
	else
		return (0);
}

void	r_rr(char *str2, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(str2, "ra") == 0)
		return (rotation(stack_a));
	if (ft_strcmp(str2, "rb") == 0)
		return (rotation(stack_b));
	if (ft_strcmp(str2, "rr") == 0)
	{
		rotation(stack_a);
		rotation(stack_b);
		return ;
	}
	if (ft_strcmp(str2, "rra") == 0)
		return (reverse_rotation(stack_a));
	if (ft_strcmp(str2, "rrb") == 0)
		return (reverse_rotation(stack_b));
	if (ft_strcmp(str2, "rrr") == 0)
	{
		reverse_rotation(stack_a);
		reverse_rotation(stack_b);
		return ;
	}
}

void	manip_stack(char *str2, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(str2, "pa") == 0)
		return (push(stack_b, stack_a));
	if (ft_strcmp(str2, "pb") == 0)
		return (push(stack_a, stack_b));
	if (ft_strcmp(str2, "sa") == 0)
		return (swap(*stack_a));
	if (ft_strcmp(str2, "sb") == 0)
		return (swap(*stack_b));
	if (ft_strcmp(str2, "ss") == 0)
	{
		swap(*stack_a);
		swap(*stack_b);
		return ;
	}
	r_rr(str2, stack_a, stack_b);
}

void	list_move_stack(char *str, t_stack **stack_a, t_stack **stack_b)
{
	char	*str2;
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		str2 = malloc(sizeof(char) * 4);
		if (!str2)
			return ;
		if (str[i] == '\n')
			i++;
		while (str[i] != '\n' && str[i])
			str2[j++] = str[i++];
		str2[j] = '\0';
		manip_stack(str2, stack_a, stack_b);
		free (str2);
		i++;
	}
	free(str);
}
