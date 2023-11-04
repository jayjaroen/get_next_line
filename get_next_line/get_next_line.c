/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:47:38 by jjaroens          #+#    #+#             */
/*   Updated: 2023/11/04 17:52:33 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*update_buffer(char *buffer)
{
	size_t	i;
	char	*line;
	char	*ptr;
	char	*tmp;

	if (buffer == NULL)
		return (NULL);
	ptr = ft_strchr(buffer, '\n');
	line = (char *)malloc(ft_strlen(ptr + 1) * sizeof(char));
	if (line == NULL)
		return (NULL);
	tmp = line;
	while (*ptr)
		*(line++) = *(ptr++);
	*line = '\0';
	free(buffer);
	return(tmp);
}

char	*get_line(char *buffer)
{
	char	*line;
	size_t	i;

	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_join(char *buffer, char *tmp)
{
	char	*ptr;
	
	ptr = ft_strjoin(buffer, tmp);
	free(buffer);
	return (ptr);
}

char	*read_buffer(int fd, char *buffer)
{
	char	*tmp;
	size_t	byte;

	if (buffer == NULL)
		buffer = (char *)(ft_calloc(1, 1));
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (tmp == NULL)
		return (NULL);
	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, tmp, BUFFER_SIZE);
		if (byte <= 0)
		{
			free(tmp);
			return (NULL);
		}
		tmp[byte] = '\0';
		buffer = ft_join(buffer, tmp); 
		if (ft_strchr(tmp, '\n'))
			break ;
		free(tmp);
	}	
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_buffer(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = get_line(buffer);
	buffer = update_buffer(buffer);
	return (line);
}