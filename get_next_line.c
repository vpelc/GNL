/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:59:18 by vpelc             #+#    #+#             */
/*   Updated: 2024/05/15 17:19:05 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *buffer, char *read_buffer)
{
	char	*temp;

	temp = ft_strjoin(buffer, read_buffer);
	free(buffer);
	return (temp);
}

char	*ft_fill_buff(int fd, char *buffer)
{
	int		read_count;
	char	*read_buffer;

	if (!buffer)
		buffer = ft_strdup("");
	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buffer)
		return (NULL);
	read_count = 1;
	while (read_count > 0)
	{
		read_count = read(fd, read_buffer, BUFFER_SIZE);
		if (read_count == -1)
		{
			free(read_buffer);
			return (NULL);
		}
		read_buffer[read_count] = '\0';
		buffer = ft_free(buffer, read_buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(read_buffer);
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_fill_next_buff(char *buffer)
{
	char	*next_buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next_buffer = malloc((ft_strlen(buffer) - i + 1));
	next_buffer[ft_strlen(buffer) - i] = '\0';
	i++;
	while (buffer[i])
		next_buffer[j++] = buffer[i++];
	free(buffer);
	buffer = NULL;
	return (next_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_fill_buff(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_fill_next_buff(buffer);
	return (line);
}
