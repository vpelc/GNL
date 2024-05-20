/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 22:00:02 by vpelc             #+#    #+#             */
/*   Updated: 2024/05/20 23:04:16 by vpelc            ###   ########.fr       */
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
int		ft_strchr(char *s);
size_t	ft_strlen(char *c);
void	ft_free(char **buffer);
char	*ft_join(char *buffer, char *read_buffer);

#endif