/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpelc <vpelc@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:59:48 by vpelc             #+#    #+#             */
/*   Updated: 2024/05/15 15:39:48 by vpelc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen( char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

static	char	*ft_strj(char *s1, char *s2, char *join, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < (len - ft_strlen(s2)))
	{
		join[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (j < len)
	{
		join[j] = s2[i];
		j++;
		i++;
	}
	join[j] = '\0';
	return (join);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	len;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	join = malloc(sizeof(char) * (len + 1));
	if (join == 0)
		return (0);
	ft_strj(s1, s2, join, len);
	return (join);
}

char	*ft_strchr( char *s, int c)
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

char	*ft_strdup( char *s)
{
	char	*dup;
	size_t	len;
	size_t	i;

	if (!s)
		return (0);
	len = ft_strlen(s);
	dup = malloc(sizeof(char) * (len + 1));
	if (!dup)
		return (free(dup), NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
