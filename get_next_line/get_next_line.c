/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:47:38 by jjaroens          #+#    #+#             */
/*   Updated: 2023/12/08 22:49:32 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//check on update_buffer --> ptr null --> print line (already in the line function)
// for the update buffer --> check line 24 && 25 (if the buffer has no '\n', it should already print out in the line?)
// check line 59
char	*update_buffer(char *buffer)
{
	char	*update;
	char	*ptr;
	char	*tmp;

  	ptr = ft_strchr(buffer, '\n');
	if (ptr == NULL) // if there is no "/n" -> also print out in line?
		return (NULL);
	ptr++;
	update = malloc(sizeof(char) * (ft_strlen(ptr) + 1));
	if (update == NULL)
		return (NULL);
	tmp = update;
	while (*ptr)
		*(update++) = *(ptr++);
	*(update) = '\0';
	free(buffer);
	return (tmp);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (free(buffer), NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		line = malloc(sizeof(char) * (i + 2));
		if (line == NULL)
			return (NULL);
		i = 0;
		while (buffer[i] != '\n')
		{
			line[i] = buffer[i];
			i++;
		}
		line[i] = '\n'; //what if it is not the end of the file?
		line[i + 1] = '\0';
	}
	else
		line = buffer;
	return (line);
}

char	*ft_join(char *tmp, char *str)
{
	char	*ptr;

	ptr = ft_strjoin(tmp, str);
	free(tmp);
	return (ptr);
}

char	*read_buffer(int fd, char *buffer, char *str)
{
	char	*tmp;
	int		byte_read;

	while (1)
	{
		byte_read = read(fd, str, BUFFER_SIZE);
		if (byte_read == 0 || byte_read == -1)
			break ;
		str[byte_read] = '\0';
		tmp = buffer;
		if (tmp == NULL)
		{
			tmp = malloc(sizeof(char) * 1);
			if (tmp == NULL)
				return (NULL);
			tmp[0] = '\0';
		}
		buffer = ft_join(tmp, str);
		if (ft_strchr(buffer, '\n') != NULL)
			break ;
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*str;
	char		*line;
	// char		*ptr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	// ptr = ft_strchr(buffer, '\n');
	if (ft_strchr(buffer, '\n') == NULL)
	{
		str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (str == NULL)
			return (NULL);
		buffer = read_buffer(fd, buffer, str);
		free(str);
		if (buffer == NULL)
			return (NULL);
	}
  line = ft_line(buffer);
	buffer = update_buffer(buffer);
	return (line);
}
