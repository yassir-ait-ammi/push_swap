/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:34:48 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/14 15:59:04 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorted(t_stack *s_stack, int size)
{
	t_stack	*current;
	int		*arr;
	int		i;

	arr = malloc(size * sizeof(int));
	if (!arr)
		error_exit(&s_stack, NULL, NULL);
	current = s_stack;
	i = 0;
	while (current)
	{
		arr[i] = current->value;
		i++;
		current = current->next;
	}
	help_sorted(size, arr, &s_stack);
	current = s_stack;
	help2_sorted(&current, size, arr);
	if (arr)
		free (arr);
}

void	push_swap(t_stack *a, t_stack *b, int len)
{
	int	min;
	int	max;

	min = 0;
	max = (ft_sqrt(len + 1) + ((len + 1) / 500) + 5);
	while (a)
	{
		if (a->rank >= min && a->rank <= max)
		{
			pb(&a, &b);
			min++;
			max++;
		}
		else if (a->rank < min)
		{
			pb(&a, &b);
			rb(&b);
			min++;
			max++;
		}
		else
			find_pos(&a, len, min, max);
	}
	back_to_a(&b, &a, len);
}

void	back_to_a(t_stack **b, t_stack **a, int len)
{
	int	position;
	int	size;

	while (len >= 0)
	{
		position = 0;
		size = help_back(b, len, &position, size);
		if (position <= size / 2)
		{
			while ((*b)->rank != len)
				rb(b);
		}
		else
		{
			while ((*b)->rank != len)
				rrb(b);
		}
		pa(b, a);
		len--;
	}
	free_stack(a);
}

void	handler(t_stack **a, int ac, t_stack **b)
{
	if (ac == 3)
	{
		ra(a);
		return ;
	}
	else if (ac == 4)
	{
		sort_3(a);
	}
	else if (ac == 5)
	{
		sort_4(a, b);
	}
	else if (ac == 6)
	{
		sort_5(a, b);
	}
	free_stack(a);
	free_stack(b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	parsing(ac, av);
	if (ac == 2)
		return (ft_atoi(av[1], &stack_a));
	help_main_1(ac, av, &stack_a);
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		free_stack(&stack_b);
		return (1);
	}
	sorted(stack_a, ac - 1);
	if (ac <= 6)
		return (handler(&stack_a, ac, &stack_b), 1);
	push_swap(stack_a, stack_b, ac - 2);
	free_stack(&stack_b);
	return (0);
}
