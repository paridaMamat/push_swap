/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:41:58 by pmaimait          #+#    #+#             */
/*   Updated: 2022/10/03 14:57:02 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				position;
	int				target_position;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

//input_1
void		free_stack(t_stack **stack);
long int	ft_atoi(const char *str);
int			input_is_number(const char *str);
t_stack		*fill_stack_values(int ac, char **av);

//stack
t_stack		*get_stack_last(t_stack *stack);
t_stack		*get_stack_before_last(t_stack *stack);
t_stack		*stack_new(int value);
void		stack_add_tail(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack	*stack);

//index_position
void		assign_index(t_stack **stack_a);

//main
int			main(int ac, char **av);
void		push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size);
int			sorted(t_stack **stack);

//swap
void		swap(t_stack *stack);
void		sa(t_stack **stack_a);

//utils
int			value_abs(int a);
void		ft_putstr(char *s);

//input_check
int			is_correct_input(char **av);
int			not_only_zero(const char *str);
int			check_double(t_stack **stack_a);

//reverse_rotation
void		reverse_rotation(t_stack **stack);
void		rra(t_stack **stack_a);
void		rrb(t_stack **stack_b);
void		rrr(t_stack **stack_a, t_stack **stack_b);

//rotation
void		rotation(t_stack **stack);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rr(t_stack **stack_a, t_stack **stack_b);

//sort_three
int			find_highest_index(t_stack *stack);
void		sort_for_three(t_stack **stack_a);

//cost
void		label_cost(t_stack **stack_a, t_stack **stack_b);
void		find_cheapest_move(t_stack **stack_a, t_stack **stack_b);

//move
void		do_move(t_stack **stack_a, t_stack **stack_b,
				int cost_a, int cost_b);
void		do_rota(t_stack **stack_a, t_stack **stack_b,
				int cost_a, int cost_b);

//position
void		give_position(t_stack **stack);
int			get_target(t_stack **stack_a, int b, int max, int target_pos);
void		give_b_position_in_a(t_stack **stack_a, t_stack **stack_b);

//push
void		push(t_stack **src, t_stack **dest);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);

//sort_three_plus
void		exit_all_and_stay_three(t_stack **stack_a, t_stack **stack_b);
void		roll_stack(t_stack **stack_a);
void		sort_for_more(t_stack **stack_a, t_stack **stack_b);

#endif
