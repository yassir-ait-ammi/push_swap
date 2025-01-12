/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utiliz_3_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:03:05 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/12 18:09:25 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/push_swap_bonus.h"

void	sa(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sb(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*b)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = *a;
		*a = tmp;
	}
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
}
