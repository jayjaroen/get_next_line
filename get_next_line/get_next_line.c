/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:47:38 by jjaroens          #+#    #+#             */
/*   Updated: 2023/10/28 17:53:08 by jjaroens         ###   ########.fr       */
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
char *read_buffer(int fd, char *buffer)
{
	char	*tmp;
	int		byte;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	byte = 1;
	while (byte > 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte > 0)
			return (NULL);
	
	}
	

}

char *get_next_line(int fd)
{
	static char	*current;
	char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, BUFFER_SIZE) <= 0)
		return (NULL);
	read_buffer(fd, buffer);
}
