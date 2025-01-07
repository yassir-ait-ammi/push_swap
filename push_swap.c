/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 15:34:48 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/07 21:03:00 by yaait-am         ###   ########.fr       */
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
				printf("error\n");
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

// void	push_swap(t_stack *a, t_stack *b, int len, int *rank)
// {
// 	int i = 0;
// 	int min = 0;
// 	int max = 2;
// 	while (i < len)
// 	{

// 	}
// // }

int main(int ac, char **av)
{
	// handler(ac, av);
	t_stack *stack_a  = NULL;
	int i = 1;
	t_stack *current = NULL;
	while (i < ac)
	{
		t_stack *new_node = ft_lstnew(atoi(av[i]));
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
	sorted(stack_a, ac - 1);
	int b[ac - 1];
	// push_swap(stack_a, stack_b, ac - 2, rank);
}
