/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utiliz_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 17:30:56 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/15 09:50:58 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "sa\n", 3);
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
	write(1, "sb\n", 3);
}

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		if (a->value == a->next->value)
			error_exit(&a, NULL, 0);
		a = a->next;
	}
	return (1);
}

void	sort_5(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		min_value;
	int		min_index;
	int		i;

	if (!a || !*a)
		return ;
	temp = *a;
	min_value = temp->value;
	min_index = 0;
	i = 0;
	while (temp)
	{
		if (temp->value < min_value)
		{
			min_value = temp->value;
			min_index = i;
		}
		temp = temp->next;
		i++;
	}
	help_sort_5(min_index, a, b);
}

void	help_sort_5(int min_index, t_stack **a, t_stack **b)
{
	int	rotations;

	if (!a || !*a || !b)
		return ;
	if (min_index < 0 || min_index > 4)
		return ;
	if (min_index <= 2)
	{
		rotations = min_index;
		while (rotations--)
			ra(a);
	}
	else
	{
		rotations = 5 - min_index;
		while (rotations--)
			rra(a);
	}
	pb(a, b);
	sort_4(a, b);
	pa(b, a);
}
