/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utiliz_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:07:49 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/14 13:57:44 by yaait-am         ###   ########.fr       */
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

int	ft_sqrt(int nb)
{
	float	i;

	i = 1;
	if (nb < 0)
		return (0);
	while (i <= nb / i)
	{
		if (i * i == nb)
			return (i);
		i += 0.1;
	}
	return (i);
}

int	is_double(t_stack *a)
{
	t_stack	*tmp;

	tmp = a;
	while (tmp && tmp->next)
	{
		if (tmp->value == tmp->next->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	sort_3(t_stack **s)
{
	t_stack	*a;

	a = *s;
	while (!is_sorted(a))
	{
		if (a->value > a->next->value && a->value > a->next->next->value)
			ra(s);
		else if (a->next->value > a->value
			&& a->next->value > a->next->next->value)
			rra(s);
		if ((*s)->value > (*s)->next->value)
			sa(s);
	}
	return ;
}

void	sort_4(t_stack **a, t_stack **b)
{
	t_stack	*min;
	t_stack	*temp;

	min = *a;
	temp = *a;
	while (temp)
	{
		if (temp->value < min->value)
			min = temp;
		temp = temp->next;
	}
	if (min == (*a)->next->next->next)
		rra(a);
	else if (min == (*a)->next->next)
	{
		rra(a);
		rra(a);
	}
	else if (min == (*a)->next)
		sa(a);
	pb(a, b);
	sort_3(a);
	pa(b, a);
	return ;
}
