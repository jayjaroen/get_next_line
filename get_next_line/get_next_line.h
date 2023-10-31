/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjaroens <jjaroens@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 21:30:52 by jjaroens          #+#    #+#             */
/*   Updated: 2023/10/31 22:56:19 by jjaroens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*Buffer_size is defined at compiling time*/
#ifdef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifdef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
// typedef struct s_struct
// {
//     char    *buffer;
//     struct s_struct    *next;
// }   t_list;

char	*get_next_line(int fd);
#endif
