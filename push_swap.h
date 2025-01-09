/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:08:04 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/09 21:47:15 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int	value;
	int	rank;
	struct s_stack	*next;
}	t_stack;

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

t_stack		*ft_lstnew(int value , int rank);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_b, t_stack **stack_a);
void		ra(t_stack **stack_a);
void		rb(t_stack **stack_b);
void		rrb(t_stack **stack);
void		back_to_a(t_stack **b, t_stack **a, int len);
int			ft_sqrt(int nb);
void		sort_3(t_stack *s);
void		sort_2(t_stack *s);
void		sort_4(t_stack **a, t_stack **b);
void		rra(t_stack **stack);
void		sa(t_stack **stack);
void		sb(t_stack **stack);
int			is_sorted(t_stack *a);

#endif
