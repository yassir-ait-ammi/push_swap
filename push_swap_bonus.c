/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:04:50 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/14 16:19:08 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/push_swap_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && (s1[i] && s2[i]) && i < n)
		i++;
	if (i == n)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	prepare(char *s, t_stack **a, t_stack **b)
{
	if (ft_strncmp (s, "pa\n", 4) == 0)
		pa(a, b);
	else if (ft_strncmp (s, "pb\n", 4) == 0)
		pb(a, b);
	else if (ft_strncmp (s, "ra\n", 4) == 0)
		ra(a);
	else if (ft_strncmp (s, "rb\n", 4) == 0)
		rb(b);
	else if (ft_strncmp (s, "rra\n", 5) == 0)
		rra(a);
	else if (ft_strncmp (s, "rrb\n", 5) == 0)
		rrb(b);
	else if (ft_strncmp (s, "sa\n", 4) == 0)
		sa(a);
	else if (ft_strncmp (s, "sb\n", 4) == 0)
		sb(b);
	else if (ft_strncmp (s, "rr\n", 4) == 0)
		rr(a, b);
	else if (ft_strncmp (s, "rrr\n", 5) == 0)
		rrr(a, b);
	else if (ft_strncmp (s, "ss\n", 4) == 0)
		ss(a, b);
	else
		error_exit(a, b, 0);
}

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

void	help_main(int ac, char **av, t_stack **stack_a)
{
	int		i;
	t_stack	*current;
	char	**s;
	int		j;

	i = 1;
	current = NULL;
	*stack_a = NULL;
	parsing_1(ac, av);
	parsing_2(ac, av);
	while (i < ac)
	{
		s = ft_split(av[i], ' ');
		help_the_help(s, stack_a, &current);
		j = 0;
		while (s[j] != NULL)
		{
			free(s[j]);
			j++;
		}
		free(s);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*s;

	if (ac < 2)
		return (1);
	b = NULL;
	help_main(ac, av, &a);
	if (is_double(a))
		error_exit(&a, &b, 0);
	if (is_sorted(a))
		return (free_stack(&a), 1);
	while (1)
	{
		s = get_next_line(0);
		if (!s)
			break ;
		prepare(s, &a, &b);
		free(s);
	}
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_stack(&a), free_stack(&b), 0);
}
