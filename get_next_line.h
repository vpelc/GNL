/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 22:00:02 by vpelc             #+#    #+#             */
/*   Updated: 2024/05/17 21:55:05 by vpelc            ###   ########.fr       */
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

char	*get_next_line(int fd);
char	*ft_fill_buff(int fd, char *buffer);
char	*ft_get_line(char *buffer);
char	*ft_fill_next_buff(char *buffer);
char	*ft_strjoin(char *buffer, char *read_buffer);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *c);
void	ft_free(char **buffer);

#endif