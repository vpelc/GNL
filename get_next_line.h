/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 22:00:02 by vpelc             #+#    #+#             */
/*   Updated: 2024/05/09 17:40:54 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# ifndef BUFFER_SIZE 
# define BUFFER_SIZE 1024
// typedef struct s_list
// {
// 	int		fd;
// 	char	*buffer;
// }	t_list;

char	*get_next_line(int fd);
int		ft_linelen(int fd, char *str);

#endif