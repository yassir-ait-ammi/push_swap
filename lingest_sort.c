/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lingest_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaait-am <yaait-am@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:10:18 by yaait-am          #+#    #+#             */
/*   Updated: 2025/01/04 19:31:04 by yaait-am         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	set(int len, int *index, int *sort, int *arr)
{
	int	a[2];

	a[0] = 0;
	a[1] = 0;
	while (a[1] < len)
	{
		index[a[1]] = 1;
		sort[a[1]] = -1;
		a[1]++;
	}
	a[1] = 1;
	while (a[1] < len)
	{
		a[0] = 0;
		while (a[0] < a[1])
		{
			if (arr[a[1]] > arr[a[0]] && index[a[1]] < index[a[0]] + 1)
			{
				index[a[1]] = index[a[0]] + 1;
				sort[a[1]] = a[0];
			}
			a[0]++;
		}
		a[1]++;
	}
}

void	backtrack(int *a, int *lis, int *sort, int *arr)
{
	int	i;

	i = a[2];
	a[3] = a[1] - 1;
	while (i >= 0)
	{
		lis[a[3]--] = arr[i];
		if (sort[i] == -1)
			break ;
		i = sort[i];
	}
}

void	alloc(int len, int **index, int **sort)
{
	*index = malloc(sizeof(int) * len);
	if (!*index)
		return ;
	*sort = malloc(sizeof(int) * len);
	if (!*sort)
		return ;
}

int	*lis(int *arr, int len, int	*lis)
{
	int	*index;
	int	*sort;
	int	a[4];

	a[0] = 0;
	a[1] = 0;
	a[2] = 0;
	lis = malloc(sizeof(int) * a[1]);
	alloc(len, &index, &sort);
	if (!sort || !index || !lis)
		return (NULL);
	set(len, index, sort, arr);
	while (a[0] < len)
	{
		if (index[a[0]] > a[1])
		{
			a[1] = index[a[0]];
			a[2] = a[0];
		}
		a[0]++;
	}
	return (backtrack(a, lis, sort, arr), lis);
}

// int main()
// {
// 	int arr[12] = {1, 45, 7, 8, 10, 7, 6, 54, 15, 87, 1, 65};
//     int a = sizeof(arr) / sizeof(arr[0]);  // Corrected size calculation

// 	int *s = lis(arr, a, s);
// 	int i = 0;
// 	while (i < 7)
// 	{
// 		printf(" -- %d -- ", s[i]);
// 		i++;
// 	}
// }
