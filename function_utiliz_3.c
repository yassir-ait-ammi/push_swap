/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utiliz_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:07:49 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/09 21:37:28 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lstnew(int value, int rank)
{
	t_stack	*yas;

	yas = malloc(sizeof(t_stack));
	if (!yas)
		return (NULL);
	yas->value = value;
	yas->rank = rank;
	yas->next = NULL;
	return (yas);
}

int ft_sqrt(int nb)
{
	float i = 1;

	if (nb < 0)
		return 0;

	while (i <= nb / i)
	{
		if (i * i == nb)
			return i;
		i += 0.1;
	}
	return i;
}

void	sort_2(t_stack *s)
{
	ra(&s);
	exit(1);
}

void sort_3(t_stack *s)
{
	t_stack *a = s;

	while (a)
	{
		/* code */
	}
	
 	exit(1);
}

void sort_4(t_stack **a, t_stack **b)
{
	t_stack *min = *a;
	t_stack *temp = *a;
	while (temp) {
		if (temp->value < min->value)
			min = temp;
		temp = temp->next;
	}
	if (min == (*a)->next->next->next)
		rra(a);
	else if (min == (*a)->next->next)
		rra(a), rra(a);
	else if (min == (*a)->next)
		sa(a);
	pb(a, b);
	sort_3(*a);
	pa(a, b);
	exit(1);
}

