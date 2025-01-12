/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utiliz_4_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 12:04:04 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/12 18:23:25 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	*stack = last;
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	stack = NULL;
}

void	error_exit(t_stack **a, t_stack **b, int *arr)
{
	if (arr)
		free(arr);
	free_stack(a);
	free_stack(b);
	write(2, "error\n", 6);
	exit(1);
}

int	is_double(t_stack *stack)
{
	t_stack	*current;
	t_stack	*checker;

	current = stack;
	while (current)
	{
		checker = current->next;
		while (checker)
		{
			if (current->value == checker->value)
				return (1);
			checker = checker->next;
		}
		current = current->next;
	}
	return (0);
}
