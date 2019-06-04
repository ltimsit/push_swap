/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_calc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 16:42:15 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/05/31 20:10:07 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	remove_duo(t_command *cmd)
{
	int i;

	i = 0;
	ft_printf("HELLO");
	while (i < cmd->size - 1)
	{
		if (cmd->tab[i] == 0 && cmd->tab[i + 1] == 1)
		{
			cmd->tab[i] = 2;
			cmd->tab[i + 1] = -1;
			i++;
		}
		if (cmd->tab[i] == 5 && cmd->tab[i + 1] == 6)
		{
			cmd->tab[i] = 7;
			cmd->tab[i + 1] = -1;
			i++;
		}
		i++;
	}
}

void	reduce_cmd(t_command *cmd, int a, int b)
{
	int i;
	int j;
	int k;
	int cpt;

	i = 0;
	j = 0;
	k = 0;
	cpt = 0;
	while (i < cmd->size)
	{
		while (cmd->tab[i + j] == a)
		{
			cpt++;
			j++;
		}
		while (cmd->tab[i + j] == b && cpt)
		{
			cpt--;
			j++;
		}
		while (k < j && !cpt)
		{
			cmd->tab[i + k] = -1;
			k++;
		}
		cpt = 0;
		j = 0;
		k = 0;
		i++;
	}
}

int		check_rest_pileb(t_pile *pile, t_command *cmd)
{
	int cpt;

	cpt = 0;
	while (cpt < pile->top2 - 1 && pile->pile2_tab[pile->top2 - 1] <
			pile->pile2_tab[pile->top2 - 2])
	{
		do_one_cmd(pile, 1);
		cmd->size++;
		cmd->tab[cmd->size - 1] = 1;
		do_one_cmd(pile, 6);
		cmd->size++;
		cmd->tab[cmd->size - 1] = 6;
		cpt++;
	}
	if (cpt > pile->top2 / 2)
	{
		while (pile->top2 - cpt && pile->top - cpt > 0)
		{
			do_one_cmd(pile, 6);
			cmd->size++;
			cmd->tab[cmd->size - 1] = 6;
			cpt++;
		}
	}
	else
	{
		while (cpt)
		{
			do_one_cmd(pile, 9);
			cmd->size++;
			cmd->tab[cmd->size - 1] = 9;
			cpt--;
		}
	}
	return (1);
}

void	get_next_command(t_command *cmd, t_pile *pile)
{
	int i;
	int ret;
	int force_rb;
	int cpt;

	cpt = 0;
	force_rb = 0;
	ret = 0;
	i = 0;
	while (pile->top)
	{
		if (pile->top > 2 &&
				pile->pile_tab[pile->top - 1] > pile->pile_tab[0])
		{
			ret = do_one_cmd(pile, 5); //ra
			cmd->size++;
			cmd->tab[cmd->size - 1] = 5;
		}
		if (force_rb || (cpt && !force_rb) || (pile->top2 > 1 &&
					pile->pile2_tab[pile->top2 - 1] < pile->pile2_tab[0]))
		{
			if (pile->top2 > 1 &&
					pile->pile2_tab[pile->top2 - 1] < pile->pile2_tab[0])
				force_rb = 1;
			if (!force_rb)
				cpt--;
			ret = do_one_cmd(pile, force_rb ? 6 : 9); //rb / rrb
			cmd->size++;
			cmd->tab[cmd->size - 1] = force_rb ? 6 : 9;
			force_rb = 0;
		}
		if (!ret && pile->top > 1 &&
				pile->pile_tab[pile->top - 1] > pile->pile_tab[pile->top - 2])
		{
			ret = do_one_cmd(pile, 0); //sa
			cmd->size++;
			cmd->tab[cmd->size - 1] = 0;
		}
		if (pile->top2 > 1 &&
				pile->pile2_tab[pile->top2 - 1] < pile->pile2_tab[pile->top2 - 2]
				&& cpt < pile->top2 - 1)
		{
			ret = do_one_cmd(pile, 1); //sb
			cmd->size++;
			cmd->tab[cmd->size - 1] = cpt == pile->top2 - 1 ? 6 : 1;
			cpt += pile->top2 > 2 ? 1 : 0;
			force_rb += pile->top2 > 2 ? 1 : 0;
		}

		if (!ret)
		{
			ret = do_one_cmd(pile, 4); //pb
			cmd->size++;
			cmd->tab[cmd->size - 1] = 4;
		}
		ret = 0;
	}
	while (pile->top2)
	{
		do_one_cmd(pile, 3); //pa
		cmd->size++;
		cmd->tab[cmd->size - 1] = 3;
	}
}
