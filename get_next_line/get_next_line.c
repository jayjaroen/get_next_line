/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:47:38 by jjaroens          #+#    #+#             */
/*   Updated: 2023/11/02 23:00:19 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
/*
1. Read from the file (not over the give buffer size)
2. Malloc the given buffer size & store
3. Read from the buffer until finding '\n' && save the reminder (get the line?)
4. Read and store from the file
Read the line to the output
Functions that need to be created
*/
char *update_buffer(char *buffer)
{
	//free buffer in the line function
	size_t	i;

	if (buffer == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		free(buffer[i]);
		i++;
	}
	return (buffer);
}

char *get_line(char *buffer)
{
	char	*line;
	size_t	i;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		line[i++] = buffer[i++];
	line[i] = '\0';
	return (line);
}

char *read_buffer(int fd, char *buffer)
{
	char	*tmp;
	int		byte;

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (tmp == NULL)
		return (NULL);
	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, tmp, BUFFER_SIZE);
		if (byte <= 0) // does not read anything?// while setting to -1
			return (NULL);
    	tmp[byte] = '\0'; // ensure that it's null terminated oor 0??
		// joining buffer ///
		buffer = ft_strjoin(buffer, tmp);
		free(tmp);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (buffer);
}

char *get_next_line(int fd)
{
	static char	*buffer;
	char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, BUFFER_SIZE) <= 0)
		return (NULL);
	buffer = read_buffer(fd, buffer); // update the buffer
	if (buffer == NULL)
		return (NULL);
	line = get_line(buffer);//get line from the buffer
}
