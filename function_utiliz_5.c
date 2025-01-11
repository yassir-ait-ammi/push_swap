/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utiliz_5.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:11:14 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/11 11:00:27 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	help_sorted(int size, int *arr, t_stack **s_stack)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] == arr[j + 1])
				error_exit(s_stack, NULL, arr);
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	help2_sorted(t_stack **current, int size, int *arr)
{
	int	j;

	while (*current)
	{
		j = 0;
		while (j < size)
		{
			if (arr[j] == (*current)->value)
			{
				(*current)->rank = j;
				break ;
			}
			j++;
		}
		*current = (*current)->next;
	}
}

int	help_back(t_stack **b, int len, int *position, int size)
{
	t_stack	*curent;

	curent = *b;
	while (curent)
	{
		if (curent->rank == len)
			break ;
		curent = curent->next;
		(*position)++;
	}
	size = 0;
	curent = *b;
	while (curent)
	{
		curent = curent->next;
		size++;
	}
	return (size);
}

void	help_main(int ac, char **av, t_stack **stack_a)
{
	int		i;
	t_stack	*new_node;
	t_stack	*current;

	i = 1;
	current = NULL;
	while (i < ac)
	{
		new_node = ft_lstnew(ft_atoi(av[i]), 0);
		if (!new_node)
			error_exit(stack_a, NULL, NULL);
		if (!*stack_a)
		{
			*stack_a = new_node;
			current = new_node;
		}
		else
		{
			current->next = new_node;
			current = new_node;
		}
		i++;
	}
}

void	find_pos(t_stack **a, int len, int min, int max)
{
	t_stack	*tmp;
	int		pos;

	tmp = *a;
	pos = 0;
	while (tmp)
	{
		if (tmp->rank >= min && tmp->rank <= max)
			break ;
		tmp = tmp->next;
		pos++;
	}
	if (pos <= len / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		while (pos++ < len)
			rra(a);
	}
}
