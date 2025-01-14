/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:08:04 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/14 10:51:57 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_stack
{
	int				value;
	int				rank;
	struct s_stack	*next;
}	t_stack;

t_stack		*ft_lstnew(int value, int rank);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_b, t_stack **stack_a);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rrb(t_stack **stack);
void		rra(t_stack **stack);
void		sa(t_stack **stack);
void		sb(t_stack **stack);
void		back_to_a(t_stack **b, t_stack **a, int len);
int			ft_sqrt(int nb);
void		sort_3(t_stack *s);
void		sort_2(t_stack *s);
void		sort_4(t_stack **a, t_stack **b);
void		sort_5(t_stack **a, t_stack **b);
void		help_sort_5(int min_index, t_stack **a, t_stack **b);
int			is_sorted(t_stack *a);
void		free_stack(t_stack **stack);
void		error_exit(t_stack **a, t_stack **b, int *arr);
void		help_sorted(int size, int *arr, t_stack **s_stack);
void		help2_sorted(t_stack **current, int size, int *arr);
int			help_back(t_stack **b, int len, int *position, int size);
void		help_main_1(int ac, char **av, t_stack **stack_a);
void		find_pos(t_stack **a, int len, int min, int max);
int			ft_atoi(char *str, t_stack **a);
void		parsing(int ac, char **av);

#endif
