/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:47:38 by jjaroens          #+#    #+#             */
/*   Updated: 2023/11/16 22:37:09 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <ctype.h>

char	*update_buffer(char *buffer)
{
	char	*line;
	char	*ptr;
	char	*tmp;

	if (!buffer)
		return (NULL);
	ptr = ft_strchr(buffer, '\n');
	ptr++;
	line = (char *)malloc((ft_strlen(ptr) + 1) * sizeof(char));
	if (line == NULL)
	{
		free(buffer);
		return (NULL);
	}
	tmp = line;
	while (*ptr)
		*(line++) = *(ptr++);
	free(buffer);
	return (tmp);
}

char	*get_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = '\n';
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
	int		byte;

	if (!buffer)
    {
        buffer = (char *)malloc((sizeof(char)) * 1);
        *buffer = 0;
    }
		// buffer = (char *)(ft_calloc(1, 1));
	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (tmp == NULL)
		return (NULL);
	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, tmp, BUFFER_SIZE);
		if (byte == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[byte] = 0;
		buffer = ft_join(buffer, tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_buffer(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = get_line(buffer);
	buffer = update_buffer(buffer);
	return (line);
}
