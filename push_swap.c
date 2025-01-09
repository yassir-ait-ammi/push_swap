/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:34:48 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/09 21:47:06 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorted(t_stack *s_stack ,int size)
{
	int *arr = malloc(size * sizeof(int));

	t_stack *current = s_stack;
	int i = 0;
	while (current)
	{
		arr[i] = current->value;
		i++;
		current = current->next;
	}
	i = 0;
	int j;
	int tmp;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			if (arr[j] == arr[j + 1])
			{
				write(2, "error\n", 7);
				exit(1);
			}
			j++;
		}
		i++;

	}
	j = 0;
	current = s_stack;
	while (current)
	{
		j = 0;
		while (j < size)
		{
			if (arr[j] == current->value)
			{
				current->rank = j;
				break ;
			}
			j++;
		}
		current = current->next;
	}
}

void	push_swap(t_stack *a, t_stack *b, int len)
{
	int min = 0;
	int max = (ft_sqrt(len + 1) + ((len + 1) / 500) + 5);
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
			ra(&a);
	}
	t_stack *curent = b;
	back_to_a(&curent, &a, len);
}

void back_to_a(t_stack **b, t_stack **a, int len) {
	int size, position;
	t_stack *curent;

	while (len >= 0)
	{
		curent = *b;
		position = 0;
		while (curent)
		{
			if (curent->rank == len)
				break;
			curent = curent->next;
			position++;
		}
		size = 0;
		curent = *b;
		while (curent)
		{
			curent = curent->next;
			size++;
		}
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
		pa(a, b);
		len--;
	}
}

void	handler(t_stack *a, int ac, t_stack *b)
{
	if (ac <= 2)
		exit(1);
	else if (ac == 3)
		sort_2(a);
	else if (ac == 4)
		sort_3(a);
	else if (ac == 5)
		sort_4(&a, &b);
	// else if (ac == 6)
	// 	sorte_5(s);
}

int main(int ac, char **av)
{
	if (ac == 2)
		return(0);
	t_stack *stack_a  = NULL;
	int i = 1;
	t_stack *current = NULL;
	while (i < ac)
	{
		t_stack *new_node = ft_lstnew(atoi(av[i]), 0);
		if (!stack_a)
		{
			stack_a = new_node;
			current = new_node;
		}
		else
		{
			current->next = new_node;
			current = new_node;
		}
		i++;
	}
	if (is_sorted(stack_a))
		return(1);
	t_stack *stack_b = NULL;
	handler(stack_a, ac, stack_b);
	sorted(stack_a, ac - 1);
	push_swap(stack_a, stack_b, ac - 2);
}
