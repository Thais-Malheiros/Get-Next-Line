/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:28:44 by tmalheir          #+#    #+#             */
/*   Updated: 2023/12/01 11:04:40 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_line(int fd, char *buffer, char *st_buffer);
static char	*get_line(char *st_buffer, char *line);
static char	*copy_line(char *st_buffer, char *line);
static char	*get_remain(char *st_buffer);

char	*get_next_line(int fd)
{
	static char	*st_buffer;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (!st_buffer)
		st_buffer = ft_strdup("");
	st_buffer = read_line(fd, buffer, st_buffer);
	line = NULL;
	line = get_line(st_buffer, line);
	st_buffer = get_remain(st_buffer);
	if (!st_buffer && ft_strlen(line) == 0)
	{
		free (line);
		return (NULL);
	}
	return (line);
}

static char	*read_line(int fd, char *buffer, char *st_buffer)
{
	int		bytes_read;
	char	*temp_stash;

	bytes_read = 0;
	while (bytes_read <= (BUFFER_SIZE))
		buffer[bytes_read++] = '\0';
	while (!ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		else if (bytes_read == -1)
		{
			free (st_buffer);
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		temp_stash = ft_strjoin(st_buffer, buffer);
		free (st_buffer);
		st_buffer = ft_strdup(temp_stash);
		free (temp_stash);
	}
	free (buffer);
	return (st_buffer);
}

static char	*get_line(char *st_buffer, char *line)
{
	int		idx;

	idx = 0;
	while (st_buffer && st_buffer[idx] && st_buffer[idx] != '\n')
		idx++;
	if (st_buffer && st_buffer[idx] == '\n')
	{
		line = malloc(sizeof(char) * (idx + 2));
		if (!line)
		{
			free (st_buffer);
			return (NULL);
		}
		line = copy_line(st_buffer, line);
		return (line);
	}
	else
		return (st_buffer);
}

static char	*copy_line(char *st_buffer, char *line)
{
	int	idx;

	idx = 0;
	while (st_buffer[idx] && st_buffer[idx] != '\n')
	{
		line[idx] = st_buffer[idx];
		idx++;
	}
	if (st_buffer[idx] == '\n')
		line[idx++] = '\n';
	line[idx] = '\0';
	return (line);
}

static char	*get_remain(char *st_buffer)
{
	char	*remain;
	int		idx_st;
	int		idx_rm;

	idx_st = 0;
	while (st_buffer && st_buffer[idx_st] && st_buffer[idx_st] != '\n')
		idx_st++;
	if (st_buffer && st_buffer[idx_st] == '\n')
	{
		remain = malloc(sizeof(char) * (ft_strlen(st_buffer) - idx_st));
		if (!remain)
		{
			free (st_buffer);
			return (NULL);
		}
		idx_st++;
		idx_rm = 0;
		while (st_buffer[idx_st])
			remain[idx_rm++] = st_buffer[idx_st++];
		remain[idx_rm] = '\0';
		free(st_buffer);
		return (remain);
	}
	else
		return (NULL);
}
