/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 17:22:20 by fdeage            #+#    #+#             */
/*   Updated: 2015/04/25 13:31:18 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Tests dest unless src is null
** Returns a mallocked string so beware of potential mem leaks
*/

char	*ft_strsub(char const *src, unsigned int start, size_t len)
{
	char			*dest;
	register size_t	i;
	size_t			min;

	if (!src || !src[start] || !len)
		return (NULL);
	min = ft_min(len, ft_strlen(src));
	min = ft_max(min, 0);
	if (!(dest = (char *)malloc(sizeof(char) * (min + 1))))
		return (NULL);
	i = 0;
	while (i < min)
		dest[i++] = src[start++];
	dest[i] = '\0';
	return (dest);
}
