/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjoo <yjoo@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 13:39:50 by yjoo              #+#    #+#             */
/*   Updated: 2022/06/22 20:35:48 by yjoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*save_buffer(char *buffer)
{
	int		i;
	char	*tmp;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	tmp = (char *)malloc(sizeof(char) * (gnl_ft_strlen(buffer) - i + 1));
	if (!tmp)
		return (NULL);
	i++;
	gnl_ft_strlcpy(tmp, buffer + i, gnl_ft_strlen(buffer) - i + 1);
	free(buffer);
	return (tmp);
}

char	*get_line(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	gnl_ft_strlcpy(line, buffer, i + 2);
	return (line);
}

char	*read_buffer(int fd, char *buffer)
{
	int		read_len;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp)
		return (NULL);
	read_len = 1;
	while (read_len > 0 && !gnl_ft_strchr(buffer, '\n'))
	{
		read_len = read(fd, tmp, BUFFER_SIZE);
		if (read_len == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[read_len] = 0;
		buffer = gnl_ft_strjoin(buffer, tmp);
	}
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = read_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = get_line(buffer);
	buffer = save_buffer(buffer);
	return (line);
}
