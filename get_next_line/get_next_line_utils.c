/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:38:50 by jjaroens          #+#    #+#             */
/*   Updated: 2023/12/05 21:58:24 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// void	ft_bzero(void *s, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*ptr;

// 	i = 0;
// 	ptr = (unsigned char *)s;
// 	while (i < n)
// 	{
// 		*ptr = 0;
// 		ptr++;
// 		i++;
// 	}
// }

// void	*ft_calloc(size_t count, size_t size)
// {
// 	void	*str;

// 	str = (void *)malloc(count * size);
// 	if (str == NULL)
// 		return (NULL);
// 	ft_bzero(str, (count * size));
// 	return (str);
// }

char	*ft_strchr(const char *s, int c)
{
	unsigned char	i;

	i = (unsigned char)c;
	if (!s)
		return (NULL);
	while (*s != '\0' && *s != i)
		s++;
	if (*s == i)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlen(const char *s)
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

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1 || !s2 || !new)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = 0;
	return (new);
}
