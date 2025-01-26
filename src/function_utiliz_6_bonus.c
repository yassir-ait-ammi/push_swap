/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utiliz_6_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 17:43:52 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/20 09:28:54 by yaait-am         ###   ########.fr       */
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
		new_node = ft_lstnew(ft_atoi_2(s[j], &s, stack_a), 0);
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

void	parsing_1(int ac, char **av)
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
		if (av[i][0] == '\0')
			error_exit(NULL, NULL, 0);
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		if (av[i][j] == '\0')
			a++;
		while (av[i][j] >= '0' && av[i][j] <= '9')
			j++;
		if (!(av[i][j] >= '0' && av[i][j] <= '9')
		&& (av[i][j] != '\0') && av[i][j] != ' ')
			a++;
		i++;
	}
	if (a > 0)
		error_exit(NULL, NULL, 0);
}

void	parsing_2(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] == ' ' || (av[i][j] >= 9 && av[i][j] <= 13))
				j++;
			if (av[i][j] == '+' || av[i][j] == '-')
				j++;
			while (av[i][j] != '\0' && ('0' <= av[i][j] && av[i][j] <= '9'))
				j++;
			if (!('0' <= av[i][j] || av[i][j] <= '9') && av[i][j] != ' ')
				error_exit(NULL, NULL, 0);
			j++;
		}
		i++;
	}
}

void	saver(char **s, t_stack **a, t_stack **b)
{
	free(*s);
	get_next_line(-2);
	error_exit(a, b, 0);
}
