/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:31:26 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/05 16:09:51 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strnlen(const char *s, size_t maxlen)
{
	unsigned int i;

	i = 0;
	while (s[i] && i < maxlen)
		i++;
	return (i);
}
