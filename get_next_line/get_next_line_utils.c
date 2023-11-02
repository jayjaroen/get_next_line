/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:38:50 by jjaroens          #+#    #+#             */
/*   Updated: 2023/11/02 23:00:30 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h> // why not linking to the header file

char *ft_strchr(const char *s, int c)
{
	unsigned char	i;

	i = (unsigned char)c;
	if (!s || c)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (*s == i)
		return ((char *)s);
	return (NULL);
}

size_t ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (*s)
	{
		s++;
		i++;
	}
	return (i);
}

char  *ft_strjoin(char *s1, char *s2)
{
	char	*new;
	char	*ptr;

	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	ptr = new;
	if (new == NULL)
		return (NULL);
	while (*s1)
		*(new++) = *(s1++);
	while (*s2)
		*(new++) = *(s2++);
	*new = '\0';
	return (ptr);
}
