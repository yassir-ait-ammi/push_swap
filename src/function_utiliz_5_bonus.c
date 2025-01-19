/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utiliz_5_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 16:28:15 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/19 18:56:16 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
	*stack = last;
}

int	ft_atoi_2(char *str, char ***s, t_stack **a)
{
	int		i;
	long	yas;
	int		sir;

	i = 0;
	sir = 1;
	yas = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sir = -sir;
		i++;
	}
	while (str[i] != '\0' && ('0' <= str[i] && str[i] <= '9'))
	{
		if ((yas * sir) > 2147483647 || (yas * sir) < -2147483648)
		{
			free(*s);
			saver(&str, a, NULL);
		}
		yas = (yas * 10 + (str[i] - 48));
		i++;
	}
	return ((int)yas * sir);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
