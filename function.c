/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:07:49 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/07 18:29:17 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(int *stack_a)
{
	int	tmp;

	tmp = stack_a[0];
	stack_a[0] = stack_a[1];
	stack_a[1] = tmp;
}

void	sb(int *stack_b)
{
	sa(stack_b);
}

void	ss(int *stack_a, int *stack_b)
{
	sa(stack_a);
	sa(stack_b);
}

void	ra(int *stack_a, int len)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stack_a[0];
	while (i < len - 1)
	{
		stack_a[i] = stack_a[i + 1];
		i++;
	}
	stack_a[i] = tmp;
}

void	rb(int *stack_b, int len)
{
	ra(stack_b, len);
}

t_stack	*ft_lstnew(int value)
{
	t_stack	*yas;

	yas = malloc(sizeof(t_stack));
	if (!yas)
		return (NULL);
	yas->value = value;
	yas->next = NULL;
	return (yas);
}
