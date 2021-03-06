/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 16:35:10 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/05/31 13:08:13 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_int(char *str, int sign)
{
	char *int_max;
	char *int_min;

	int_max = "2147483647";
	int_min = "2147483648";
	if (ft_strcmp(sign == -1 ? int_min : int_max, str) < 0)
		return (0);
	return (1);
}

int check_str(char *str)
{
	int i;
	int j;
	int sign;
	char *trim_str;

	sign = 1;
	j = 0;
	i = 0;
	if (!(trim_str = ft_strtrim(str)))
		return (0);
	if ((trim_str[j] == '-' || trim_str[j] == '+') &&
			trim_str[j + 1] >= '0' && trim_str[j + 1] <= '9')
		sign = 44 - trim_str[j++];
	if (trim_str[j] < '0' || trim_str[j] > '9')
	{
		free(trim_str);
		return (0);
	}
	while (trim_str[j] == '0')
		j++;
	while ((trim_str[j + i] >= '0') && (trim_str[j + i] <= '9'))
		i++;
	if (i > 10 || trim_str[j + i] || (i == 10 && !(check_int(trim_str + j, sign))))
	{
		free(trim_str);
		return (0);
	}
	free(trim_str);
	return (1);
}

int	check_double(int *pile_tab, int size)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (pile_tab[i] == pile_tab[j++])
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_nbr(int c, char **v, t_pile *pile)
{
	int i;

	i = 0;
	if (!(pile->pile_tab = (int *)malloc(sizeof(int) * c - 1)))
		return (0);
	while (i < c - 1)
	{
		if (!(check_str(v[i + 1])))
		{
			free(pile->pile_tab);
			return (0);
		}
		pile->pile_tab[c - 2 - i] = ft_atoi(v[i + 1]);
		i++;
	}
	if (!(check_double(pile->pile_tab, c - 1)))
	{
		free(pile->pile_tab);
		return (0);
	}
	return (1);
}

void print(t_pile *pile, t_command *cmd)
{
	int i;
	int nb;

	nb = 0;
	printf("top = %d\n", pile->top);
	i = pile->top;
	while (i--)
	{
		printf("|%10d|\n", pile->pile_tab[i]);
	}
	i = 0;
	while (i < cmd->size)
	{
		if (cmd->tab[i] != -1)
		{
			printf("command |%10d|\n", cmd->tab[i]);
			nb++;
		}
		i++;
	}
	ft_printf("total = %d\n", nb);
}

int	main(int argc, char **argv)
{
	int			nb_cpt;
	t_pile		pile;
	t_command	command;

	command.tab = (int *)malloc(sizeof(int) * 1000);
	command.size = 0;
	pile.top = argc - 1;
	pile.max_size = argc - 1;
	pile.top2 = 0;
	nb_cpt = 0;
	if (argc == 1)
		return (0);
	init_cmd_fct();
	pile.pile2_tab = (int *)malloc(sizeof(int) * argc - 1);
	if (argc < 2 || !(check_nbr(argc, argv, &pile)))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	get_next_command(&command, &pile);
	reduce_cmd(&command, 4, 3);
	reduce_cmd(&command, 6, 9);
	remove_duo(&command);
	print(&pile, &command);
	return (0);
}
