/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utiliz_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:15:28 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/10 15:47:48 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = *b;
		*b = tmp;
	}
	write(1, "pb\n", 3);
}

void	ra(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*tmp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	tmp = *stack_a;
	while (tmp->next)
		tmp = tmp->next;
	*stack_a = first->next;
	first->next = NULL;
	tmp->next = first;
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack)
{
	t_stack	*top;
	t_stack	*current;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	top = *stack;
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = top;
	*stack = top->next;
	write(1, "rb\n", 3);
	top->next = NULL;
}

void	rra(t_stack **stack)
{
	t_stack	*second_last;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	second_last = NULL;
	last = *stack;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	write(1, "rra\n", 4);
	*stack = last;
}
