/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:47:38 by jjaroens          #+#    #+#             */
/*   Updated: 2023/10/23 15:30:28 by jjaroens         ###   ########.fr       */
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

char *get_next_line(int fd)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
}
