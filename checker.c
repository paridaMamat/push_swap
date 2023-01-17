/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:56:49 by pmaimait          #+#    #+#             */
/*   Updated: 2022/10/03 13:49:50 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	correct_command(char *str, t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		j;
	char	str2[4];

	i = 0;
	while (str[i])
	{
		j = 0;
		if (str[i] == '\n')
			i++;
		while (str[i] != '\n' && str[i] && j < 4)
			str2[j++] = str[i++];
		if ((str[i] && str[i] != '\n') || (check_list(str2, j) == 0))
		{
			free_stack(stack_a);
			free_stack(stack_b);
			write(2, "Error\n", 6);
			free(str);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_str(char *str, t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '\n' && str[i + 1] == '\n') || str[0] == '\n')
		{
			free_stack(stack_a);
			free_stack(stack_b);
			write(2, "Error\n", 6);
			free(str);
			return (0);
		}
		i++;
	}
	return (1);
}

char	*read_list(char *str)
{
	int		read_size;
	char	buf[4];

	read_size = 1;
	while (read_size != 0)
	{
		read_size = read(0, buf, 4);
		if (read_size < 0)
			return (NULL);
		buf[read_size] = '\0';
		str = joint_and_free(str, buf);
	}
	return (str);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*str;

	if (ac < 2)
		return (0);
	stack_b = NULL;
	str = '\0';
	if (!is_correct_input(av))
		return (0);
	stack_a = fill_stack_values(ac, av);
	if (!check_double(&stack_a))
		return (0);
	str = read_list(str);
	if (check_str(str, &stack_a, &stack_b) == 0
		|| correct_command(str, &stack_a, &stack_b) == 0)
		return (0);
	list_move_stack(str, &stack_a, &stack_b);
	if (!checker_sorted(&stack_a) || stack_b)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
