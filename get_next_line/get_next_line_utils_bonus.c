/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:34:49 by jjaroens          #+#    #+#             */
/*   Updated: 2023/12/08 20:35:54 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*str;

// 	str = malloc(sizeof(char) * (count + size));
// 	if (str == NULL)
// 		return (NULL);

// }

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int		i;
	unsigned char	j;

	if (str == NULL)
		return (NULL);
	i = 0;
	j = (unsigned char)c;
	while (str[i] != j)
	{
		if (str[i] == j)
			return ((char *)(str));
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!*s1 || !*s2)
		return (NULL);
	i = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (i + 1));
	i = 0;
	while (*s1)
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (*s2)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	return (str);
}
