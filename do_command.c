/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 16:26:29 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/05/28 13:17:04 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	c_sa(t_pile *pile)
{
	unsigned long	i;
	int				*elem1;
	int				*elem2;

	if (pile->top >= 2)
	{
		elem1 = pile->pile_tab + pile->top - 1;
		elem2 = pile->pile_tab + pile->top - 2;
		i = 0;
		while (i < sizeof(*(pile->pile_tab)))
		{
			ft_memswap((void *)elem1 + i, (void *)elem2 + i);
			i++;
		}
	}
}

void	c_sb(t_pile *pile)
{
	unsigned long	i;
	int				*elem1;
	int				*elem2;

	if (pile->top2 >= 2)
	{
		elem1 = pile->pile2_tab + pile->top2 - 1;
		elem2 = pile->pile2_tab + pile->top2 - 2;
		i = 0;
		while (i < sizeof(*(pile->pile2_tab)))
		{
			ft_memswap((void *)elem1 + i, (void *)elem2 + i);
			i++;
		}
	}
}

void	c_ss(t_pile *pile)
{
	c_sa(pile);
	c_sb(pile);
}

void	c_pa(t_pile *pile)
{
	int *elem1;
	int *elem2;

	if (pile->top2 > 0)
	{
		pile->top++;
		elem1 = pile->pile2_tab + pile->top2 - 1;
		elem2 = pile->pile_tab + pile->top - 1;
		ft_memcpy(elem2, elem1, sizeof(pile->pile_tab));
		pile->top2--;
	}
}

void	c_pb(t_pile *pile)
{
	int *elem1;
	int *elem2;

	if (pile->top > 0)
	{
		pile->top2++;
		elem1 = pile->pile_tab + pile->top - 1;
		elem2 = pile->pile2_tab + pile->top2 - 1;
		ft_memcpy(elem2, elem1, sizeof(pile->pile2_tab));
		pile->top--;
	}
}

void	c_ra(t_pile *pile)
{
	unsigned long	i;
	int				*elem1;
	int				*elem2;
	int				buff_top;

	buff_top = pile->top - 1;
	if (pile->top >= 2)
	{
		while (buff_top)
		{
			i = -1;
			elem1 = pile->pile_tab + buff_top;
			elem2 = pile->pile_tab + buff_top - 1;
			while (++i < sizeof(*(pile->pile_tab)))
				ft_memswap((void *)elem1 + i, (void *)elem2 + i);
			buff_top--;
		}
	}
}

void	c_rb(t_pile *pile)
{
	unsigned long	i;
	int				*elem1;
	int				*elem2;
	int				buff_top;

	buff_top = pile->top2 - 1;
	if (pile->top2 >= 2)
	{
		i = -1;
		elem1 = pile->pile2_tab + buff_top;
		elem2 = pile->pile2_tab;
		while (++i < sizeof(*(pile->pile2_tab)))
			ft_memswap((void *)elem1 + i, (void *)elem2 + i);
		while (buff_top > 1)
		{
			i = -1;
			elem1 = pile->pile2_tab + buff_top;
			elem2 = pile->pile2_tab + buff_top - 1;
			while (++i < sizeof(*(pile->pile2_tab)))
				ft_memswap((void *)elem1 + i, (void *)elem2 + i);
			buff_top--;
		}
	}
}

void	c_rr(t_pile *pile)
{
	c_ra(pile);
	c_rb(pile);
}

void	c_rra(t_pile *pile)
{
	unsigned long	i;
	int				j;
	int				*elem1;
	int				*elem2;
	int				buff_top;

	buff_top = pile->top - 1;
	if (pile->top >= 2)
	{
		j = 0;
		while (j < buff_top)
		{
			i = -1;
			elem1 = pile->pile_tab + j;
			elem2 = pile->pile_tab + j + 1;
			while (++i < sizeof(*(pile->pile_tab)))
				ft_memswap((void *)elem1 + i, (void *)elem2 + i);
			j++;
		}
	}
}

void	c_rrb(t_pile *pile)
{
	unsigned long	i;
	int				j;
	int				*elem1;
	int				*elem2;
	int				buff_top;

	buff_top = pile->top2 - 1;
	if (pile->top2 >= 2)
	{
		j = 0;
		while (j < buff_top)
		{
			i = -1;
			elem1 = pile->pile2_tab + j;
			elem2 = pile->pile2_tab + j + 1;
			while (++i < sizeof(*(pile->pile2_tab)))
				ft_memswap((void *)elem1 + i, (void *)elem2 + i);
			j++;
		}
	}
}

void	c_rrr(t_pile *pile)
{
	c_rra(pile);
	c_rrb(pile);
}

void	do_cmd(t_pile *pile, t_command *cmd)
{
	int i;

	i = 0;
	while (i < cmd->size)
	{
		g_cmd_fct[cmd->tab[i]](pile);
		i++;
	}
}

void	init_cmd_fct(void)
{
	g_cmd_fct[0] = c_sa;
	g_cmd_fct[1] = c_sb;
	g_cmd_fct[2] = c_ss;
	g_cmd_fct[3] = c_pa;
	g_cmd_fct[4] = c_pb;
	g_cmd_fct[5] = c_ra;
	g_cmd_fct[6] = c_rb;
	g_cmd_fct[7] = c_rr;
	g_cmd_fct[8] = c_rra;
	g_cmd_fct[9] = c_rrb;
	g_cmd_fct[10] = c_rrr;
}
