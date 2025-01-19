/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utiliz_7.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 10:47:22 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/19 11:13:36 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	j;

	j = 0;
	if (!split)
		return ;
	while (split[j])
	{
		free(split[j]);
		j++;
	}
	free(split);
}

static int	count_words(int ac, char **av)
{
	int		i;
	int		j;
	int		new_ac;
	char	**split;

	new_ac = 1;
	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		if (!split)
			return (0);
		j = 0;
		while (split[j])
		{
			new_ac++;
			j++;
		}
		free_split(split);
		i++;
	}
	return (new_ac);
}

static char	**fill_new_av(int ac, char **av, int new_ac)
{
	int		i;
	int		j;
	int		k;
	char	**split;
	char	**new_av;

	new_av = malloc(sizeof(char *) * (new_ac + 1));
	if (!new_av)
		return (NULL);
	new_av[0] = ft_strdup("./push_swap");
	k = 1;
	i = 1;
	while (i < ac)
	{
		split = ft_split(av[i], ' ');
		j = 0;
		while (split[j])
			new_av[k++] = ft_strdup(split[j++]);
		free_split(split);
		i++;
	}
	return (new_av[k] = NULL, new_av);
}

void	parsing_3(int *ac, char ***av)
{
	int		new_ac;
	char	**new_av;

	new_ac = count_words(*ac, *av);
	if (new_ac == 0)
		return ;
	new_av = fill_new_av(*ac, *av, new_ac);
	if (!new_av)
		return ;
	*av = new_av;
	*ac = new_ac;
}

void	parsing_4(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] && av[i][j] == ' ')
			j++;
		if (av[i][j] == '\0')
			error_exit(NULL, NULL, 0, NULL);
		i++;
	}
}
