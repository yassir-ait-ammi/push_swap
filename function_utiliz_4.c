/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utiliz_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 10:30:56 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/14 16:37:01 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	write(1, "rrb\n", 4);
	*stack = last;
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

void	error_exit(t_stack **a, t_stack **b, int *arr)
{
	if (arr != 0)
		free(arr);
	free_stack(a);
	free_stack(b);
	write(2, "error\n", 6);
	exit(1);
}

int	ft_atoi(char *str, t_stack **a)
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
	if (str[i] == '\0' || str[i] == '-' || str[i] == '+')
		error_exit(a, NULL, 0);
	while (str[i] != '\0' && ('0' <= str[i] && str[i] <= '9'))
	{
		yas = (yas * 10 + (str[i] - 48));
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		error_exit(a, NULL, 0);
	if (str[i] != '\0' || (yas * sir) > 2147483647 || (yas * sir) < -2147483648)
		error_exit(a, NULL, 0);
	return ((int)yas * sir);
}

void	parsing(int ac, char **av)
{
	int	i;
	int	j;
	int	a;

	i = 1;
	j = 0;
	a = 0;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		if (av[i][j] == '\0')
			a++;
		i++;
	}
	if (a > 0)
		error_exit(NULL, NULL, 0);
}
