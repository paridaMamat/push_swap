/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaimait <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:58:14 by pmaimait          #+#    #+#             */
/*   Updated: 2022/10/05 10:23:26 by pmaimait         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>

//checker
int		correct_command(char *str, t_stack **stack_a, t_stack **stack_b);
int		check_str(char *str, t_stack **stack_a, t_stack **stack_b);
char	*read_list(char *str);
int		main(int ac, char **av);

//checker_make_list
int		check_list(char *str2, int j);
void	r_rr(char *str2, t_stack **stack_a, t_stack **stack_b);
void	manip_stack(char *str2, t_stack **stack_a, t_stack **stack_b);
void	list_move_stack(char *str, t_stack **stack_a, t_stack **stack_b);

//checker_utils
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	*joint_and_free(char *str, char *buf);
size_t	ft_strlen(char *str);
int		checker_sorted(t_stack **stack);

#endif
