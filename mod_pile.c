/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_pile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 14:02:15 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/04 17:19:14 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		abs_val(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

void	get_mod_tab(t_pile *pile)
{
	int i;
	int a;
	int b;

	i = pile->top;
	while (--i >= 0)
	{
			a = pile->pile_tab[i] - i;
			if (pile->pile_tab[i] < pile->top)
				b = a < 0 ? pile->top + a : a - pile->top;
			else
				b = a < 0 ? i + a : a - i;

			//printf("|%d|%d\n", a, b);
			pile->mod_tab[i] = abs_val(a) < abs_val(b) ? a : b;
			if (pile->mod_tab[i] > pile->top - a)
				pile->mod_tab[i] = 0;
			printf("|%d|\n", pile->mod_tab[i]);
	}
}

void	get_mod_tab2(t_pile *pile)
{
	int i;
	int a;
	int b;

	i = pile->top2;
	while (--i >= 0)
	{
			a = (pile->top2 - pile->pile2_tab[i]) - i;
			if (pile->pile2_tab[i] < pile->top2)
				b = a < 0 ? pile->top2 + a : a - pile->top2;
			else
				b = a < 0 ? i + a : a - i;

			if (pile->mod2_tab[i] > pile->top2 - a)
				pile->mod2_tab[i] = 0;
			if (pile->mod_tab[i] > pile->top - a)
				pile->mod_tab[i] = 0;
			//printf("|%d|%d\n", a, b);
			pile->mod2_tab[i] = abs_val(a) < abs_val(b) ? a : b;
			printf("          s  |%d|\n", pile->mod2_tab[i]);
	}
}

void	change_elem_to_index(t_pile *pile)
{
	int i;
	int j;

	i = 0;
	while (i < pile->top)
	{
		j = 0;
		while (pile->pile_tab[i] != pile->qs_pile[pile->top - 1 - j])
			j++;
		pile->pile_tab[i] = j;
		i++;
	}
}

int		*get_qs_pile(t_pile *pile)
{
	int *qs_pile;
	int i;

	i = 0;
	qs_pile = (int *)malloc(sizeof(int) * pile->top);
	while (i < pile->top)
	{
		qs_pile[i] = pile->pile_tab[pile->top - 1 - i];
		i++;
	}
	quick_sort(qs_pile, 0, pile->top - 1);
	i = 0;
	return (qs_pile);
}

int		init_to_qs(t_pile *pile)
{
	pile->qs_pile = get_qs_pile(pile);
	change_elem_to_index(pile);
	pile->mod_tab = (int *)malloc(sizeof(int) * pile->top);
	pile->mod2_tab = (int *)malloc(sizeof(int) * pile->top);
	get_mod_tab(pile);
	return (0);
}
