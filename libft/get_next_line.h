/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiulian <agiulian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:15:25 by agiulian          #+#    #+#             */
/*   Updated: 2016/12/06 18:05:02 by agiulian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUF_SIZE 1024
# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

typedef	struct	s_fd
{
	int			fd;
	char		*stc;
}				t_fd;
int				get_next_line(const int fd, char **line);

#endif
