/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utiliz_6_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:43:52 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/12 18:20:59 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	help_the_help(char **s, t_stack **stack_a, t_stack **current)
{
	t_stack	*new_node;
	int		j;

	j = 0;
	while (s[j] != NULL)
	{
		new_node = ft_lstnew(ft_atoi_2(s[j]), 0);
		if (!*stack_a)
		{
			*stack_a = new_node;
			*current = new_node;
		}
		else
		{
			(*current)->next = new_node;
			*current = new_node;
		}
		j++;
	}
}

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}
