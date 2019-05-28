/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltimsit- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:30:45 by ltimsit-          #+#    #+#             */
/*   Updated: 2019/05/26 15:02:16 by ltimsit-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	process_line(char **line, char **lines, char **buffline, char *posn)
{
	if (posn)
	{
		if (!(*line = ft_strndup(*lines, posn - *lines)))
			return (-1);
		if (!(*buffline = ft_strdup(posn + 1)))
			return (-1);
		free(*lines);
		*lines = *buffline;
		return (1);
	}
	if (**lines)
	{
		if (!(*line = ft_strdup(*lines)))
			return (-1);
		free(*lines);
		*lines = NULL;
		return (1);
	}
	free(*lines);
	*lines = NULL;
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char		*lines[OPEN_MAX];
	int				r;
	char			buffer[BUFF_SIZE + 1];
	char			*buffline;
	char			*posn;

	r = 0;
	if (fd < 0 || fd > OPEN_MAX || BUFF_SIZE <= 0 || !line
			|| (!lines[fd] && !(lines[fd] = ft_strnew(0))))
		return (-1);
	while (!(posn = ft_strchr(lines[fd], '\n'))
			&& (r = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[r] = '\0';
		if (!(buffline = ft_strjoin(lines[fd], buffer)))
			return (-1);
		free(lines[fd]);
		lines[fd] = buffline;
	}
	if (r < 0)
		return (-1);
	return (process_line(line, &lines[fd], &buffline, posn));
}
