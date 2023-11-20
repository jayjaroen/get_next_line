/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:47:38 by jjaroens          #+#    #+#             */
/*   Updated: 2023/11/20 22:42:48 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*update_buffer(char *buffer)
{
	char	*update;
	char	*ptr;
	char	*tmp;

	ptr = ft_strchr(buffer, '\n');
	if (ptr == NULL)
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

char *ft_line(char *buffer)
{
	char *line;
	int i;

	i = 0;
	if (!buffer[i])
	{
		// free(buffer);
		return (free(buffer),NULL);
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
		line = buffer; // check this again?
return (line);
}

char *ft_join(char *tmp, char *str)
{
	char	*ptr;

	ptr = ft_strjoin(tmp, str);
	free(tmp);
	return (ptr);
}

char *read_buffer(int fd, char *buffer, char *str)
{
	char	*tmp;
	int   	byte_read;

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
		if (buffer == NULL)
			return (NULL);
		if (ft_strchr(buffer, '\n') != NULL)
			break ;
	}
	return (buffer);
}

char *get_next_line(int fd)
{
	static char	*buffer;
	char		*str;
	char		*line;
	char		*ptr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ptr = ft_strchr(buffer, '\n');
	if (ptr == NULL)
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

/*----------the following still have problem on new line------------------*/
// char	*update_buffer(char *buffer)
// {
// 	char	*update;
// 	char	*ptr;
// 	char	*tmp;

// 	ptr = ft_strchr(buffer, '\n');
// 	// return NULL - don't keep the value
// 	if (ptr == NULL)
// 		return (NULL);
// 	ptr++;
// 	update = malloc(sizeof(char) * (ft_strlen(ptr) + 1));
// 	if (update == NULL)
// 		return (NULL);
// 	tmp = update;
// 	while (*ptr)
// 		*(update++) = *(ptr++);
// 	*(update) = '\0';
// 	free(buffer);
// 	return (tmp);
// }

// char *get_line(char *buffer)
// {
// 	char *line;
// 	int i;

// 	i = 0;
// 	while (buffer[i] && buffer[i] != '\n')
// 		i++;
// 	/// find '\n\ && not the end of file + malloc size
// 	if (buffer[i] == '\n')
// 	{
// 		line = malloc(sizeof(char) * (i + 2));
// 		if (line == NULL)
// 			return (NULL);
// 		i = 0;
// 		while (buffer[i] != '\n')
// 		{
// 			line[i] = buffer[i];
// 			i++;
// 		}
// 		line[i] = '\n';
// 		line[i + 1] = '\0';
// 	}
// 	/// end of file
// 	// else if (buffer[i] == '\0')
// 	else
// 	{
// 		line = buffer;
// 		// line = malloc(sizeof(char) * (i + 1));
// 		// if (line == NULL)
// 		// 	return (NULL);
// 		// i = 0;
// 		// while (buffer[i] != '\0')
// 		// {
// 		// line[i] = buffer[i];
// 		// 	i++;
// 		// }
// 		// line[i] = '\0';
// 	}
// return (line);
// }

// char *ft_join(char *tmp, char *str)
// {
// 	char	*ptr;

// 	ptr = ft_strjoin(tmp, str);
// 	// free(str);
// 	free(tmp);
// 	// str = NULL;
// 	// tmp = NULL;
// 	return (ptr);
// }

// char *read_buffer(int fd, char *buffer, char *str, char *tmp)
// {
// 	int	byte_read;

// 	while (1)
// 	{
// 		byte_read = read(fd, str, BUFFER_SIZE);
// 		if (byte_read == 0)
// 			break ;
// 		if (byte_read == -1)
// 		{
// 			// free(buffer);
// 			return (NULL);
// 		}
// 		str[byte_read] = '\0';
// 		tmp = buffer;
// 		if (tmp == NULL)
// 		{
// 			tmp = malloc(sizeof(char) * 1);
// 			if (tmp == NULL)
// 				return (NULL);
// 			tmp[0] = '\0';
// 		}
// 		buffer = ft_join(tmp, str);
// 		if (buffer == NULL)
// 			return (NULL);
// 		if (ft_strchr(buffer, '\n') != NULL)
// 			break ;
// 	}
// 	return (buffer);
// }

// char *get_next_line(int fd)
// {
// 	static char	*buffer;
// 	char		*str;
// 	char		*tmp;
// 	char		*line;
// 	char		*ptr;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	ptr = ft_strchr(buffer, '\n');
// 	if (ptr == NULL)
// 	{
// 		str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 		if (str == NULL)
// 			return (NULL);
// 		tmp = NULL;
// 		buffer = read_buffer(fd, buffer, str, tmp);
// 		free(str);
// 		if (buffer == NULL)
// 			return (NULL);
// 	}
// 	line = get_line(buffer);
// 	buffer = update_buffer(buffer); /// byte_read == 0
// 	return (line);
// }
/*-----------------------------------------------PREVIOUS--------------------------------------*/
// char	*update_buffer(char *buffer)
// {
// 	char	*line;
// 	char	*ptr;
// 	char	*tmp;

// 	if (buffer == NULL)
// 		return (NULL);
// 	ptr = ft_strchr(buffer, '\n');
// 	ptr++;
// 	line = malloc(sizeof(char) * (ft_strlen(ptr) + 1));
// 	if (line == NULL)
// 		return (NULL);
// 	tmp = line;
// 	while (*ptr)
// 		*(line++) = *(ptr++);
// 	*(line++) = '\0';
// 	free(buffer);
// 	return (tmp);
// }

// char	*get_line(char *buffer)
// {
// 	char	*line;
// 	size_t	i;

// 	i = 0;
// 	if (buffer == NULL)
// 		return (NULL);
// 	while (buffer[i] && buffer[i] != '\n')
// 		i++;
// 	line = malloc(sizeof(char) * (i + 2));
// 	if (line == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (buffer[i] && buffer[i] != '\n')
// 	{
// 		line[i] = buffer[i];
// 		i++;
// 	}
// 	if (buffer[i] == '\n')
// 	{
// 		line[i] = '\n';
// 		i++;
// 	}
// 	line[i] = '\0';
// 	return (line);
// }

// char	*ft_join(char *tmp, char *str)
// {
// 	char	*ptr;

// 	ptr = ft_strjoin(tmp, str);
// 	free(str);
// 	free(tmp);
// 	str = NULL;
// 	tmp = NULL;
// 	return (ptr);
// }

// // char	*read_buffer(int fd, char *buffer)
// // {
// // 	char	*tmp;
// // 	int		byte;

// // 	if (!buffer)
// //     {
// //         buffer = (char *)malloc(sizeof(char));
// //         buffer[0] = '\0';
// //     }
// // 		// buffer = (char *)(ft_calloc(1, 1));
// // 	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// // 	if (tmp == NULL)
// // 		return (NULL);
// // 	byte = 1;
// // 	while (byte > 0)
// // 	{
// // 		byte = read(fd, tmp, BUFFER_SIZE);
// // 		if (byte == -1)
// // 		{
// // 			free(tmp);
// // 			return (NULL);
// // 		}
// // 		tmp[byte] = 0;
// // 		buffer = ft_join(buffer, tmp);
// // 		if (ft_strchr(tmp, '\n') || byte == 0)
// // 			break ;
// // 	}
// // 	free(tmp);
// // 	return (buffer);
// // }
// char	*read_buffer(int fd, char *buffer, char *str, char *tmp)
// {
// 	int	byte_read;

// 	while (1)
// 	{
// 		byte_read = read(fd, str, BUFFER_SIZE);
// 		if (byte_read == -1)
// 		{
// 			free(str);
// 			return (NULL);
// 		}
// 		str[byte_read] = '\0';
// 		tmp = buffer;
// 		if (tmp == NULL)
// 		{
// 			tmp = malloc(sizeof(char) * 1);
// 			if (tmp == NULL)
// 			{
// 				free(str);
// 				return (NULL);
// 			}
// 			tmp[0] = '\0';
// 		}
// 		buffer = ft_join(tmp, str);
// 		if (ft_strchr(buffer, '\n') || byte_read == 0)
// 			break ;
// 	}
// 	return (buffer);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*buffer;
// 	char		*line;
// 	char		*str;
// 	char		*tmp;

// 	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1 || fd == STDIN_FILENO
// 	|| fd == STDERR_FILENO)
// 		return (NULL);
// 	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
// 	if (str == NULL)
// 		return (NULL);
// 	tmp = NULL;
// 	buffer = read_buffer(fd, buffer, str, tmp);
// 	if (buffer == NULL)
// 	{
// 		free(str);
// 		return (NULL);
// 	}
// 	line = get_line(buffer);
// 	buffer = update_buffer(buffer);
// 	return (line);
// }
