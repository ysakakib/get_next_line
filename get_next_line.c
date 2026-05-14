/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusakaki <yusakaki@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/09 00:03:09 by yusakaki          #+#    #+#             */
/*   Updated: 2026/05/14 20:46:11 by yusakaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_store(int fd, char *save)
{
	char	*read_buf;
	ssize_t	bytes_read;

	read_buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buf)
		return (NULL);
	bytes_read = 1;
	// 改行が見つかる、または読み込みが終わるまでループ
	while (!ft_strchr(save, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, read_buf, BUFFER_SIZE);
		if (bytes_read == -1) // readエラー時
		{
			free(read_buf);
			free(save); // 保存していたものも解放
			return (NULL);
		}
		read_buf[bytes_read] = '\0';
		// 以前作った「s1をfreeしてくれる」ft_strjoinを活用
		if (!save)
			save = ft_strdup("");
		save = ft_strjoin(save, read_buf);
	}
	free(read_buf);
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!save)
		save = ft_strdup("");
	// 1. 改行が見つかるまで読み込む
	save = read_and_store(fd, save);
	if (!save)
		return (NULL);
	// 2. 行を切り出す
	line = extract_line(save);
	// 3. 次回のために残りを保存する
	save = update_buffer(save);
	return (line);
}

// static char	*extract_line(char *buffer)
// {
// 	char	*line;
// 	size_t	len;
// 	size_t	i;

// 	if (!buffer || buffer[0] == '\0')
// 		return (NULL);
// 	len = 0;
// 	while (buffer[len] && buffer[len] != '\n')
// 		len++;
// 	if (buffer[len] == '\n')
// 		len++;
// 	line = (char *)malloc(len + 1);
// 	if (!line)
// 		return (NULL);
// 	i = 0;
// 	while (i < len)
// 	{
// 		line[i] = buffer[i];
// 		i++;
// 	}
// 	line[len] = '\0';
// 	return (line);
// }

// static char	*update_buffer(char *buffer)
// {
// 	char	*new_buffer;
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	while (buffer[i] && buffer[i] != '\n')
// 		i++;
// 	if (buffer[i] == '\0')
// 	{
// 		free(buffer);
// 		return (NULL);
// 	}
// 	i++;
// 	new_buffer = (char *)malloc(ft_strlen(buffer + i) + 1);
// 	if (!new_buffer)
// 		return (NULL);
// 	j = 0;
// 	while (buffer[i + j])
// 	{
// 		new_buffer[j] = buffer[i + j];
// 		j++;
// 	}
// 	new_buffer[j] = '\0';
// 	free(buffer);
// 	return (new_buffer);
// }

// static char	*read_and_append(int fd, char *buffer)
// {
// 	char	*read_buf;
// 	char	*temp;
// 	ssize_t	bytes_read;

// 	read_buf = (char *)malloc(BUFFER_SIZE + 1);
// 	if (!read_buf)
// 		return (NULL);
// 	bytes_read = read(fd, read_buf, BUFFER_SIZE);
// 	if (bytes_read <= 0)
// 	{
// 		free(read_buf);
// 		return (buffer);
// 	}
// 	read_buf[bytes_read] = '\0';
// 	if (buffer)
// 	{
// 		temp = ft_strjoin(buffer, read_buf);
// 		free(read_buf);
// 		free(buffer);
// 		return (temp);
// 	}
// 	else
// 	{
// 		temp = ft_strdup(read_buf);
// 		free(read_buf);
// 		return (temp);
// 	}
// }

// char	*get_next_line(int fd)
// {
// 	static char	*buffer;
// 	char		*line;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	while (!ft_strchr(buffer, '\n'))
// 	{
// 		buffer = read_and_append(fd, buffer);
// 		if (!buffer)
// 			return (NULL);
// 		if (ft_strlen(buffer) == 0)
// 		{
// 			free(buffer);
// 			buffer = NULL;
// 			return (NULL);
// 		}
// 	}
// 	line = extract_line(buffer);
// 	buffer = update_buffer(buffer);
// 	return (line);
// }
