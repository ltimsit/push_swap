/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 14:19:10 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/02 19:41:27 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	reset_pile_b(t_command *cmd, t_pile *pile)
{
	while (pile->b_min_index)
	{
		if (pile->b_min_index < pile->top2 / 2)
		{
			do_one_cmd(pile, rrb);
			pile->b_min_index++
		}
		else
		{
			do_one_cmd(pile, rb);
			pile->b_min_index += pile->b_min_index ? -1 : pile->top2 - 1;
		}
	}
}

void	check_pile_b(t_command *cmd, t_pile *pile)
{
	int i;
	int j;

	i = 0;
	j = 0;
	reset_pile_b(cmd, pile);
	while (pile->pile2_tab[i] < pile->pile_tab[pile->top - 1])
		i++;
	if (i && i < pile->top2 / 2)
	{
		while (j++ <= i)
		{
			do_one_cmd(pile, rrb);
			pile->b_min_index++;
		}
	}
	else
	{
		while (pile->top2 - j++ > i)
		{
			do_one_cmd(pile, rb);
			pile->b_min_index += pile->b_min_index ? -1 : pile->top2 - 1;
		}
	}
}

void	check_pile_a(t_command *cmd, t_pile *pile)
{
	int a;
	int b;
	int c;

	while (pile->top > 1)
	{
		a = pile->pile_tab[pile->top - 1];
		b = pile->pile_tab[pile->top - 2];
		c = pile->pile_tab[0];

		if (a < b && a < c)
			break ;
		if (b < a && b < c)
		{
			if (a > c)
				do_one_cmd(pile, ra);
			else
				do_one_cmd(pile, sa);
		}
		else if (c < a && c < b)
		{
			if (a > b)
				do_one_cmd(pile, sa);
			do_one_cmd(pile, rra);
		}
	}
}

int calc_cmd()
{
	while (pile->pile1_tab)
	{
		check_pile_a();
		check_pile_b();
		update_cmd_tab();
		do_one_cmd(pile, 4); //pb
	}
}

int test_cmd_rb(t_command *cmd, t_pile *pile, int *cpt)
{
	
}

int test_cmd(t_command *cmd, t_pile *pile)
{
	int cpt;
	int ret;

	ret = 0;
	cpt = 0;
	while (pile->top)
	{
		cpt = test_cmd_rb(cmd, pile, &cpt) ? ret = test_cmd_ra(cmd, pile) : 0;
		cpt = test_cmd_sb(cmd, pile, &cpt) ? ret = test_cmd_sa(cmd, pile) : 0;
//		cpt = test_cmd_rrb(cmd, pile, &cmd) ? test_cmd_rra(cmd, pile) : 0;

		test_cmd_ra(cmd, pile);
		test_cmd_sa(cmd, pile);
	}
}
