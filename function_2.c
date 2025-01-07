/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:15:28 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/06 10:24:27 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(int *stack_a, int *stack_b, int len_a, int len_b)
{
	ra(stack_a, len_a);
	ra(stack_b, len_b);
}

void	rra(int *stack_a, int len)
{
	int	i;
	int	tmp;

	i = len - 1;
	tmp = stack_a[len - 1];
	while (i > 0)
	{
		stack_a[i] = stack_a[i - 1];
		i--;
	}
	stack_a[0] = tmp;
}

void	rrb(int *stack_b, int len)
{
	rra(stack_b, len);
}

void pa(int *stack_a, int *stack_b, int len_a, int len_b)
{
	if (len_b == 0) return;
	for (int i = 0; i < len_a; i++)
	{
		printf(">>>> %d\n", stack_a[i]);
	}
	for (int i = 0; i < len_a; i++)
	{
		stack_a[i + 1] = stack_a[i];
	}

	stack_a[0] = stack_b[0];
	for (int i = 0; i < len_b - 1; i++) {
		stack_b[i] = stack_b[i + 1];
	}
}

// void	pa(int	*stack_a, int *stack_b, int len_a, int len_b)
// {
// 	int	i;

// 	i = len_a;
// 	if (len_b == 0)
// 		return ;
// 	stack_b[len_b - 1] = stack_a[i];
// }

void	pb(int *stack_b, int *stack_a, int len_b, int len_a)
{
	pa(stack_b, stack_a, len_b, len_a);
}
