/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fratajcz <fratajcz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:20:57 by fratajcz          #+#    #+#             */
/*   Updated: 2019/04/06 17:48:30 by fratajcz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	len;
	char	*new;

	len = ft_strnlen(s1, n);
	if (!(new = ft_strnew(len)))
		return (NULL);
	ft_memcpy(new, s1, len);
	new[len] = '\0';
	return (new);
}
