/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdeage <fdeage@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 15:24:36 by fdeage            #+#    #+#             */
/*   Updated: 2015/04/25 13:33:38 by fdeage           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns a mallocked string so beware of potential mem leaks -> strtrim()
** returns a copy of the original since s1 is const...
** The condition after the first run "if (!s1[i] )ret(NULL)" has been removed
** so strdup() is called anyways
*/

char	*ft_strtrim(char const *s1)
{
	register size_t	i;
	char			*s2;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && ft_isspace(s1[i]))
		++i;
	s2 = ft_strdup(&s1[i]);
	i = ft_strlen(s2) - 1;
	while (s2[i] && ft_isspace(s2[i]))
		s2[i--] = '\0';
	return (s2);
}

char	*ft_strtrim_mod(char *s)
{
	register size_t	i;

	while (*s && ft_isspace(*s))
		++s;
	i = 0;
	while (s[i] && !ft_isspace(s[i]))
		++i;
	s[i] = '\0';
	return (s);
}
