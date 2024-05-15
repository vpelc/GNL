/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 22:00:02 by vpelc             #+#    #+#             */
/*   Updated: 2024/05/15 14:25:54 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
// typedef struct s_list
// {
// 	int		fd;
// 	char	*buffer;
// }	t_list;

char	*get_next_line(int fd);
char	*ft_fill_buff(int fd, char *buffer);
char	*ft_get_line(char *buffer);
char	*ft_fill_next_buff(char *buffer);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s);
size_t	ft_strlen(char *c);

#endif