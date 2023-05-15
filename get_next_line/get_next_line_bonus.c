/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itrueba- <itrueba-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 10:02:08 by itrueba-          #+#    #+#             */
/*   Updated: 2022/12/28 13:45:05 by itrueba-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_leftovers(char *leftovers)
{
	int		len;
	char	*new_leftovers;

	len = 0;
	while (leftovers[len] && leftovers[len] != '\n')
		len++;
	if (!leftovers[len])
	{
		free(leftovers);
		return (NULL);
	}
	new_leftovers = malloc(ft_strlen(leftovers) - len);
	if (!new_leftovers)
		return (NULL);
	len++;
	ft_strlcpy(new_leftovers, &leftovers[len], ft_strlen(leftovers) - len + 1);
	free(leftovers);
	return (new_leftovers);
}

char	*ft_line(char *leftovers)
{
	char	*new_line;
	int		len;

	if (!leftovers[0])
		return (NULL);
	len = 1;
	while (leftovers[len] && leftovers[len - 1] != '\n')
		len++;
	new_line = malloc(len + 1);
	if (!new_line)
		return (NULL);
	ft_strlcpy(new_line, leftovers, len + 1);
	return (new_line);
}

char	*ft_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}

char	*ft_read(int fd, char *leftovers)
{
	char	*buffer;
	int		number_bytes;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	number_bytes = 1;
	while (!ft_strchr(leftovers, '\n') && number_bytes != 0)
	{
		number_bytes = read(fd, buffer, BUFFER_SIZE);
		if (number_bytes == -1)
		{
			free(leftovers);
			free(buffer);
			return (NULL);
		}
		buffer[number_bytes] = '\0';
		leftovers = ft_strjoin(leftovers, buffer);
	}
	free(buffer);
	return (leftovers);
}

char	*get_next_line(int fd)
{
	static char	*leftovers[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	leftovers[fd] = ft_read(fd, leftovers[fd]);
	if (!leftovers[fd])
		return (NULL);
	line = ft_line(leftovers[fd]);
	leftovers[fd] = ft_leftovers(leftovers[fd]);
	return (line);
}
