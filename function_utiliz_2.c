/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utiliz_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:15:28 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/09 18:27:27 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_b)
		return;
	t_stack *new_node = malloc(sizeof(t_stack));
	if (!new_node)
		exit(1);
	new_node->value = (*stack_b)->value;
	new_node->rank = (*stack_b)->rank;
	new_node->next = *stack_a;

	*stack_a = new_node;
	t_stack *temp = *stack_b;
	*stack_b = (*stack_b)->next;
	write(1, "pa\n", 3);
	free(temp);
}

void pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!*stack_a)
		return;
	t_stack *new_node = malloc(sizeof(t_stack));
	if (!new_node)
		exit(1);
	new_node->value = (*stack_a)->value;
	new_node->rank = (*stack_a)->rank;
	new_node->next = *stack_b;

	*stack_b = new_node;
	t_stack *temp = *stack_a;
	*stack_a = (*stack_a)->next;
	write(1, "pb\n", 3);
	free(temp);
}

void ra(t_stack **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return;

	t_stack *first = *stack_a;
	t_stack *temp = *stack_a;
	while (temp->next)
		temp = temp->next;

	*stack_a = first->next;
	first->next = NULL;
	temp->next = first;
	write(1, "ra\n", 3);
}

void rb(t_stack **stack)
{
	t_stack *top;
	t_stack *current;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return;
	}
	top = *stack;
	current = *stack;
	while (current->next != NULL)
		current = current->next;
	current->next = top;
	*stack = top->next;
	write(1, "rb\n", 3);
	top->next = NULL;
}

void rra(t_stack **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	t_stack *second_last = NULL;
	t_stack *last = *stack;
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

void rrb(t_stack **stack)
{
	if (*stack == NULL || (*stack)->next == NULL)
		return;
	t_stack *second_last = NULL;
	t_stack *last = *stack;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	write(1, "rrb\n", 4);
	*stack = last;
}
