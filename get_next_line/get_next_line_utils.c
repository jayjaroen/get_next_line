/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:38:50 by jjaroens          #+#    #+#             */
/*   Updated: 2023/10/31 23:09:04 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

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

// int	main(void)
// {
// 	char	*s1;
// 	char	*s2;
// 	char	*new;

// 	s1 = "hello";
// 	s2 = "World";
// 	new = ft_strjoin(s1, s2);
// 	while (*new)
// 	{
// 		printf("%c", *new);
// 		new++;
// 	}
// }
