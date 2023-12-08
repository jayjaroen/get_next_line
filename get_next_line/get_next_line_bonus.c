/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 20:07:37 by jjaroens          #+#    #+#             */
/*   Updated: 2023/12/08 20:27:09 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	{
		free(buffer);
		return (NULL);
	}
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
		line[i] = '\n';
		line[i + 1] = '\0';
	}
	else
		line = buffer;
	return (line);
}

char	*ft_join(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	if (str == NULL)
		return (NULL);
	free(s1);
	return (str);
}

char	*read_buffer(char *buffer, char *str, int fd)
{
	char	*tmp;
	int		byte_read;

	while (1)
	{
		byte_read = read(fd, str, BUFFER_SIZE);
		if (byte_read == 0 || byte_read == -1)
			break ;
		str[BUFFER_SIZE] = '\0';
		tmp = buffer;
		if (tmp == NULL)
		{
			tmp = malloc(sizeof(char) * 1);
			if (tmp == NULL)
				return (NULL);
			tmp[0] = '\0';
			buffer = ft_join(buffer, str);
			if (ft_strchr(buffer, '\n'))
				break ;
		}
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[OPEN_MAX];
	char		*line;
	char		*str;
	char		*ptr;
	//ptr to find the "\n" in buffer?

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	//check if buffer is empty
	ptr = ft_strchr(buffer[fd], '\n');
	if (ptr == NULL) // not good if is a null? / could be empty buffer?
	{
		//buffer = combined buffer + str
    str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (str == NULL)
      return (NULL);
	buffer[fd] = read_buffer(buffer[fd], str, fd);
	free(str);
	}
	line = ft_line(buffer[fd]);
	//read line later,if not emply
	//update buffer;
	buffer[fd] = update_buffer(buffer[fd]);
	return (line);
}
