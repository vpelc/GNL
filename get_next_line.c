/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:59:18 by vpelc             #+#    #+#             */
/*   Updated: 2024/05/09 18:25:09 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill_buff(int fd, char *buffer)
{
	int		read_count;
	char	*read_buffer;
	char	*temp;

	if (!buffer)
		ft_strdup("");
	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buffer)
		return (0);
	read_count = 1;
	while (read_count > 0)
	{
		read_count = read(fd, read_buffer, BUFFER_SIZE);
		if (read_count == -1)
		{
			free(read_buffer);
			return (0);
		}
		read_buffer[read_count] = 0; 

		temp = ft_strjoin(buffer, read_buffer);
		free(read_buffer);
		buffer = temp;
		ft_strchr(buffer, '\n');
	}
	
}

char	*get_next_line(int fd)
{
	int			i;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_fill_buff(fd, buffer);
}
