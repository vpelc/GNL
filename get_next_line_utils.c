/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:59:48 by vpelc             #+#    #+#             */
/*   Updated: 2024/05/18 13:16:51 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *c)
{
	size_t	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *buffer, char *read_buffer)
{
	char	*join;
	size_t	i;
	size_t	j;

	join = malloc((ft_strlen(buffer) + ft_strlen(read_buffer) + 1));
	if (!join)
		return (NULL);
	i = 0;
	while (buffer[i])
	{
		join[i] = buffer[i];
		i++;
	}
	j = 0;
	while (read_buffer[j])
	{
		join[i + j] = read_buffer[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;
	size_t	n;
	char	*str;

	i = 0;
	str = (char *)s;
	n = ft_strlen(str);
	while (i <= n && str[i] != (unsigned char)c)
		i++;
	if (i > n)
		return (0);
	return (str + i);
}

void	ft_free(char **buffer)
{
	free(*buffer);
	*buffer = NULL;
}
