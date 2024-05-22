/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:59:18 by vpelc             #+#    #+#             */
/*   Updated: 2024/05/22 17:10:05 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_fill_buff(int fd, char *buffer)
{
	int		read_count;
	char	*read_buffer;

	while (buffer && !(ft_strchr(buffer)))
	{
		read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!read_buffer)
			return (ft_free(&buffer), NULL);
		read_count = read(fd, read_buffer, BUFFER_SIZE);
		if (read_count < 0)
			return (ft_free(&read_buffer), ft_free(&buffer), NULL);
		if (read_count == 0)
			break ;
		read_buffer[read_count] = '\0';
		buffer = ft_strjoin(buffer, read_buffer);
	}
	if (read_count == 0)
		ft_free(&read_buffer);
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
	if (buffer[i] == '\n')
		i++;
	line = malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
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
	if (!buffer[i])
		return (ft_free(&buffer), NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		j++;
	next_buffer = malloc((ft_strlen(buffer) - i + j));
	if (!next_buffer)
		return (ft_free(&buffer), NULL);
	if (buffer[i] == '\n')
	{
		i++;
		j--;
	}
	while (buffer[i])
		next_buffer[j++] = buffer[i++];
	next_buffer[j] = '\0';
	ft_free(&buffer);
	return (next_buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0
		|| BUFFER_SIZE >= 2147483647 || read(fd, 0, 0) < 0)
		return (ft_free(&buffer), NULL);
	if (!buffer)
	{
		buffer = malloc(sizeof(char) * 1);
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	buffer = ft_fill_buff(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_fill_next_buff(buffer);
	if (!(ft_strchr(line)))
		ft_free(&buffer);
	return (line);
}
