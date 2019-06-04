/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:37:58 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/01 15:33:59 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
void	free_all(char **tab, size_t size)
{
	while (size)
		free(tab[--size]);
	free(tab);
}
*/

void	init_ctab(char **tab)
{
	tab[0] = "sa";
	tab[1] = "sb";
	tab[2] = "ss";
	tab[3] = "pa";
	tab[4] = "pb";
	tab[5] = "ra";
	tab[6] = "rb";
	tab[7] = "rr";
	tab[8] = "rra";
	tab[9] = "rrb";
	tab[10] = "rrr";
}

int		check_line(char *line)
{
	char	*command_tab[11];
	int		i;

	i = 0;
	init_ctab(command_tab);
	while (i < 11)
		if (!(strcmp(line, command_tab[i++])))
			return (i - 1);
	return (-1);
}

void	*ft_realloc(void *ptr, size_t size_old, size_t size_new,
		size_t size_mem)
{
	void	*ptrnew;
	int		i;
	size_t	size;

	size = size_old < size_new ? size_old : size_new;
	i = 0;
	if (!(ptrnew = malloc(size_mem * size_new)))
		return (NULL);
	if (size_old)
		ft_memcpy(ptrnew, ptr, size * size_mem);
	free(ptr);
	return (ptrnew);
}

int		check_commands(t_command *command)
{
	int		ret;
	int		index;
	char	*line;
	int		*tab;
	size_t	size_tab;

	tab = NULL;
	size_tab = 0;
//	do_one_cmd(pile, command, -1);
	while ((ret = get_next_line(0, &line)))
	{
		if (ret == (-1) || (index = check_line(line)) == -1)
		{
			free(tab);
			free(line);
			return (0);
		}
		tab = (int *)ft_realloc(tab, size_tab, size_tab + 1, sizeof(*tab));
		tab[size_tab] = index;
//		do_one_cmd(pile, command, index);
		free(line);
		size_tab++;
	}
	command->tab = tab;
	command->size = size_tab;
	return (1);
}

int		check_and_do_commands(t_command *command, t_pile *pile)
{
	int		ret;
	int		index;
	char	*line;
	int		*tab;
	size_t	size_tab;

	tab = NULL;
	size_tab = 0;
	do_one_cmd(pile, -1);
	while ((ret = get_next_line(0, &line)))
	{
		if (ret == (-1) || (index = check_line(line)) == -1)
		{
			free(tab);
			free(line);
			return (0);
		}
		tab = (int *)ft_realloc(tab, size_tab, size_tab + 1, sizeof(*tab));
		tab[size_tab] = index;
		free(line);
		size_tab++;
		do_one_cmd(pile, index);
		printf("NB CMD = %zu\n", size_tab);
	}
	command->tab = tab;
	command->size = size_tab;
	return (1);
}

/*
int main()
{
	t_command command;
	int i;

	i = 0;
	command.size = 0;
	printf("%d\n", check_commands(&command));
	while (i < command.size)
	{
		printf("%d\n", command.tab[i]);
		i++;
	}
	return (0);
}
*/
