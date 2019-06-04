/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:38:04 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/04 14:35:31 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int g_i = 0;

int partition(int *array, int start, int end)
{
	int pivot;
	int p_index;
	int i;
	int j;
	int *e1;
	int *e2;

	pivot = array[end];
	p_index = start;
	i = start;
	j = 0;
	while (i <= end)
	{
		if (array[i] < pivot || i == end)
		{
			e1 = array + i;
			e2 = array + p_index;
			if (e1 != e2)
			{
				while (j < 4)
				{
					ft_memswap((void *)e1 + j, (void *)e2 + j);
					j++;
				}
				//g_i++;
				j = 0;
			}
			p_index += i != end ? 1 : 0;
		}
		i++;
	}
	return (p_index);
}

int quick_sort(int *array, int start, int end)
{
	int p_index;

	if (start >= end)
		return (0);
	p_index = partition(array, start, end);
	quick_sort(array, start, p_index - 1);
	quick_sort(array, p_index + 1, end);
	return (0);
}

/*
int main()
{
	int tab[10];
	int i;

	i = 0;
	tab[0] = 7;
	tab[1] = 2;
	tab[2] = 1;
	tab[3] = 6;
	tab[4] = 8;
	tab[5] = 5;
	tab[6] = 3;
	tab[7] = 4;
	quick_sort(tab, 0, 7);
	while (i < 8)
	{
		printf("tab[%d] = %d\n", i, tab[i]);
		i++;
	}
	printf("%d\n", g_i);
	return (0);
}
*/
