/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:22:30 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/06/04 13:50:12 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

typedef struct	s_pile
{
	int			max_size;
	int 		*pile_tab;
	int			*pile2_tab;
	int			*mod_tab;
	int			*mod2_tab;
	int			top;
	int			top2;
	int			b_min_index;
}				t_pile;

typedef struct	s_command
{
	int	 		*tab;
	int			size;
	int			*a_tab;
	int			*b_tab;
}				t_command;

enum			e_num
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
};

int				check_commands(t_command *command);
int				check_and_do_commands(t_command *command, t_pile *pile);
void			init_cmd_fct(void);
void			do_cmd(t_pile *pile, t_command *cmd);
void			*ft_realloc(void *ptr, size_t size_old, size_t size_new,
					size_t size_mem);
int				do_one_cmd(t_pile *pile, int index);
void			get_next_command(t_command *cmd, t_pile *pile);
void			reduce_cmd(t_command *cmd, int a, int b);
void			remove_duo(t_command *cmd);

void			(*g_cmd_fct[11])(t_pile *);

#endif
