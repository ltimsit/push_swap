/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 16:22:30 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/05/27 20:46:51 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# include "get_next_line.h"

typedef struct	s_pile
{
	int 		*pile_tab;
	int			*pile2_tab;
	int			top;
	int			top2;
}				t_pile;

typedef struct	s_command
{
	int	 		*tab;
	int			size;
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
void			init_cmd_fct(void);
void			do_cmd(t_pile *pile, t_command *cmd);
void			*ft_realloc(void *ptr, size_t size_old, size_t size_new,
					size_t size_mem);

void			(*g_cmd_fct[11])(t_pile *);

#endif
