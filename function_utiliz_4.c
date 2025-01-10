/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utiliz_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:30:56 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/10 16:07:23 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_stack **stack)
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
	write(1, "rrb\n", 4);
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
